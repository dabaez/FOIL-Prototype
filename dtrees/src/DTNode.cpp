#include "DTNode.h"

#include <vector>
#include <memory>
#include <algorithm>



DTNode::DTNode(int label, const std::shared_ptr<DTNode> left, const std::shared_ptr<DTNode> right) :
    label(label), left(left), right(right), leaf(true), depth(0), size(1)
{
    if(label >= 0) { // non leaf
        leaf = false;
        if(left == nullptr or right == nullptr) {
            throw std::invalid_argument("trying to build a non-leaf node but one subtree is null");
        }
        size = 1 + left->getSize() + right->getSize();
        depth = 1 + std::max(left->depth, right->depth);
    } else {
        if(left != nullptr or right != nullptr) {
            throw std::invalid_argument("trying to build a leaf but one subtree is not null");
        }
    }
}

bool DTNode::predict(const std::vector<bool>& instance) {
    if(this->isLeaf()) {
        return this->leafValue();
    }
    if(label >= instance.size()) {
        throw std::invalid_argument("given instance has less dimension than the model");
    }

    if(instance[label]) {
        return this->right->predict(instance);
    } else {
        return this->left->predict(instance);
    }

}

bool DTNode::leafValue() {
    assert(this->isLeaf());
    return (label == -1);
}


bool DTNode::isLeaf() {
    return leaf;
}

int DTNode::getDepth() {
    return depth;
}

int DTNode::getSize() {
    return size;
} 

const auto DTNode::TRUE = std::make_shared<DTNode>(-1, nullptr, nullptr);
const auto DTNode::FALSE = std::make_shared<DTNode>(-2, nullptr, nullptr);

