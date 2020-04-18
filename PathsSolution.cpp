//
// Created by Jian Wu on 19/04/2020.
//

#include "PathsSolution.h"

void PathsSolution::dfs(vector<int> &nums, int target, int pos)
{
	if (target == 0)
	{
		paths.push_back(path);
		return;
	}

	if (target < 0)
		return;

	for (int i = pos; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		dfs(nums, target-nums[i], i);

		path.pop_back();
	}
}

vector<vector<int> > PathsSolution::combinationSum(vector<int> &candidates, int target)
{
	dfs(candidates, target, 0);

	return paths;
}
