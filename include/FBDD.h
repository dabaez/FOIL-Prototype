#pragma once

#include <vector>
#include "FNode.h"
#include "models.h"

// Assumes binary features TODO: check if it's worth expanding
class FBDD : public IModel {
    public:
        FBDD();

        FBDD(std::shared_ptr<FNode> root);

        FBDD(FNode& oroot);

        bool predict(const std::vector<bool>& instance) const override;

        bool complete(const std::vector<int>& instance) const override;

        void readFromFile(const std::string& filename) override;

        void readFromConsole() override;

        bool checkVector(const std::vector<int>& instance) const override;

        int vectorSize() const override;

        int getSize() const;
        
        int getDepth() const;

        FBDD condition(const std::vector<bool>& instance) const;

        FBDD intersect(const FBDD& other) const;

        FBDD unite(const FBDD& other) const; // the word union is reserved in C++.

        FBDD negate() const;

    private:
        std::shared_ptr<FNode> root;
        int size;
};
