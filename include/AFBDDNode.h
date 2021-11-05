#include <memory>
#include <unordered_map>
#include <map>
#include <vector>

class AFBDDNode {
    public:
        AFBDDNode(int label, const std::shared_ptr<AFBDDNode> left, const std::shared_ptr<AFBDDNode> right);

        AFBDDNode();

        void setLabel(int newlabel);

        void setLeft(const std::shared_ptr<AFBDDNode> newleft);

        void setRight(const std::shared_ptr<AFBDDNode> newright);

        AFBDDNode(bool leafValue);

        bool predict(const std::vector<bool>& instance) const;

        int getDimension() const;

        bool isLeaf() const;

        bool isTrueLeaf() const;

        int getDepth() const; // dfefined as the number of edges in the longest path root-to-leaf

        int getSize() const; // defined as the total number of nodes

        bool complete(const std::vector<int>& x, std::map<const AFBDDNode*, bool>& dp) const;

        bool negativeComplete(const std::vector<int>& x, std::map<const AFBDDNode*, bool>& dp) const;

        // leaves
        const static std::shared_ptr<AFBDDNode> TRUE;
        const static std::shared_ptr<AFBDDNode> FALSE;

        int label; // -2 -> false, -1 -> true, 0...n-1 -> feature labels
        std::shared_ptr<AFBDDNode> left;
        std::shared_ptr<AFBDDNode> right;


    private:
        bool leaf;
        int depth;
        int size;
        int dimension;
};
