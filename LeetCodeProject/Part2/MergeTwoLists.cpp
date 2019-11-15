#include "stdafx.h"
#include "MergeTwoLists.h"


MergeTwoLists::MergeTwoLists()
{
}


MergeTwoLists::~MergeTwoLists()
{
}

//ListNode* MergeTwoLists::mergeTwoLists(ListNode *l1, ListNode *l2)
//{
//	if (!l1 || (l2 && l1->val > l2->val)) swap(l1, l2);
//	if (l1) l1->next = mergeTwoLists(l1->next, l2);
//	return l1;
//}

//ListNode* MergeTwoLists::mergeTwoLists(ListNode *l1, ListNode *l2)
//{
//	if (!l1) return l2;
//	if (!l2) return l1;
//	if (l1->val < l2->val) {
//		l1->next = mergeTwoLists(l1->next, l2);
//		return l1;
//	}
//	else {
//		l2->next = mergeTwoLists(l1, l2->next);
//		return l2;
//	}
//}

ListNode* MergeTwoLists::mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *ret = new ListNode(-1), *cur = ret;//cur作为中间量，每次给ret添入一个值

	while (l1 && l2)
	{
		if (l1->val < l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = l1 ? l1 : l2;
	return ret->next;

}