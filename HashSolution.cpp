//
// Created by Jian Wu on 19/05/2020.
//

#include "HashSolution.h"

int HashSolution::subarraySum(vector<int> &nums, int k)
{
	int count = 0, prev = 0;
	map<int, int> mp;
	mp.insert({0, 1});

	for (int i = 0; i < nums.size(); ++i)
	{
		prev += nums[i];

		if (mp.find(prev) == mp.end())
			mp.insert({prev, 1});
		else
			mp[prev]++;

		if (mp.find(prev - k) != mp.end())
			count += mp[prev - k];
	}

	return count;
}