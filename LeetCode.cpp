#include <iostream>

#include "DoublePtrSolution.h"
#include "DynamicProgrammingSolution.h"
#include "MathSolution.h"
#include "FunSolution.h"
#include "BackTrackingSolution.h"
#include "StackSolution.h"
#include "SortAlgorithm.h"
#include "LinkedListSolution.h"
#include "HashSolution.h"

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

    auto longest = dps.longestCommonSubsequence("abc", "def");

    vector<int> insertList = { 1, 1, 2, 2};
    auto permute = dps.permuteUnique(insertList);

    grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = dps.largest1BorderedSquare(grid);

    auto ways = dps.waysToChange(10);

    // 474
	vector<string> strs = {"10", "0001", "111001", "1", "0"};
	int maxForm = dps.findMaxForm(strs, 5, 3);
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

    auto s = "Let's take LeetCode contest";
	auto ansS = fc.reverseWords(s);

	auto rS = fc.reverseStr("abcdefg", 2);
}

void SortTest()
{
    SortAlgorithm sa;
    int a[7] = {3, 4, 1, 98, 32, 54, 6};
    sa.quickSort(a, 0, 6);
}

void HashSolutionTest()
{
	HashSolution hs;

	vector<int> nums = {1, 2, 1, 2, 3};
	auto ans = hs.subarraySum(nums, 3);

	vector<int> nums2 = {23,2,4,6,7};
	auto ans2 = hs.checkSubarraySum(nums2, -6);
}

void StackSolutionTest()
{
	StackSolution ss;
	string preOrder = "9,#,92,#,#";

	auto isValidBT = ss.isValidSerialization(preOrder);
}

void DoublePtrSolutionTest()
{
	DoublePtrSolution ds;
	vector<int> test = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

	int uni = ds.removeDuplicates(test);
}

void DFSPathTest()
{
	BackTrackingSolution ps;
//	vector<int> nums = { 2, 3, 6, 7};
//	auto ans = ps.combinationSum(nums, 7);

//	auto com = ps.combine(4, 2);

//	auto watches = ps.readBinaryWatch(2);

//	auto ans = ps.letterCasePermutation("a1b2");

	vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
	auto ans = ps.fourSum(nums, 0);
}

void LinkedListTest()
{
	auto l1 = new ListNode(1);

	auto l2 = new ListNode(2);
	l1->next = l2;

	auto l3 = new ListNode(4);
	l2->next = l3;

	auto r1 = new ListNode(1);

	auto r2 = new ListNode(3);
	r1->next = r2;

	auto r3 = new ListNode(4);
	r2->next = r3;

	LinkedListSolution lls;

	auto m = lls.mergeTwoLists(l1, r1);
}

int main() {
    std::cout << "Test, Begin!" << std::endl;

    RunDynamicProgrammingQuestions();
//    MathTest();
//    FunTest();

//    SortTest();

//	StackSolutionTest();

//	DoublePtrSolutionTest();

//	DFSPathTest();

//	LinkedListTest();

//	HashSolutionTest();

    std::cout << "Test, End!" << std::endl;
    return 0;
}



