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

vector<int> LinkedListSolution::reversePrint(ListNode *head)
{
	stack<int> s;
	ListNode* ptr = head;

	while(ptr)
	{
		s.push(ptr->val);
		ptr = ptr->next;
	}

	vector<int> ans;
	while(!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}

	return ans;
}

ListNode * LinkedListSolution::reverseList(ListNode *head)
{
	if (!head) return head;

	ListNode* p_Prev = NULL, *p_Cur = head, *p_Next;

	while(p_Cur)
	{
		p_Next = p_Cur->next;
		p_Cur->next = p_Prev;
		p_Prev = p_Cur;
		p_Cur = p_Next;
	}

	return p_Prev;
}

ListNode * LinkedListSolution::mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* dump = new ListNode(INT_MIN);
	dump->next = l1;
	ListNode* front = dump, *back = l1, *insert = l2;

	while (true)
	{
		while (back && (insert->val > back->val))
		{
			front = front->next;
			back = back->next;
		}

		front->next = insert;

		if (!back)
			break;

		while (insert && (insert->val < back->val))
		{
			front = front->next;
			insert = insert->next;
		}

		front->next = back;

		if (!insert)
			break;

		front = back;
		back = back->next;
	}

	return dump->next;
}
