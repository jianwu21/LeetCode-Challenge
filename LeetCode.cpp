#include <iostream>

#include "DynamicProgrammingSolution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DynamicProgrammingSolution dps;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    auto maxSubArray = dps.maxSubArray(nums);

    vector<vector<int >> grid = {
        {1, 2, 5},
        {3, 2, 1},
    };
    auto minPath = dps.minPathSum(grid);

    vector<vector<int>> triangle = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    auto miniTotal = dps.minimumTotal(triangle);

    return 0;
}


