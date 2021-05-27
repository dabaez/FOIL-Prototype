#include <memory>
#include <unordered_map>
#include <vector>

class DTNode {
    public:
        DTNode(int label, const std::shared_ptr<DTNode> left, const std::shared_ptr<DTNode> right);

        DTNode();

        void setLabel(int newlabel);

        void setLeft(const std::shared_ptr<DTNode> newleft);

        void setRight(const std::shared_ptr<DTNode> newright);

        DTNode(bool leafValue);

        bool predict(const std::vector<bool>& instance) const;

        DTNode negate() const;

        std::shared_ptr<DTNode> unite(const std::shared_ptr<DTNode> other) const;

        DTNode intersect(const std::shared_ptr<DTNode> other) const;

        DTNode condition(const std::unordered_map<int, int>& cond) const;

        int getDimension() const;

        bool isLeaf() const;

        bool isTrueLeaf() const;

        int getDepth() const; // dfefined as the number of edges in the longest path root-to-leaf

        int getSize() const; // defined as the total number of nodes

        bool complete(const std::vector<int>& x) const;

        bool negativeComplete(const std::vector<int>& x) const;
        
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
        int dimension;
};
