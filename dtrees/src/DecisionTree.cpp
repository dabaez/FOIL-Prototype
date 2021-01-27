#include "DecisionTree.h"

#include <vector>

DecisionTree::DecisionTree() {
    root = {};
    size = 0;
}


bool DecisionTree::predict(const std::vector<bool>& instance) const {
    return true;
}

int DecisionTree::getSize() const {
    return 0;
}


DecisionTree DecisionTree::condition(const std::vector<bool>& instance) const {
    return DecisionTree();
}

DecisionTree DecisionTree::intersect(const DecisionTree& other) const {
    return DecisionTree();
}

DecisionTree DecisionTree::unite(const DecisionTree& other) const {
    return DecisionTree();
}

DecisionTree DecisionTree::negate(const DecisionTree& other) const {
    return DecisionTree();
}

