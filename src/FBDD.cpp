#include "FBDD.h"

#include <vector>

FBDD::FBDD() {
    root = {};
    size = 0;
}

FBDD::FBDD(std::shared_ptr<FNode> root) : root(root) {
    size = root->getDimension();
}

FBDD::FBDD(FNode& oroot) {
    root = std::make_shared<FNode>(oroot);
    size = root->getSize();
}


bool FBDD::predict(const std::vector<bool>& instance) const {
    return root->predict(instance);
}


void FBDD::readFromFile(const std::string& filename) {
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
    std::vector<std::shared_ptr<FNode>> nodes(N);
    for(int i = 0; i < N; ++i) 
        nodes[i] = std::make_shared<FNode>();

    for(int i = 0; i < N; ++i) {
        int label, left, right;
        dt >> label >> left >> right;
        nodes[i]->setLabel(label);
        if(left == -2) {
            nodes[i]->setLeft(FNode::FALSE);
        } else if(left == -1) {
            nodes[i]->setLeft(FNode::TRUE);
        } else {
            nodes[i]->setLeft(nodes[left]);
        }
        if(right == -2) {
            nodes[i]->setRight(FNode::FALSE);
        } else if(right == -1) {
            nodes[i]->setRight(FNode::TRUE);
        } else {
            nodes[i]->setRight(nodes[right]);
        }
    }
    root = nodes[0];
    return;
}

void FBDD::readFromConsole() {
    return;
}

bool FBDD::checkVector(const std::vector<int>& instance) const {
    return this->vectorSize() >= int(instance.size());
}

int FBDD::vectorSize() const {
    return root->getDimension();
}   

int FBDD::getSize() const {
    return size;
}


FBDD FBDD::condition(const std::vector<bool>& instance) const {
    return FBDD();
}

FBDD FBDD::intersect(const FBDD& other) const {
    return FBDD();
}

FBDD FBDD::unite(const FBDD& other) const {
    return FBDD();
}

FBDD FBDD::negate() const {
    return FBDD(std::make_shared<FNode>(root->negate()));
}

bool FBDD::complete(const std::vector<int>& instance) const {
    // Not implemented yet
    return true;
}