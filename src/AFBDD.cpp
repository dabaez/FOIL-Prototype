#include "AFBDD.h"
#include "json.hpp"

#include <map>
#include <vector>

using json = nlohmann::json;


AFBDD::AFBDD() {
    root = {};
    size = 0;
    dimension = 0;
}

AFBDD::AFBDD(std::shared_ptr<AFBDDNode> root, int dimension) : root(root), dimension(dimension) {
    size = root->getSize();
}

AFBDD::AFBDD(AFBDDNode& oroot, int dimension) : dimension(dimension) {
    root = std::make_shared<AFBDDNode>(oroot);
    size = root->getSize();
}


bool AFBDD::predict(const std::vector<bool>& instance) const {
    return root->predict(instance);
}


void AFBDD::readFromFile(const std::string& filename) {
    std::ifstream json_file(filename);
    json j; json_file >> j;
    json nodes = j["nodes"];
    std::string positive = j["positive"];

    int N = nodes.size();
    std::vector<std::shared_ptr<AFBDDNode>> dtnodes(N);
    for(int i = 0; i < N; ++i)
        dtnodes[i] = std::make_shared<AFBDDNode>();

    for(int i = 0; i < N; ++i) {
        json node = nodes[std::to_string(i)];
        if(node["type"] == "internal") {
            dtnodes[i]->setLabel(node["feature_index"]);
            int left_index = node["id_left"];
            int right_index = node["id_right"];
            json left = nodes[std::to_string(left_index)];
            json right = nodes[std::to_string(right_index)];
            if(left["type"] == "leaf") {
                dtnodes[i]->setLeft((left["class"] == positive ? AFBDDNode::TRUE : AFBDDNode::FALSE));
            } else {
                dtnodes[i]->setLeft(dtnodes[left_index]);
            }

            if(right["type"] == "leaf") {
                dtnodes[i]->setRight((right["class"] == positive ? AFBDDNode::TRUE : AFBDDNode::FALSE));
            } else {
                dtnodes[i]->setRight(dtnodes[right_index]);
            }
        }

    }
    root = dtnodes[0];
    dimension = j["feature_names"].size();
    return;
}

void AFBDD::readFromConsole() {
    return;
}

bool AFBDD::checkVector(const std::vector<int>& instance) const {
    return this->vectorSize() >= int(instance.size());
}

int AFBDD::vectorSize() const {
    return dimension;
}

int AFBDD::getSize() const {
    return size;
}

bool AFBDD::complete(const std::vector<int>& x) const {
    std::map<const AFBDDNode*, bool> dp;
    return root->complete(x, dp);
}

bool AFBDD::negativeComplete(const std::vector<int>& x) const {
    std::map<const AFBDDNode*, bool> dp;
    return root->negativeComplete(x, dp);
}
