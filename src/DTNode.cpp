#include "DTNode.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cassert>


DTNode::DTNode(int label, const std::shared_ptr<DTNode> left, const std::shared_ptr<DTNode> right) :
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

DTNode::DTNode() {
    leaf = false;
    label = -3;
    left = nullptr;
    right = nullptr;
    dimension = 0;
}

int DTNode::getDimension() const {
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

void DTNode::setLabel(int newlabel) {
    label = newlabel;
}

void DTNode::setLeft(const std::shared_ptr<DTNode> newleft) {
    left  = newleft;
}

void DTNode::setRight(const std::shared_ptr<DTNode> newright) {
    right = newright;
}

DTNode::DTNode(bool leafValue) : DTNode(-2 + int(leafValue), nullptr, nullptr) {}

bool DTNode::predict(const std::vector<bool>& instance) const {
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

DTNode DTNode::negate() const {
    if(this->isLeaf()) {
       return DTNode(!this->isTrueLeaf());
    }
    return DTNode(label, std::make_shared<DTNode>(left->negate()), std::make_shared<DTNode>(right->negate()));
}

std::shared_ptr<DTNode> DTNode::unite(const std::shared_ptr<DTNode> other) const {
   if(this->isLeaf()) {
        if(this->isTrueLeaf()) {
            return DTNode::TRUE;
        } else {
            return other;
        }
   }
   return std::make_shared<DTNode>(this->label, this->left->unite(other), this->right->unite(other));
}

DTNode DTNode::condition(const std::unordered_map<int, int>& conds) const {
    return DTNode(1, nullptr, nullptr); // TODO
}

bool DTNode::isTrueLeaf() const {
    assert(this->isLeaf());
    return (label == -1);
}


bool DTNode::isLeaf() const {
    return leaf;
}

int DTNode::getDepth() const {
    return depth;
}

int DTNode::getSize() const {
    return size;
}

const std::shared_ptr<DTNode> DTNode::TRUE = std::make_shared<DTNode>(-1, nullptr, nullptr);
const std::shared_ptr<DTNode> DTNode::FALSE = std::make_shared<DTNode>(-2, nullptr, nullptr);


bool DTNode::complete(const std::vector<int>& x) const {
    if (this->isLeaf()){
        //return false;
        return this->isTrueLeaf();
    }
    if (x[label] == 2) return (this->right->complete(x)) || (this->left->complete(x));
    else if (x[label]) return this->right->complete(x);
    else return this->left->complete(x);
}

bool DTNode::negativeComplete(const std::vector<int>& x) const {
    if (this->isLeaf()){
        return not this->isTrueLeaf();
    }
    if (x[label] == 2) return (this->right->negativeComplete(x)) || (this->left->negativeComplete(x));
    else if (x[label]) return this->right->negativeComplete(x);
    else return this->left->negativeComplete(x);
}
