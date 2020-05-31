/*
 * Some funny questions in LeetCode, which I
 * dont know which kind of type it should belong
 * to.
 */
#ifndef LEETCODE_FUNSOLUTION_H
#define LEETCODE_FUNSOLUTION_H

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FunSolution {
public:
    int islandPerimeter(vector<vector<int>>& grid); // LeetCode 463
    int numIslands(vector<vector<char>>& grid); // LeetCode 200
    int maxAreaOfIsland(vector<vector<int>>& grid); // LeetCode 695
	double myPow(double x, int n); // LeetCode 50
	int totalHammingDistance(vector<int>& nums); // LeetCode 477
	string reverseWords(string s); // LeetCode 557
	string reverseStr(string s, int k); // LeetCode 541
	int strStr(string haystack, string needle); // LeetCode 28
	int smallestRepunitDivByK(int K); // LeetCode 1015
};


#endif //LEETCODE_FUNSOLUTION_H
