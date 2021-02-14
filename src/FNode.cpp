#include "FNode.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cassert>


FNode::FNode(int label, const std::shared_ptr<FNode> left, const std::shared_ptr<FNode> right) :
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

FNode::FNode() {
    leaf = false;
    label = -3;
    left = nullptr;
    right = nullptr;
    dimension = 0;
}

int FNode::getDimension() const {
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

void FNode::setLabel(int newlabel) {
    label = newlabel;
}

void FNode::setLeft(const std::shared_ptr<FNode> newleft) {
    left  = newleft;
}

void FNode::setRight(const std::shared_ptr<FNode> newright) {
    right = newright;
}

FNode::FNode(bool leafValue) : FNode(-2 + int(leafValue), nullptr, nullptr) {}

bool FNode::predict(const std::vector<bool>& instance) const {
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

FNode FNode::negate() const {
    if(this->isLeaf()) {
       return FNode(!this->isTrueLeaf());
    }
    return FNode(label, std::make_shared<FNode>(left->negate()), std::make_shared<FNode>(right->negate()));
}

FNode FNode::condition(const std::unordered_map<int, int>& conds) const {
    return FNode(1, nullptr, nullptr); // TODO 
}  

/*FNode FNode::intersect(const std::shared_ptr<FNode> other) {*/
    //if(this->isLeaf()) {
        //if(this->isTrueLeaf()) {
            //return condition(other, path);
        //} else {
            //return FALSE;
        //}
    //}
    //// case where they share the root label
    

    //// case where they don't
/*}*/

bool FNode::isTrueLeaf() const {
    assert(this->isLeaf());
    return (label == -1);
}


bool FNode::isLeaf() const {
    return leaf;
}

int FNode::getDepth() const {
    return depth;
}

int FNode::getSize() const {
    return size;
} 

const std::shared_ptr<FNode> FNode::TRUE = std::make_shared<FNode>(-1, nullptr, nullptr);
const std::shared_ptr<FNode> FNode::FALSE = std::make_shared<FNode>(-2, nullptr, nullptr);


