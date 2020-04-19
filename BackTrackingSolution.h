//
// Created by Jian Wu on 19/04/2020.
//

#ifndef LEETCODE__BACKTRACKINGSOLUTION_H
#define LEETCODE__BACKTRACKINGSOLUTION_H

#include<vector>
#include<string>

using namespace std;

struct Timer
{
	int hour;
	int min;

	Timer(int hour_, int min_) : hour(hour_), min(min_) {}
};

class BackTrackingSolution
{
private:
	vector<int> path;
	vector<vector<int>> paths;

	void dfs(vector<int>& nums, int target, int pos);

	vector<int> scales = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

	vector<string> ans = {"0:03","0:05","0:06","0:09","0:10","0:12","0:17","0:18","0:20","0:24","0:33","0:34","0:36","0:40","0:48","1:01","1:02","1:04","1:08","1:16","1:32","2:01","2:02","2:04","2:08","2:16","2:32","3:00","4:01","4:02","4:04","4:08","4:16","4:32","5:00","6:00","8:01","8:02","8:04","8:08","8:16","8:32","9:00","10:00"};

	void dfsC(int n, int pos, int k);
	Timer scalesToTime(vector<int> scaleIndexes);
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	vector<vector<int>> combine(int n, int k);
	vector<string> readBinaryWatch(int num);
};

#endif //LEETCODE__BACKTRACKINGSOLUTION_H
