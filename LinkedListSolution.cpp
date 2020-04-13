//
// Created by Jian Wu on 22/02/2020.
//

#include "LinkedListSolution.h"

ListNode * LinkedListSolution::deleteNode(ListNode *head, int val)
{
	ListNode* dump = new ListNode(0);
	dump->next = head;

	ListNode *front = dump, *back = head;

	while (back)
	{
		if (back->val == val)
		{
			front->next = back->next;
			break;
		}
		front = front->next;
		back = back->next;
	}

	return dump->next;
}
