/*
 * Some funny questions in LeetCode, which I
 * dont know which kind of type it should belong
 * to.
 */
#ifndef LEETCODE_FUNSOLUTION_H
#define LEETCODE_FUNSOLUTION_H

#include <vector>

using namespace std;

class FunSolution {
public:
    int islandPerimeter(vector<vector<int>>& grid); // LeetCode 463
    int numIslands(vector<vector<char>>& grid); // LeetCode 200
    int maxAreaOfIsland(vector<vector<int>>& grid); // LeetCode 695
	double myPow(double x, int n); // LeetCode 50
};


#endif //LEETCODE_FUNSOLUTION_H
