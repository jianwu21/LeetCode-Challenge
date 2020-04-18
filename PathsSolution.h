//
// Created by Jian Wu on 19/04/2020.
//

#ifndef LEETCODE__PATHSSOLUTION_H
#define LEETCODE__PATHSSOLUTION_H

#include<vector>

using namespace std;

class PathsSolution
{
private:
	vector<int> path;
	vector<vector<int>> paths;

	void dfs(vector<int>& nums, int target, int pos);
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

#endif //LEETCODE__PATHSSOLUTION_H
