//
// Created by Jian Wu on 24/02/2020.
//

#include "FunSolution.h"
#include <queue>
#include <cstdlib>

void infect(vector<vector<char>>& grid, const int& i, const int& j, int w, int h)
{
    if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != '1')
        return;

    grid[i][j] = '0';
    infect(grid, i+1, j, w, h);
    infect(grid, i-1, j, w, h);
    infect(grid, i, j+1, w, h);
    infect(grid, i, j-1, w, h);
}

void infect(vector<vector<int>>& grid, const int& i, const int& j, const int& w, int h, int& area)
{
    if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != 1)
        return;

    grid[i][j] = 0;
    area++;
    infect(grid, i+1, j, w, h, area);
    infect(grid, i-1, j, w, h, area);
    infect(grid, i, j+1, w, h, area);
    infect(grid, i, j-1, w, h, area);
}

int FunSolution::numIslands(vector<vector<char>>& grid) {
    // DFS solution
    if (grid.empty())
        return 0;

    int rows = grid.size(), cols = grid.front().size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1') {
                infect(grid, i, j, cols, rows);
                count++;
            }
        }
    }

    return count;
}

int FunSolution::maxAreaOfIsland(vector<vector<int> > &grid) {
    if (grid.empty()) return  0;
    int maxArea = 0;

    int rows = grid.size(), cols = grid.front().size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                int area = 0;
                infect(grid, i, j, cols, rows, area);

                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int FunSolution::islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    const int rows = grid.size();
    const int cols = grid.front().size();
    int numOfStripes = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                numOfStripes += 4;
                int left = j - 1, up = i - 1;
                if (left >= 0 && grid[i][left] == 1) numOfStripes -= 2;
                if (up >= 0 && grid[up][j] == 1) numOfStripes -= 2;
            }
        }
    }

    return numOfStripes;
}

double FunSolution::myPow(double x, int n) {
	double pow = 1.0;
	long exp = abs((long)n);
	while (exp)
	{
		if ((exp & 1) == 1) pow *= x;
		exp >>= 1;
		x *= x;
	}

	return n > 0 ? pow : 1/pow;
}

int FunSolution::totalHammingDistance(vector<int> &nums)
{
	vector<int> ones(32, 0);
	int count = 0;

	for (auto& num : nums)
	{
		int i = 0;

		while (num)
		{
			ones[i++] += (num & 1);
			num >>= 1;
		}
	}

	for (const auto& one : ones)
	{
		count += one * (nums.size() - one);
	}

	return count;
}

string FunSolution::reverseWords(string s)
{
//	string word = "", ans = "";
//
//	for (const char& c : s)
//	{
//		if (c == ' ')
//		{
//			ans += word;
//			ans += ' ';
//			word = "";
//		}
//		else
//			word = c + word;
//	}
//	ans += word;
//
//	return ans;

// using sstream

	istringstream ss(s);
	string str, ans;

	while (ss >> str)
	{
		reverse(str.begin(), str.end());
		ans += str + ' ';
	}

	return ans.substr(0, ans.length()-1);
}

string FunSolution::reverseStr(string s, int k)
{
	string::iterator front = s.begin();
	int index = 0;
	bool reversed = false;

	for (string::iterator it = s.begin(); it != s.end(); ++it)
	{
		if (index == 2 * k)
		{
			front = it;
			index = 0;
			reversed = false;
		}

		if (index == k)
		{
			reverse(front, it);
			reversed = true;
		}

		index++;
	}

	if (!reversed) reverse(front, s.end());

	return s;
}

int FunSolution::strStr(string haystack, string needle)
{
	for (int i = 0; i < haystack.length(); ++i)
	{
		if (haystack[i] == needle[0])
		{
			if (haystack.substr(i, needle.length()) == needle)
				return i;
		}
	}

	return -1;
}

int FunSolution::smallestRepunitDivByK(int K)
{
	if (!(K & 1)) return -1;
	int num = 1, count = 1;
	while (num <= INT_MAX)
	{
		if (num % K == 0)
			return count;

		num = num * 10 + 1;
		count++;
	}

	return -1;
}

void nextPermutation(vector<int>& nums) {
    int end = nums.size() - 2;
    int i = end;

    while (i >= 0 && nums[i] >= nums[i+1]) {
        --i;
    }

    if (i >= 0){
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

int nthUglyNumber(int n) {
    vector<int> dp(n + 1, 1);

    int index2 = 1, index3 = 1, index5 = 1;
    for (int i = 2; i < n+1; ++i) {
        int num2 = dp[index2] * 2, num3 = dp[index3] * 3, num5 = dp[index5] * 5;

        dp[i] = min(min(num2, num3), num5);

        if (dp[i] == num2) index2++;
        if (dp[i] == num3) index3++;
        if (dp[i] == num5) index5++;
    }

    return dp[n];
}

