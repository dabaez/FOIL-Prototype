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

DTNode::DTNode(bool leafValue) : DTNode(-2 + int(leafValue), nullptr, nullptr) {}

bool DTNode::predict(const std::vector<bool>& instance) {
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

DTNode DTNode::negate() {
    if(this->isLeaf()) {
       return DTNode(!this->isTrueLeaf());
    }
    return DTNode(label, std::make_shared<DTNode>(left->negate()), std::make_shared<DTNode>(right->negate()));
}

DTNode DTNode::condition(const std::unordered_map<int, int>& conds) {
    return DTNode(1, nullptr, nullptr); // TODO 
}  

/*DTNode DTNode::intersect(const std::shared_ptr<DTNode> other) {*/
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

bool DTNode::isTrueLeaf() {
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


