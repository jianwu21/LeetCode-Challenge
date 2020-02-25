#include <iostream>

#include "DynamicProgrammingSolution.h"
#include "MathSolution.h"
#include "FunSolution.h"


void RunDynamicProgrammingQuestions()
{
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

    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    auto longestChain = dps.findLongestChain(pairs);

    vector<int> sortedNums = {4, 6, 7, 7};
    auto subSequences = dps.findSubsequences(sortedNums);
}

void MathTest()
{
    MathSolution ms;

    auto sqrtX = ms.mySqrt(4);
}

void FunTest()
{
    FunSolution fc;
    vector<vector<char>> map1 = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };

    vector<vector<int >> grid = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1}
    };

    vector<vector<int >> grid2 = {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}
    };

    auto numOfIslands = fc.numIslands(map1);
    auto maxArea = fc.maxAreaOfIsland(grid);
    auto numOfStripes = fc.islandPerimeter(grid2);
}

int main() {
    std::cout << 'Test, Begin!' << std::endl;

//    RunDynamicProgrammingQuestions();

//    MathTest();
    FunTest();
    std::cout << 'Test, End!' << std::endl;
    return 0;
}



