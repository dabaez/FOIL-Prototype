#include <vector>
#include <DTNode.h>

// Assumes binary features TODO: check if it's worth expanding
class DecisionTree {
    public:
        DecisionTree();
        ~DecisionTree();

        bool predict(const std::vector<bool>& instance) const;

        int size() const;

        DecisionTree condition(const std::vector<bool>& instance) const;

        DecisionTree intersect(const DecisionTree& other) const;

        DecisionTree unite(const DecisionTree& other) const; // the word union is reserved in C++.

        DecisionTree negate(const DecisionTree& other) const;

    private:
        DTNode root;
        int size;
};
