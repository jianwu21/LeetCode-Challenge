//
// Created by Jian Wu on 03/03/2020.
//

#include "EasySolution.h"
#include <unordered_map>
#include <unordered_set>

bool EasySolution::uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> mapArr;

    for (const int& num : arr) mapArr[num]++;

    vector<int> checked;

    for (auto itr = mapArr.begin(); itr != mapArr.end(); ++itr) {
       for (const int& checkNum : checked)
       {
           if (checkNum == itr->second) return false;
       }
       checked.push_back(itr->second);
    }

    return true;
}

bool EasySolution::containsDuplicate(vector<int> &nums) {
    if (nums.size() <= 1) return false;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i-1]) return true;
    }

    return false;
}

bool EasySolution::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> pos;

    for (int i = 0; i < nums.size(); ++i) {
        if (pos[nums[i]] != 0) pos[nums[i]] = i - pos[nums[i]];
        if (pos[nums[i]] != 0 && pos[nums[i]] <= k) return true;
    }

    return false;
}

bool EasySolution::isUnique(string astr) {
    unordered_set<char> checked;

    sort(astr.begin(), astr.end());
    for (const auto& s : astr) {
        if (checked.find(s) != checked.end()) return false;
        checked.insert(s);
    }

    return true;
}