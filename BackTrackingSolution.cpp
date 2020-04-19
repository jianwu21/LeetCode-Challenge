//
// Created by Jian Wu on 19/04/2020.
//

#include "BackTrackingSolution.h"

void BackTrackingSolution::dfs(vector<int> &nums, int target, int pos)
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

vector<vector<int> > BackTrackingSolution::combinationSum(vector<int> &candidates, int target)
{
	dfs(candidates, target, 0);

	return paths;
}

void BackTrackingSolution::dfsC(int n, int pos, int k)
{
	if (k == 0)
	{
		paths.push_back(path);
		return;
	}

	if (pos + k - 1 > n)
		return;

	for (int i = pos; i < n+1; ++i)
	{
		path.push_back(i);
		dfsC(n, i+1, k-1);
		path.pop_back();
	}

}

vector<vector<int> > BackTrackingSolution::combine(int n, int k)
{
	dfsC(n, 1, k);

	return paths;
}

Timer BackTrackingSolution::scalesToTime(vector<int> scaleIndexes)
{
	int hours = 0, minutes = 0;
	for (const int scaleIndex : scaleIndexes)
	{
		if (scaleIndex <=  4) hours += scales[scaleIndex-1];
		else minutes += scales[scaleIndex-1];
	}

	return Timer(hours, minutes);
//	return to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
}

vector<string> BackTrackingSolution::readBinaryWatch(int num)
{

	vector<string> times;
	int n = scales.size();
	auto scaleIndexes = combine(n, num);

	for (auto& scaleIndex : scaleIndexes)
	{
		Timer timer = scalesToTime(scaleIndex);
		if (timer.hour >= 12 || timer.min > 59)
			continue;
		times.push_back(
			to_string(timer.hour) + ":" + (timer.min < 10 ? "0" : "") + to_string(timer.min));
	}

	auto a = ans;

	return times;
}
