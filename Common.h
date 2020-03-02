//
// Created by Jian Wu on 26/02/2020.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <iostream>

typedef struct ListNode{
    int val;
    ListNode* next;

    ListNode() : next(nullptr)
    {}
} ListNode;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

#endif //LEETCODE_COMMON_H
