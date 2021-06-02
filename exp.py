import time
import subprocess
import resource
import numpy as np
import json
import pandas as pd
import os

def time1(query):
    q = open("query.txt","w")
    q.write(query + "\n")
    q.close()
    times = []
    out = ""
    for i in range(5):
        usage_start = resource.getrusage(resource.RUSAGE_CHILDREN)
        try:
            sp = subprocess.run("./main --model=dt --file=dt.txt --v=2 < query.txt", shell = True, capture_output = True , timeout = 60 )
            usage_end = resource.getrusage(resource.RUSAGE_CHILDREN)
            cpu_time = usage_end.ru_utime - usage_start.ru_utime
            out = sp.stdout.splitlines()[3]
            times.append(cpu_time)
        except:
            print("timeout with query " + query)
            times = [60,60,60,60,60]
            out = "timeout"
            break
    return (times , out)

def random_constant(query , dt_size):
    ans = ""
    idx = 1
    for i in range(len(query[0])):
        if (query[0][i] == 'C'):
            ans+="[ "
            for j in range(dt_size):
                if (j):
                    ans += " , "
                val = query[idx][j]
                if (val == 2): val = '?'
                else: val = str(val)
                ans += val
            ans += " ] "
            idx+=1
        else:
            ans+=query[0][i]
    return ans

def generate_query(squeries , nvars , rng):
    query = ""
    isnot = rng.integers(2)
    if (isnot):
        query += " ~ ( "
    if (squeries == 1):
        
        if (nvars == 1):
            opt = rng.integers(3)
        else:
            opt = rng.integers(4)
        
        if (opt == 0):
            
            query += " P ( x" + str( rng.integers(nvars) + 1 ) + " ) "
        
        if (opt == 1):
            
            query += " C <= x" + str( rng.integers(nvars) + 1 ) + " "
        
        if (opt == 2):
            
            query += " x" + str( rng.integers(nvars) + 1 ) + " <= C "
            
        if (opt == 3):
            
            x1 = rng.integers(nvars) + 1
            x2 = rng.integers(nvars) + 1
            while (x2 == x1):
                x2 = rng.integers(nvars) + 1
            query += " x" + str(x1) + " <= x" + str(x2) + " "
        
    else:
        
        query += " ( "
        fs = rng.integers(squeries-1) + 1
        query += generate_query(fs , nvars , rng)
        
        if ( rng.integers(2) ):
            query += " ) V ( "
        else:
            query += " ) ^ ( "
            
        query += generate_query(squeries - fs , nvars , rng) + " ) "
    
    if (isnot):
        query += " ) "
    
    return query
    
def create_constant(max_s,rng):
    return rng.integers(3,size=max_s)

def replace_constants(q , cs, dim):
    nq = ""
    idx = 0
    for l in q:
        if l == 'C':
            nq += " [ "
            for j in range(dim):
                if (j): nq += " , "
                if (cs[idx][j] == 2): nq += " ? "
                else: nq += str(cs[idx][j])
            nq += " ] "
            idx+=1
        else: nq += l
    return nq

def load_tree(dt_name):
    with open("../dtrees/" + dt_name) as json_file:
        data = json.load(json_file)
        
    with open('dt.txt', 'w') as outfile:
        json.dump(data, outfile)
        
def queries_with_tree( dim, leaves, queries, constants ):
    load_tree("dim_" + str(dim) + "_nleaves_" + str(leaves) + ".json")
    n = len(queries)
    info = [ dim , leaves ]
    table = []
    
    for i in range(n):
        q = replace_constants(queries[i] , constants[i] , dim)
        tims =  time1( q )
        tp = (sum( tims[0] ) - max(tims[0]) - min(tims[0]) )/3
        info.append(tp)
        table.append( [ q ] + tims[0] + [ tims[1] , tp ]  )
    
    df = pd.DataFrame( table , columns = ["query" , "t1" , "t2" , "t3" , "t4" , "t5" , "ans" , "tp"] )
    
    df.to_csv( "data/dim_" + str(dim) + "_nleaves_" + str(leaves) + ".csv")
    
    return info
    

def run_queries(queries , seed):
    
    cs = []
    rng = np.random.default_rng()
    maxdim = 0
    for filename in os.listdir("../dtrees"):
        maxdim = max( maxdim , int(filename.split("_")[1]) )
    for query in queries:
        cc = []
        for j in range( query.count('C') ):
            cc.append( create_constant( maxdim , rng ) )
        cs.append(cc)
    
    table = []
    table2 = []
    
    for filename in os.listdir("../dtrees"):
        dim = int(filename.split("_")[1])
        leaf = int( filename.split("_")[3].split(".")[0] )
        print("tree with " + str(dim) + " dimensions and " + str(leaf) + " leaves started testing")
        table.append( queries_with_tree(dim , leaf , queries , cs) )
        print("tree with " + str(dim) + " dimensions and " + str(leaf) + " leaves finished testing")
        table2.append([dim, leaf, sum(table[len(table)-1][2:])/len(queries) , max(table[len(table)-1][2:]) ])

    df = pd.DataFrame( table , columns = ["dimension" , "leaves" ] + queries )
    df.to_csv("queries.csv")
    df = pd.DataFrame( table2 , columns = ["dimension" , "leaves" , "average" , "maximum"])
    df.to_csv("experiment_data.csv")
    os.remove("query.txt")
    os.remove("dt.txt")
    
def ran_generate_queries(nvarmin,nvarmax,querysmin,querysmax,nqueries,seed):
    rng = np.random.default_rng(seed)
    qs = []
    for i in range(nqueries):
        nvars = rng.integers( nvarmin, nvarmax, endpoint = True )
        q = ""
        ex = rng.integers(2)
        for j in range(nvars):
            if (ex):
                q += "Exists x" + str(j + 1) + ", "
            else:
                q += "Forall x" + str(j + 1) + ", "
        q += generate_query( rng.integers( querysmin, querysmax, endpoint = True ) , nvars, rng )
        qs.append(q)
    return qs

os.chdir( os.getcwd() + "/build" )

os.makedirs( os.getcwd() + "/data", exist_ok = True)

qs = ran_generate_queries(2,4,3,5,60,10)

with open("queries.txt","w") as text:
    for i in range(len(qs)):
        text.write(qs[i] + "\n")

run_queries(qs,10)
