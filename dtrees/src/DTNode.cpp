#include "DTNode.h"

#include <memory>
#include <algorithm>



DTNode::DTNode(int label, const std::shared_ptr<DTNode> left, const std::shared_ptr<DTNode> right) :
    label(label), left(left), right(right), leaf(true), depth(0), size(1)
{
    if(label > 1) { // non leaf
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
};


bool DTNode::isLeaf() {
    return leaf;
}

int DTNode::getDepth() {
    return depth;
}

int DTNode::getSize() {
    return size;
} 

const auto DTNode::TRUE = std::make_shared<DTNode>(0, nullptr, nullptr);
const auto DTNode::FALSE = std::make_shared<DTNode>(-1, nullptr, nullptr);


