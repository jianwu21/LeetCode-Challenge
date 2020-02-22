//
// Created by Jian Wu on 22/02/2020.
//
#include <algorithm>

#include "DynamicProgrammingSolution.h"


int DynamicProgrammingSolution::maxSubArray(vector<int> &nums)
{
    vector<int> dp;
    dp.push_back(nums.front());

    for (int i = 1; i < nums.size(); ++i) {
        if (dp[i-1] < 0)
            dp.push_back(nums[i]);
        else
            dp.push_back(dp[i-1]+nums[i]);
    }

    return *max_element(dp.begin(), dp.end());
}

int DynamicProgrammingSolution::maxProduct(vector<int> &nums) {
    return 0;
}

int DynamicProgrammingSolution::minPathSum(vector<vector<int> > &grid) {
    if (grid.empty()) return 0;

    for (int i = 1; i < grid[0].size(); ++i) {
        grid[0][i] += grid[0][i-1];
    }

    for (int i = 1; i < grid.size(); ++i) {
        grid[i][0] += grid[i-1][0];
    }

    for (int i = 1; i < grid[0].size(); ++i) {
        for (int j = 1; j < grid.size(); ++j) {
            grid[j][i] += min(grid[j-1][i], grid[j][i-1]);
        }
    }

    return grid.back().back();
}

int DynamicProgrammingSolution::minimumTotal(vector<vector<int>>& triangle)
{
//    if (triangle.empty()) return 0;
//
//    for (int row = 1; row < triangle.size(); ++row) {
//        triangle[row].front() += triangle[row-1].front();
//        triangle[row].back() += triangle[row-1].back();
//
//        for (int col = 1; col < triangle[row].size() - 1; ++col) {
//            triangle[row][col] += min(triangle[row-1][col-1], triangle[row-1][col]);
//        }
//    }
//    return *min_element(triangle.back().begin(), triangle.back().end());
    if (triangle.empty()) return 0;
    int numOfRows = triangle.size();

    for (int row = numOfRows - 2; row >= 0 ; --row) {
        for (int col = 0; col < triangle[row].size(); ++col) {
            triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        }
    }

    return triangle.front().front();
}

int DynamicProgrammingSolution::findLongestChain(vector<vector<int> > &pairs) {

}