#include <memory>

class DTNode {
    public:
        DTNode(int label, const std::shared_ptr<DTNode> left, const std::shared_ptr<DTNode> right);

        bool predict(const std::vector<bool>& instance);

        bool isLeaf();

        bool leafValue();

        int getDepth(); // dfefined as the number of edges in the longest path root-to-leaf

        int getSize(); // defined as the total number of nodes
        
        // leaves
        const static std::shared_ptr<DTNode> TRUE;
        const static std::shared_ptr<DTNode> FALSE;

        int label; // -2 -> false, -1 -> true, 0...n-1 -> feature labels
        std::shared_ptr<DTNode> left;
        std::shared_ptr<DTNode> right;
        
        
    private:
        bool leaf;
        int depth;
        int size;
};
