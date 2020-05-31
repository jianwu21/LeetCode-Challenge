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

		if (mp.find(prev - k) != mp.end())
			count += mp[prev - k];

		if (mp.find(prev) != mp.end())
			mp[prev] = mp[prev] + 1;
		else
			mp.insert({prev, 1});
	}

	return count;
}

bool HashSolution::checkSubarraySum(vector<int> &nums, int k)
{
	int prev = 0, mod = 0, sum = nums[0];

	map<int, int> mp = {pair<int, int>{0, 1}};

	for (int i = 1; i < nums.size(); ++i)
	{
		prev += nums[i-1];
		sum += nums[i];

		if(k)
		{
			prev = prev % k;
			mod = sum % k;
		}
		else
			mod = sum;

		if (mp.find(mod) != mp.end())
			return true;

		if (mp.find(prev) == mp.end())
			mp.insert({prev, 1});

		int a = nums[1] ^ nums[2];
	}

	return false;
}
