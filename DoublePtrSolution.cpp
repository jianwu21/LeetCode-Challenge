//
// Created by Jian Wu on 12/04/2020.
//

#include "DoublePtrSolution.h"


void DoublePtrSolution::moveZeros(vector<int> &nums)
{
	int lastNonZero = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
			nums[lastNonZero++] = nums[i];
	}

	for (int j = lastNonZero; j < nums.size(); ++j)
	{
		nums[j] = 0;
	}
}

int DoublePtrSolution::removeDuplicates(vector<int> &nums)
{
	if (nums.empty()) return 0;

	vector<int> tmp;
	tmp.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != tmp.back())
		{
			tmp.push_back(nums[i]);
		}
	}

	nums = tmp;

	return nums.size();
}