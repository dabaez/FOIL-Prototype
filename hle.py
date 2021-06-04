# -*- coding: utf-8 -*-
from sklearn.tree import DecisionTreeClassifier
import json
import numbers
import pyparsing as pp
from pyparsing import pyparsing_common as ppc
import functools
import subprocess

print('Loaded modules...')

def argmax(narr): # avois loading numpy only for this method
    arr = narr[0]
    imx = 0
    mx = -1e9
    for i, v in enumerate(arr):
        if v >= mx:
            mx = v
            imx = i
    return imx

def traverse(tree, root, ans, feature_names, class_names):
  left = tree.children_left[root]
  right = tree.children_right[root]

  leaf = (left == -1)

  ans[root] = {
      "id": root,
      "type": "leaf" if leaf else "internal",
  }

  if leaf:
    ans[root].update({
      "class": str(class_names[argmax(tree.value[root])]),
    })
  else:
    ans[root].update({
      "feature_name": str(feature_names[tree.feature[root]]),
      "feature_index": int(tree.feature[root]),
      "threshold": float(tree.threshold[root]),
      "id_left": int(left),
      "id_right": int(right)
    })
    traverse(tree, int(left), ans, feature_names, class_names)
    traverse(tree, int(right), ans, feature_names, class_names)


def tree_to_dict(feature_names, feature_types, class_names, dt):
  ans = {
      "feature_names": list(map(str, feature_names)),
      "feature_types": list(map(str, feature_types)),
      "class_names": list(map(str, class_names)),
      "positive": str(class_names[0]),
      "nodes": {}
      }
  traverse(dt.tree_, 0, ans["nodes"], feature_names, class_names)
  return ans

def print_json_dt(dt, feature_names, feature_types, class_names):
  print(json.dumps(tree_to_dict(feature_names, feature_types, class_names, dt), indent=2))

real = ppc.real
integer = ppc.integer
varname = ppc.identifier

class Variable:
  def __init__(self, varname):
    self.varname = varname

  def __repr__(self):
    return self.varname


class Classification:
  def __init__(self, cl, var):
    self.cl = cl
    self.var = var

  def __repr__(self):
    return self.cl + '(' + self.var + ')'

class Full:
  def __init__(self, var):
    self.var = var

  def __repr__(self):
    return f"(Full {str(self.var)})"

class Feature:
  def __init__(self, var, ft):
    self.var = var
    self.ft = ft

  def __repr__(self):
    return self.var + '.' + self.ft

class Not:
  def __init__(self, child):
    self.child = child

  def __repr__(self):
    return f"(Not {str(self.child)})"

class And:
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def __repr__(self):
    return f"(And {str(self.left)} {str(self.right)})"

class Or:
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def __repr__(self):
    return f"(Or {str(self.left)} {str(self.right)})"

class Implies:
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def __repr__(self):
    return f"(Implies {str(self.left)} {str(self.right)})"

class Comparison:
  def __init__(self, sym, left, right):
    self.sym = sym
    self.left = left
    self.right = right

  def __repr__(self):
    return f"({str(self.sym)} {str(self.left)} {str(self.right)})"

class Exists:
  def __init__(self, var, rest):
    self.var = var
    self.rest = rest

  def __repr__(self):
    return f"(Exists {str(self.var)} {str(self.rest)})"

class ForAll:
  def __init__(self, var, rest):
    self.var = var
    self.rest = rest

  def __repr__(self):
    return f"(ForAll {str(self.var)} {str(self.rest)})"

classification =  pp.Group(varname + pp.Suppress('(') + varname +  pp.Suppress(')'))
classification.setParseAction(lambda x: Classification(*x[0]))
feature = pp.Group(varname + pp.Suppress('.') + varname)
feature.setParseAction(lambda x: Feature(*x[0]))

boolean = pp.oneOf('true false')

def reducer(x, C):
  odd_list = x[0][::2] # [a, +, b, +, c] -> [a, c]
  return functools.reduce(C, odd_list)

full = 'full' + pp.Suppress('(') + varname + pp.Suppress(')')
full.setParseAction(lambda x: Full(x[1]))

qfree = pp.infixNotation( full | classification | feature | real | integer | boolean | varname,
    [
      (pp.oneOf('<= > = !='), 2, pp.opAssoc.LEFT, lambda x: Comparison(x[0][1], x[0][0], x[0][2])),
      ('not', 1, pp.opAssoc.RIGHT, lambda x: Not(x[0][1])),
      ('and', 2, pp.opAssoc.LEFT, lambda x: reducer(x, And)),
      ('or', 2, pp.opAssoc.LEFT, lambda x: reducer(x, Or)),
     ( 'implies', 2, pp.opAssoc.LEFT, lambda x: reducer(x, Implies))
    ])

