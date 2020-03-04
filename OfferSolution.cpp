//
// Created by Jian Wu on 04/03/2020.
//

#include "OfferSolution.h"

int OfferSolution::findRepeatNumber(vector<int> &nums) {
    vector<int> ans(nums.size(), -1);

    for (int i = 0; i < nums.size(); ++i) {
        if (ans[nums[i]] != -1) return nums[i];
        ans[nums[i]] = i;
    }

    return 0;
}