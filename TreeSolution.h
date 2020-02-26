//
// Created by Jian Wu on 22/02/2020.
//

#ifndef LEETCODE_TREESOLUTION_H
#define LEETCODE_TREESOLUTION_H

#include <queue>
#include <vector>

#include "Common.h"

using namespace std;


inline TreeNode* CreateBT(vector<int>& _vec);

class TreeSolution {
    int rangeSumBST(TreeNode* root, int L, int R); // LeetCode 938
};


#endif //LEETCODE_TREESOLUTION_H
