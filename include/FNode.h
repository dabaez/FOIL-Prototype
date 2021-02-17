#include <memory>
#include <unordered_map>
#include <vector>

class FNode {
    public:
        FNode(int label, const std::shared_ptr<FNode> left, const std::shared_ptr<FNode> right);

        FNode();

        void setLabel(int newlabel);

        void setLeft(const std::shared_ptr<FNode> newleft);

        void setRight(const std::shared_ptr<FNode> newright);

        FNode(bool leafValue);

        bool predict(const std::vector<bool>& instance) const;

        FNode negate() const;

        FNode intersect(const std::shared_ptr<FNode> other) const;

        FNode condition(const std::unordered_map<int, int>& cond) const;

        int getDimension() const;

        bool isLeaf() const;

        bool isTrueLeaf() const;

        int getDepth() const; // dfefined as the number of edges in the longest path root-to-leaf

        int getSize() const; // defined as the total number of nodes
        
        // leaves
        const static std::shared_ptr<FNode> TRUE;
        const static std::shared_ptr<FNode> FALSE;

        int label; // -2 -> false, -1 -> true, 0...n-1 -> feature labels
        std::shared_ptr<FNode> left;
        std::shared_ptr<FNode> right;
        
        
    private:
        bool leaf;
        int depth;
        int size;
        int dimension;
};
