#pragma once

#include <vector>
#include "AFBDDNode.h"
#include "models.h"

// Assumes binary features TODO: check if it's worth expanding
class AFBDD : public IModel {
    public:
        AFBDD();

        AFBDD(std::shared_ptr<AFBDDNode> root, int dimension);

        AFBDD(AFBDDNode& oroot, int dimension);

        bool predict(const std::vector<bool>& instance) const override;

        bool complete(const std::vector<int>& x) const override;
        
        bool negativeComplete(const std::vector<int>& x) const override;

        void readFromFile(const std::string& filename) override;

        void readFromConsole() override;

        bool checkVector(const std::vector<int>& instance) const override;

        int vectorSize() const override;

        int getSize() const;

        int getDepth() const;

        // AFBDD condition(const std::vector<bool>& instance) const;
        //
        // AFBDD intersect(const AFBDD& other) const;
        //
        // AFBDD unite(const AFBDD& other) const; // the word union is reserved in C++.
        //
        // AFBDD negate() const;

    private:
        std::shared_ptr<AFBDDNode> root;
        int size;
        int dimension;
};
