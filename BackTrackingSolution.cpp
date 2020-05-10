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

void BackTrackingSolution::dfs(vector<int> &nums, int target, int pos, int iter)
{
	if (iter == 4)
	{
		if (target == 0)
		{
			paths.push_back(path);
		}

		return;
	}

	if (pos > 0 && nums[pos] == nums[pos-1])
		return;

	for (int i = pos; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		dfs(nums, target-nums[i], i+1, iter+1);
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
	std::vector<string> times;
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

vector<string> BackTrackingSolution::letterCasePermutation(string S)
{
	deque<string> strs;
	strs.push_back("");

	for (int i = 0; i < S.size(); ++i)
	{
		while (strs.front().size() == i)
		{
			auto current = strs.front();
			strs.pop_front();
			strs.push_back(current + S[i]);

			if (isalpha(S[i]))
			{
				S[i] ^= 32;
				strs.push_back(current + S[i]);
			}
		}
	}

	vector<string> ans;

	for (const auto& str : strs)
	{
		ans.push_back(str);
	}

	return ans;
}

vector<vector<int> > BackTrackingSolution::fourSum(vector<int> &nums, int target)
{
	sort(nums.begin(), nums.end());
	dfs(nums, target, 0, 0);

	return paths;
}
