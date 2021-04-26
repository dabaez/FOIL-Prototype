#include "DecisionTree.h"

#include <vector>

DecisionTree::DecisionTree() {
    root = {};
    size = 0;
}

DecisionTree::DecisionTree(std::shared_ptr<DTNode> root) : root(root) {
    size = root->getSize();
}

DecisionTree::DecisionTree(DTNode& oroot) {
    root = std::make_shared<DTNode>(oroot);
    size = root->getSize();
}


bool DecisionTree::predict(const std::vector<bool>& instance) const {
    return root->predict(instance);
}


void DecisionTree::readFromFile(const std::string& filename) {
    //  # nodos internos (entero N)
    //  N líneas
    //  label <id izq> <id der>
    //
    //     2
    //    / \
    //    1   0
    //   / \ / \
    //   F T T F
    std::ifstream dt(filename);
    int N;
    dt >> N;
    std::vector<std::shared_ptr<DTNode>> nodes(N);
    for(int i = 0; i < N; ++i) 
        nodes[i] = std::make_shared<DTNode>();

    for(int i = 0; i < N; ++i) {
        int label, left, right;
        dt >> label >> left >> right;
        nodes[i]->setLabel(label);
        if(left == -2) {
            nodes[i]->setLeft(DTNode::FALSE);
        } else if(left == -1) {
            nodes[i]->setLeft(DTNode::TRUE);
        } else {
            nodes[i]->setLeft(nodes[left]);
        }
        if(right == -2) {
            nodes[i]->setRight(DTNode::FALSE);
        } else if(right == -1) {
            nodes[i]->setRight(DTNode::TRUE);
        } else {
            nodes[i]->setRight(nodes[right]);
        }
    }
    root = nodes[0];
    return;
}

void DecisionTree::readFromConsole() {
    return;
}

bool DecisionTree::checkVector(const std::vector<int>& instance) const {
    return this->vectorSize() >= int(instance.size());
}

int DecisionTree::vectorSize() const {
    return root->getDimension();
}   

int DecisionTree::getSize() const {
    return size;
}


DecisionTree DecisionTree::condition(const std::vector<bool>& instance) const {
    return DecisionTree();
}

DecisionTree DecisionTree::intersect(const DecisionTree& other) const {
    return DecisionTree();
}

DecisionTree DecisionTree::unite(const DecisionTree& other) const {
    return DecisionTree(root->unite(other.root));
}

DecisionTree DecisionTree::negate() const {
    return DecisionTree(std::make_shared<DTNode>(root->negate()));
}

