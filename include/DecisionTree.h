#pragma once

#include <vector>
#include "DTNode.h"
#include "models.h"

// Assumes binary features TODO: check if it's worth expanding
class DecisionTree : public IModel {
    public:
        DecisionTree();

        DecisionTree(std::shared_ptr<DTNode> root, int dimension);

        DecisionTree(DTNode& oroot, int dimension);

        bool predict(const std::vector<bool>& instance) const override;

        bool complete(const std::vector<int>& x) const override;
        
        bool negativeComplete(const std::vector<int>& x) const override;

        void readFromFile(const std::string& filename) override;

        void readFromConsole() override;

        bool checkVector(const std::vector<int>& instance) const override;

        int vectorSize() const override;

        int getSize() const;
        
        int getDepth() const;

    private:
        std::shared_ptr<DTNode> root;
        int size;
        int dimension;
};
