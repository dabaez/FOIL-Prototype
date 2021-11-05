#include "AFBDDNode.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cassert>

AFBDDNode::AFBDDNode(int label, const std::shared_ptr<AFBDDNode> left, const std::shared_ptr<AFBDDNode> right) :
    label(label), left(left), right(right), leaf(true), depth(0), size(1)
{
    if(label >= 0) { // non leaf
        leaf = false;
        if(left == nullptr or right == nullptr) {
            throw std::invalid_argument("trying to build a non-leaf node but one subtree is null");
        }
        size = 1 + left->getSize() + right->getSize();
        dimension = std::max(1 + label, std::max(left->getDimension(), right->getDimension()));
        depth = 1 + std::max(left->depth, right->depth);
    } else {
        dimension = 0;
        if(left != nullptr or right != nullptr) {
            throw std::invalid_argument("trying to build a leaf but one subtree is not null");
        }
    }
}

AFBDDNode::AFBDDNode() {
    leaf = false;
    label = -3;
    left = nullptr;
    right = nullptr;
    dimension = 0;
}

int AFBDDNode::getDimension() const {
    int maxLeft = 0;
    int maxRight = 0;
    if(left) {
        maxLeft = left->getDimension();
    }
    if(right) {
        maxRight = right->getDimension();
    }
    return std::max(1 + label, std::max(maxLeft, maxRight));
}

void AFBDDNode::setLabel(int newlabel) {
    label = newlabel;
}

void AFBDDNode::setLeft(const std::shared_ptr<AFBDDNode> newleft) {
    left  = newleft;
}

void AFBDDNode::setRight(const std::shared_ptr<AFBDDNode> newright) {
    right = newright;
}

AFBDDNode::AFBDDNode(bool leafValue) : AFBDDNode(-2 + int(leafValue), nullptr, nullptr) {}

bool AFBDDNode::predict(const std::vector<bool>& instance) const {
    if(this->isLeaf()) {
        return this->isTrueLeaf();
    }
    if(label >= int(instance.size())) {
        throw std::invalid_argument("given instance has less dimension than the model");
    }

    if(instance[label]) {
        return this->right->predict(instance);
    } else {
        return this->left->predict(instance);
    }
}

bool AFBDDNode::isTrueLeaf() const {
    assert(this->isLeaf());
    return (label == -1);
}


bool AFBDDNode::isLeaf() const {
    return leaf;
}

int AFBDDNode::getDepth() const {
    return depth;
}

int AFBDDNode::getSize() const {
    return size;
}

const std::shared_ptr<AFBDDNode> AFBDDNode::TRUE = std::make_shared<AFBDDNode>(-1, nullptr, nullptr);
const std::shared_ptr<AFBDDNode> AFBDDNode::FALSE = std::make_shared<AFBDDNode>(-2, nullptr, nullptr);


bool AFBDDNode::complete(const std::vector<int>& x, std::map<const AFBDDNode*, bool>& dp) const {
    if (this->isLeaf()){
        return this->isTrueLeaf();
    }

    if(dp.count(this)) {
        return dp[this];
    }
    if (x[label] == 2) return dp[this] = (this->right->complete(x, dp)) || (this->left->complete(x, dp));
    else if (x[label]) return dp[this] = this->right->complete(x, dp);
    else return dp[this] = this->left->complete(x, dp);
}

bool AFBDDNode::negativeComplete(const std::vector<int>& x, std::map<const AFBDDNode*, bool>& dp) const {
    if (this->isLeaf()){
        return not this->isTrueLeaf();
    }

    if(dp.count(this)) {
        return dp[this];
    }
    if (x[label] == 2) return dp[this] = (this->right->negativeComplete(x, dp)) || (this->left->negativeComplete(x, dp));
    else if (x[label]) return dp[this] = this->right->negativeComplete(x, dp);
    else return dp[this] = this->left->negativeComplete(x, dp);
}
