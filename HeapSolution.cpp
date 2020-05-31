//
// Created by Jian Wu on 24/05/2020.
//

#include "HeapSolution.h"

vector<int> HeapSolution::smallestK(vector<int> &arr, int k)
{
	vector<int> ans;
	priority_queue<int> ipq;

	for (int& i : arr)
	{
		ipq.push(i);
		if (ipq.size() > k) ipq.pop();
	}

	while (!ipq.empty())
	{
		ans.push_back(ipq.top());
		ipq.pop();
	}

	return ans;
}