sentence = pp.Forward()

exists = 'exists' + varname + pp.Suppress(',') + sentence
exists.setParseAction(lambda x: Exists(x[1], x[2]))

forall = 'for all' + varname + pp.Suppress(',') + sentence
forall.setParseAction(lambda x: ForAll(x[1], x[2]))

forevery = 'for every' + varname + pp.Suppress(',') + sentence
forevery.setParseAction(lambda x: ForAll(x[1], x[2]))

sentence << (exists | forall | forevery | qfree)


def get_feature_map(json_dt):
  fmap = { }
  for i, name in enumerate(json_dt['feature_names']):
    fmap[name] = { 'type': json_dt['feature_types'][i], 'index': i, 'intervals': set()}

  for key in json_dt['nodes']:
    node = json_dt['nodes'][key]
    if node['type'] == 'leaf': continue
    if fmap[node['feature_name']]['type'] == 'numeric':
        fmap[node['feature_name']]['intervals'] |= set([node['threshold']])

  for ft in fmap:
    fmap[ft]['intervals'] = list(fmap[ft]['intervals'])
  return fmap

def join_intervals(map1, map2):
  common = {**map1, **map2}
  for key in common.keys():
    s = set()
    if key in map1:
      s |= set(map1[key]['intervals'])
    if key in map2:
      s |= set(map2[key]['intervals'])
    common[key]['intervals'] = list(s)
  return common

def query_intervals(parse_node, feature_map):
  if isinstance(parse_node, Exists):
    return query_intervals(parse_node.rest, feature_map)
  if isinstance(parse_node, ForAll):
    return query_intervals(parse_node.rest, feature_map)
  if isinstance(parse_node, And) or isinstance(parse_node, Or) or isinstance(parse_node, Implies):
    return join_intervals(query_intervals(parse_node.left, feature_map),
                          query_intervals(parse_node.right, feature_map))
  if isinstance(parse_node, Not):
    return query_intervals(parse_node.child, feature_map)
  if isinstance(parse_node, Comparison):
    l = parse_node.left
    r = parse_node.right
    if(isinstance(l, numbers.Number)):
      l,r = r,l
    # we assume r is the numeric one.
    return join_intervals({ l.ft : {'intervals': [r]}}, feature_map)
  return feature_map

def build_ranges(feature_map):
  i = 0
  ordered_fts = sorted(feature_map.keys(), key=lambda x: feature_map[x]['index'])
  for ft in ordered_fts:
    if feature_map[ft]['type'] == 'numeric':
        feature_map[ft]['range'] = list(range(i, i+len(feature_map[ft]['intervals'])))
        i += len(feature_map[ft]['intervals'])
    else:
        feature_map[ft]['range'] = [i]
        i += 1
  feature_map['dimension'] = sum(map(lambda x: len(feature_map[x]['range']), feature_map))

def comparison_to_low(comparison_node, feature_map):
  assert isinstance(comparison_node.left, Feature)
  var = comparison_node.left.var
  ft = comparison_node.left.ft
  assert ft in feature_map

  dimension = feature_map['dimension']

  constant = ['?' for _ in range(dimension)]

  ## IMPORTANT: Assuming constants only on the right!

  # boolean case
  if feature_map[ft]['type'] == 'boolean':
    assert comparison_node.sym == '='
    if len(feature_map[ft]['range']) != 1:
        print(ft, feature_map[ft]['range'])

    assert len(feature_map[ft]['range']) == 1

    idx_constant = feature_map[ft]['range'][0]
    constant[idx_constant] = ['false', 'true'].index(comparison_node.right)
    return f"{arr_to_str(constant)} <= {var}"
# Elif: numeric threshold case.
  '''
  Representation: the leftmost 1 in the range indicates the interval to which
the instance belongs. if there are no 1s, then it belongs to the last interval.

Interval = [ .... , T, ..., ]. Assume T has index i (from 0).
x <= T -> the leftmost 1 appearst before-including position i.
      Equivalently, it is not true that all positions are 0 up to i (included)
x > T -> the leftmost 1 appearst after-excluding position i.
      Equivalently, all positions are 0 up to i (included).

  '''
  if feature_map[ft]['type'] == 'numeric':
    rvalue = float(comparison_node.right)
    assert rvalue in feature_map[ft]['intervals']

    cnst_index = sorted(feature_map[ft]['intervals']).index(rvalue)
    start_range = feature_map[ft]['range'][0]
    for i in range(start_range, start_range + cnst_index + 1):
      constant[i] = 0

    if comparison_node.sym == '<=':
      return f"~ ({arr_to_str(constant)} <= {var})"
    elif comparison_node.sym == '>':
      return f"{arr_to_str(constant)} <= {var}"
  else:
    raise Exception("This shouldn't happen! exhaustiveness assumption has been broken")



