//
// Created by Jian Wu on 22/02/2020.
//

#ifndef LEETCODE_DYNAMICPROGRAMMINGSOLUTION_H
#define LEETCODE_DYNAMICPROGRAMMINGSOLUTION_H

#include "Common.h"
#include <string>
#include <vector>

using namespace std;

class DynamicProgrammingSolution {
public:
    int maxSubArray(vector<int>& nums);
    int maxProduct(vector<int>& nums); // LeetCode 152
    int minPathSum(vector<vector<int>>& grid); // LeetCode 64
    int minimumTotal(vector<vector<int>>& triangle); // LeetCode 120;
    int findLongestChain(vector<vector<int>>& pairs); // LeetCode 646;
    vector<vector<int>> findSubsequences(vector<int>& nums); // LeetCode 491;
    bool canPartition(vector<int>& nums); // LeetCode 416
    int numDecodings(string s); // LeetCode 91
    vector<TreeNode*> generateTrees(int n); // LeetCode 95
    int numSquares(int n);
    int countPrimes(int n);
    int lenLongestFibSubseq(vector<int>& A);
    int integerBreak(int n); // LeetCode 343;
    vector<int> countBits(int num); // LeetCode 338;
    int rob(vector<int>& nums); // LeetCode 198
    int robInCircle(vector<int>& nums); // LeetCode 213
    bool wordBreak(string s, vector<string>& wordDict); // LeetCode 139
    int lengthOfLIS(vector<int>& nums); // LeetCode 300
};


#endif //LEETCODE_DYNAMICPROGRAMMINGSOLUTION_H
