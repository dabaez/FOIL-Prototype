#include <memory>

class DTNode {
    public:
        DTNode(int label, const std::shared_ptr<DTNode> left, const std::shared_ptr<DTNode> right);

        bool isLeaf();

        int getDepth(); // dfefined as the number of edges in the longest path root-to-leaf

        int getSize(); // defined as the total number of nodes
        
        // leaves
        const static std::shared_ptr<DTNode> TRUE;
        const static std::shared_ptr<DTNode> FALSE;

        int label; // -1 -> false, 0 -> true, 1...n -> feature labels
        std::shared_ptr<DTNode> left;
        std::shared_ptr<DTNode> right;
        
        
    private:
        bool leaf;
        int depth;
        int size;
};