def arr_to_str(arr):
  ## from https://stackoverflow.com/a/5445983/11780694
  return '[%s]' % ', '.join(map(str, arr))



def build_low_level(parse_node, feature_map):
  rec = lambda node : build_low_level(node, feature_map)

  if isinstance(parse_node, Variable):
    return 'variable'
  if isinstance(parse_node, Exists):
    return 'exists ' + parse_node.var + ', ' + rec(parse_node.rest)
  if isinstance(parse_node, ForAll):
    return 'ForAll ' + parse_node.var +  f', (~(FULL({parse_node.var}))) V ({rec(parse_node.rest)})'
  if isinstance(parse_node, And):
    return f"({rec(parse_node.left)}) ^ ({rec(parse_node.right)})"
  if isinstance(parse_node, Or):
    return f"({rec(parse_node.left)}) V ({rec(parse_node.right)})"
  if isinstance(parse_node, Implies):
    return f"(~({rec(parse_node.left)})) V ({rec(parse_node.right)})"
  if isinstance(parse_node, Not):
    return f"~({rec(parse_node.child)})"
  if isinstance(parse_node, Full):
    return f"FULL({parse_node.var})"
  if isinstance(parse_node, Classification):
    return f"P({parse_node.var})"
  if isinstance(parse_node, Comparison):
    return comparison_to_low(parse_node, feature_map)
  print(parse_node, type(parse_node))
  raise Exception("this shouldn't happen!, parse_node doesn't belong to any recognized class")


class RecNode:
  def __init__(self, dict_node):
    self.type = dict_node['type']
    if self.type == 'internal':
      self.feature_index = int(dict_node['feature_index'])
      self.feature_name = dict_node['feature_name']
      self.threshold = float(dict_node['threshold'])
      self.id_left = int(dict_node['id_left'])
      self.id_right = int(dict_node['id_right'])
      self.left = None
      self.right = None
    elif self.type == 'leaf':
      self.clss = dict_node['class']

  def to_dict(self):
    if self.type == 'leaf':
      return f'leaf {self.clss}'
    else:
      return {'feature_index': self.feature_index,
              'left': self.left.to_dict(),
              'right': self.right.to_dict()}

  @classmethod
  def from_feature(cls, feature_index):
    dict_node = { 'type': 'internal',
                 'feature_index': feature_index,
                 'feature_name': feature_index,
                 'threshold': 0.5,
                 'id_left': -1,
                 'id_right': -1}
    return cls(dict_node)

def traverse_rec(rec_tree, nodes, node_id_map=None):
  if node_id_map is None:
    node_id_map = {}
  if rec_tree not in node_id_map:
    node_id_map[rec_tree] = len(node_id_map)
    id = node_id_map[rec_tree]
    nodes[id] = {
        "id": id,
        "type": rec_tree.type,
    }
    if rec_tree.type == 'internal':
      nodes[id]["feature_name"] = rec_tree.feature_index
      nodes[id]["feature_index"] = rec_tree.feature_index
      nodes[id]["threshold"] = 0.5
      traverse_rec(rec_tree.left, nodes, node_id_map)
      traverse_rec(rec_tree.right, nodes, node_id_map)
      nodes[id]["id_left"] = node_id_map[rec_tree.left]
      nodes[id]["id_right"] = node_id_map[rec_tree.right]
    if rec_tree.type == 'leaf':
      nodes[id]['class'] = rec_tree.clss
  else: # already visited
    return


def final_json_from_rec(rec_tree, dim, class_names):
  js = {
      "feature_names": [str(i) for i in range(dim)],
      "feature_types": ['boolean' for i in range(dim)],
      "class_names": list(map(str, class_names)),
      "positive": str(class_names[0]),
      "nodes": {}
  }
  traverse_rec(rec_tree, js["nodes"])
  return js

def to_recursive_tree(dt_dict):
  nodes = dt_dict['nodes']
  rnodes = { int(node) : RecNode(nodes[node]) for node in nodes}
  for rnode in rnodes.values():
    if rnode.type =='internal':
      # the inversion left<--> right is because Sklearn uses left for 1 and right for 0 :()
      rnode.right = rnodes[rnode.id_left]
      rnode.left = rnodes[rnode.id_right]
  return rnodes[0]

