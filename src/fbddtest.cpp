#include "FBDD.h"

#include <iostream>

int main()
{
    const auto T = FNode::TRUE;
    const auto F = FNode::FALSE;
    const auto n = std::make_shared<FNode>(1, F, T);
    const auto n2 = std::make_shared<FNode>(2, F, n);
    const auto n3 = std::make_shared<FNode>(2, T, F);
    const auto n4 = std::make_shared<FNode>(0, n2, n3);
    /*
     *            0
     *          /    \
     *         2      2
     *        / \    /  \
     *        |  1  T    F
     *         | / \
     *          F   T
     *
     *
     *
     */
    const FBDD f {n4};

    assert(f.predict({1, 0, 0}));
    assert(f.predict({1, 1, 0}));
    assert(not f.predict({1, 1, 1}));
    assert(not f.predict({0, 1, 0}));
    assert(f.predict({0, 1, 1}));
    assert(not f.predict({0, 0, 1}));

    //assert(not NDT.predict({1, 0, 0}));
    //assert(not NDT.predict({1, 1, 0}));
    //assert(NDT.predict({1, 1, 1}));
    //assert(NDT.predict({0, 1, 0}));
    //assert(not NDT.predict({0, 1, 1}));
    //assert(NDT.predict({0, 0, 1}));

    return 0;
}
