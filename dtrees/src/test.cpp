#include "DecisionTree.h"

#include <iostream>

int main()
{
    const auto T = DTNode::TRUE;
    const auto F = DTNode::FALSE;
    const auto n = std::make_shared<DTNode>(1, F, T);
    const auto n2 = std::make_shared<DTNode>(2, F, n);
    const auto n3 = std::make_shared<DTNode>(2, T, F);
    const auto n4 = std::make_shared<DTNode>(0, n2, n3);
    /*
     *            0
     *          /    \
     *         2      2
     *        / \    /  \
     *       F   1  T    F
     *          / \
     *         F   T
     *
     *
     *
     */
    const DecisionTree DT {n4};
    assert(DT.predict({1, 0, 0}));
    assert(DT.predict({1, 1, 0}));
    assert(not DT.predict({1, 1, 1}));
    assert(not DT.predict({0, 1, 0}));
    assert(DT.predict({0, 1, 1}));
    assert(not DT.predict({0, 0, 1}));

    return 0;
}
