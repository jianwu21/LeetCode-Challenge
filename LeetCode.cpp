#include <iostream>

#include "DynamicProgrammingSolution.h"
#include "MathSolution.h"
#include "FunSolution.h"
#include "SortAlgorithm.h"


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

    vector<int> bag = {1, 5, 11, 5};
    auto canPartition = dps.canPartition(bag);

    string s = "0";
    auto ans = dps.numDecodings(s);

    vector<int> nums2 = { -2, 0, -1};
    auto maxProduct = dps.maxProduct(nums2);

    auto numSquare = dps.numSquares(12);
//    auto countPrime = dps.countPrimes(3);
    auto maxBreakProduct = dps.integerBreak(8);

    vector<int> houses = {2,7,9,3,1};
    auto maxValue = dps.rob(houses);

    maxValue = dps.robInCircle(houses);

    vector<string> wordDict = {"leet", "code"};
    auto isWordBreak = dps.wordBreak("leetcode", wordDict);

    nums = {10,9,2,5,3,7,101,18,19,16};
    auto lengthOfLIS = dps.lengthOfLIS(nums);

    auto countBits = dps.countBits(2);
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

void SortTest()
{
    SortAlgorithm sa;
    int a[7] = {3, 4, 1, 98, 32, 54, 6};
    sa.quickSort(a, 0, 6);
}

int main() {
    std::cout << 'Test, Begin!' << std::endl;

    RunDynamicProgrammingQuestions();

//    MathTest();
//    FunTest();

//    SortTest();
    std::cout << 'Test, End!' << std::endl;
    return 0;
}