def binarize_rec_tree(rec_tree, feature_map, ft_progress_map = {}):
  if rec_tree.type == 'leaf':
    return rec_tree
  else:
    fname = rec_tree.feature_name
    feature_spec = feature_map[fname]

    rnge = feature_spec['range']
    if feature_spec['type'] == 'numeric':
        t = rec_tree.threshold

        id = sorted(feature_spec["intervals"]).index(t)

        frm = 0
        if fname in ft_progress_map:
          frm = ft_progress_map[fname]
        real_rnge = rnge[frm:id+1]
        ## we now need to check that:
        ## there is at least a 1 in features from [rnge[0], limit]
        ## Nodes pass the whole check if they have a 1, and go to the next with a 0.
        ## the last one with a 0 fails the whole check.
        new_nodes = [RecNode.from_feature(ft_index) for ft_index in real_rnge]
        left = binarize_rec_tree(rec_tree.left, feature_map, {**ft_progress_map, fname: id+1})
        right = binarize_rec_tree(rec_tree.right, feature_map, ft_progress_map)
        for i in range(len(new_nodes)):
          new_nodes[i].right = right
          if i < len(new_nodes) - 1:
            new_nodes[i].left = new_nodes[i+1]
          else:
            new_nodes[i].left = left
        return new_nodes[0]
    elif feature_spec['type'] == 'boolean':
        left = binarize_rec_tree(rec_tree.left, feature_map, ft_progress_map)
        right = binarize_rec_tree(rec_tree.right, feature_map, ft_progress_map)
        new_node = RecNode.from_feature(rnge[0])
        new_node.left = left
        new_node.right = right
        return new_node


def binarize_tree(dt_dict, feature_map):
  rec_tree = to_recursive_tree(dt_dict)
  return binarize_rec_tree(rec_tree, feature_map)

def final_feature_map(dtree, feature_names, feature_types, target_names, high_query):
  dt_dict = tree_to_dict(feature_names, feature_types, target_names, dtree)
  fmap = get_feature_map(dt_dict)
  parse_results = sentence.parseString(high_query, parseAll=True)
  feature_map = query_intervals(parse_results[0], fmap)
  build_ranges(feature_map)
  return feature_map

def to_low(dtree, feature_names, feature_types, target_names, high_query):
  feature_map = final_feature_map(dtree, feature_names, feature_types, target_names, high_query)
  parse_results = sentence.parseString(high_query, parseAll=True)
  return build_low_level(parse_results[0], feature_map)

def to_binary_model(dtree, feature_names, feature_types, target_names, high_query):
  feature_map = final_feature_map(dtree, feature_names, feature_types, target_names, high_query)
  dt_dict = tree_to_dict(feature_names, feature_types, target_names, dtree)
  return binarize_tree(dt_dict, feature_map), int(feature_map['dimension'])

def high_level_cycle(dtree, feature_names, feature_types, target_names, debug=False):
    while True:
        query = input()
        if query in ['q', 'quit']:
            break
        answer = high_level_single(dtree, feature_names, feature_types, target_names, query, debug)
        print(answer, end='')

def high_level_single(dtree, feature_names, feature_types, target_names, query, debug=False):
    binary_fbdd, dim = to_binary_model(dtree, feature_names, feature_types, target_names, query)
    model_string = json.dumps(final_json_from_rec(binary_fbdd, dim, target_names))
    with open('./build/afbdd.txt', 'w') as f:
        f.write(model_string)
    low_query = to_low(dtree, feature_names, feature_types, target_names, query)
    if debug: print(low_query)
    result = subprocess.run(['./build/main', '--one', '--model=afbdd', '--file=./build/afbdd.txt', '--v=3'],
            input=low_query,
            capture_output=True,
            text=True)
    return result.stdout

# source of randomness is not really important here, so I'll just use Python's default.
import random
def random_boolean_instance(dimension):
  return [random.randint(0,1) for _ in range(dimension)]


def generate_random_dataset(n_samples, dimension, force_label=None):
  X = [ random_boolean_instance(dimension) for sample in range(n_samples)]
  if force_label is None:
    y = random_boolean_instance(n_samples)
  else:
    y = [force_label for _ in range(n_samples)]
  return X, y

def generate_random_dt(dimension, n_leaves, dataset):

  dt = DecisionTreeClassifier(max_leaf_nodes=n_leaves, random_state=0)
  X, y = dataset
  dt.fit(X, y)

  ft_names = [ f'ft{i}' for i in range(dimension)]
  ft_types = ['boolean' for _ in range(dimension)]
  class_names = ['positive', 'negative']
  dt_dict = tree_to_dict(ft_names, ft_types, class_names, dt)
  #check that numbr of actual leaves is not too different from specified
  n_actual_leaves = len(list(filter(lambda x: x['type'] == 'leaf', dt_dict['nodes'].values())))
  if  n_actual_leaves < n_leaves // 2:
    print(f"n_actual_leaves = {n_actual_leaves}, n_leaves = {n_leaves}")
  return json.dumps(dt_dict, indent=2)

def random_dt_file(filename, dimension, n_leaves, dataset):
  with open(filename, 'w') as f:
    f.write(generate_random_dt(dimension, n_leaves, dataset))
