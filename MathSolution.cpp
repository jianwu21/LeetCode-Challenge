//
// Created by Jian Wu on 23/02/2020.
//

#include "MathSolution.h"
#include <algorithm>

#define EPSILON 0.00001

int MathSolution::mySqrt(int x) {
    /**
     * Newton's method:
     * x_(n+1) = x_n - f(x) / f'(x)
     */
    int r = x;

    while (std::abs(r * r - x) > EPSILON)
    {
        r = (r * r + x) / (2 * r);
    }

    return r;
}