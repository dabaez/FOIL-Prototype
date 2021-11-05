#include "DecisionTree.h"
#include "json.hpp"

#include <vector>

using json = nlohmann::json;


DecisionTree::DecisionTree() {
    root = {};
    size = 0;
    dimension = 0;
}

DecisionTree::DecisionTree(std::shared_ptr<DTNode> root, int dimension) : root(root), dimension(dimension) {
    size = root->getSize();
}

DecisionTree::DecisionTree(DTNode& oroot, int dimension) : dimension(dimension) {
    root = std::make_shared<DTNode>(oroot);
    size = root->getSize();
}


bool DecisionTree::predict(const std::vector<bool>& instance) const {
    return root->predict(instance);
}


void DecisionTree::readFromFile(const std::string& filename) {
    std::ifstream json_file(filename);
    json j; json_file >> j;
    json nodes = j["nodes"];
    std::string positive = j["positive"];

    int N = nodes.size();
    std::vector<std::shared_ptr<DTNode>> dtnodes(N);
    for(int i = 0; i < N; ++i)
        dtnodes[i] = std::make_shared<DTNode>();

    for(int i = 0; i < N; ++i) {
        json node = nodes[std::to_string(i)];
        if(node["type"] == "internal") {
            dtnodes[i]->setLabel(node["feature_index"]);
            int left_index = node["id_left"];
            int right_index = node["id_right"];
            json left = nodes[std::to_string(left_index)];
            json right = nodes[std::to_string(right_index)];
            if(left["type"] == "leaf") {
                dtnodes[i]->setLeft((left["class"] == positive ? DTNode::TRUE : DTNode::FALSE));
            } else {
                dtnodes[i]->setLeft(dtnodes[left_index]);
            }

            if(right["type"] == "leaf") {
                dtnodes[i]->setRight((right["class"] == positive ? DTNode::TRUE : DTNode::FALSE));
            } else {
                dtnodes[i]->setRight(dtnodes[right_index]);
            }
        }

    }
    root = dtnodes[0];
    dimension = j["feature_names"].size();
    return;
}

void DecisionTree::readFromConsole() {
    return;
}

bool DecisionTree::checkVector(const std::vector<int>& instance) const {
    return this->vectorSize() >= int(instance.size());
}

int DecisionTree::vectorSize() const {
    return dimension;
}

int DecisionTree::getSize() const {
    return size;
}

bool DecisionTree::complete(const std::vector<int>& x) const {
    return root->complete(x);
}

bool DecisionTree::negativeComplete(const std::vector<int>& x) const {
    return root->negativeComplete(x);
}
