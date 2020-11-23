//
// Created by Jian Wu on 22/02/2020.
//

#ifndef LEETCODE_DYNAMICPROGRAMMINGSOLUTION_H
#define LEETCODE_DYNAMICPROGRAMMINGSOLUTION_H

#include "Common.h"
#include <string>
#include <vector>
#include <queue>
#include <memory>

using std::shared_ptr;
using std::vector;
using std::greater;
using std::string;
using std::priority_queue;

using namespace std;

class DynamicProgrammingSolution {
public:
    static int maxSubArray(vector<int>& nums);
    int maxProduct(vector<int>& nums); // LeetCode 152
    static int minPathSum(vector<vector<int>>& grid); // LeetCode 64
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
    static int rob(vector<int>& nums); // LeetCode 198
    static int robInCircle(vector<int>& nums); // LeetCode 213
    bool wordBreak(const string& s, vector<string>& wordDict); // LeetCode 139
    int lengthOfLIS(vector<int>& nums); // LeetCode 300
    int lengthOfLIS(vector<int>& nums, bool useBinarySeaarch); // LeetCode 300 O(n * log(n))
    int maxProfit(vector<int>& prices); // LeetCode 121;
    static int maxProfitWithMultiTransactions(vector<int>& prices); // LeetCode 122
    static int longestCommonSubsequence(string text1, string text2); // 1143
    int findLength(vector<int>& A, vector<int>& B); //718
    static vector<string> generateParenthesis(int n); // 22
    static vector<vector<int>> permute(vector<int>& nums); // 46
    static vector<vector<int>> permuteUnique(vector<int>& nums); // 47
	int nthUglyNumber(int n); // 264
	int nthUglyNumber(int n, bool useMinHeap = true);
	int maximalSquare(vector<vector<char>>& matrix); //221
	int countNumbersWithUniqueDigits(int n); // 357
	int fib(int n); // 509
	int largest1BorderedSquare(vector<vector<int>>& grid); // 1139
	int waysToChange(int n); // 08。11
//	vector<int> findSquare(vector<vector<int>>& matrix); // 17.23
	bool canIWin(int maxChoosableInteger, int desiredTotal); // 464
	int findMaxForm(vector<string>& strs, int m, int n); // 474
};


#endif //LEETCODE_DYNAMICPROGRAMMINGSOLUTION_H
