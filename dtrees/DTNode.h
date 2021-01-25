#include <memory>

class DTNode {
    public:
        int label; // -1 -> false, 0 -> true, 1...n -> feature labels
        std::shared_ptr<DTNode> left;
        std::shared_ptr<DTNode> right;
        bool isLeaf();
};
