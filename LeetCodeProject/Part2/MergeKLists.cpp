#include "stdafx.h"
#include "MergeKLists.h"
#include <queue>

MergeKLists::MergeKLists()
{
}


MergeKLists::~MergeKLists()
{
}

ListNode* MergeKLists::mergeKLists(vector<ListNode*>& lists) {
	auto cmp = [](ListNode*& a, ListNode*& b) {
		return a->val > b->val;
	};
	priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
	for (auto node : lists) {
		if (node) q.push(node);
	}
	ListNode *dummy = new ListNode(-1), *cur = dummy;
	while (!q.empty()) {
		auto t = q.top(); q.pop();
		cur->next = t;
		cur = cur->next;
		if (cur->next) q.push(cur->next);
	}
	return dummy->next;
}

//解法一：
//ListNode* MergeKLists::mergeKLists(vector<ListNode*>& lists) {
//	if (lists.empty()) return nullptr;
//
//	int n = lists.size();
//	while (n > 1)
//	{
//		int k = (n + 1) / 2;
//		for (int i = 0; i < n / 2; ++i)
//		{
//			lists[i] = mergeTwoLists(lists[i], lists[i + k]);
//		}
//		n = k;
//	}
//	return lists[0];
//}
//
//ListNode* MergeKLists::mergeTwoLists(ListNode *l1, ListNode *l2)
//{
//	ListNode *ret = new ListNode(-1), *cur = ret;//cur作为中间量，每次给ret添入一个值
//
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val) {
//			cur->next = l1;
//			l1 = l1->next;
//		}
//		else {
//			cur->next = l2;
//			l2 = l2->next;
//		}
//		cur = cur->next;
//	}
//	cur->next = l1 ? l1 : l2;
//	return ret->next;
//
//}

