//
// Created by Jian Wu on 22/02/2020.
//

#ifndef LEETCODE_LINKEDLISTSOLUTION_H
#define LEETCODE_LINKEDLISTSOLUTION_H

#include <vector>
#include <stack>
#include "Common.h"

using namespace std;

class LinkedListSolution {
public:
	ListNode* deleteNode(ListNode* head, int val);
	vector<int> reversePrint(ListNode* head);
	ListNode* reverseList(ListNode* head);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};


#endif //LEETCODE_LINKEDLISTSOLUTION_H
