#pragma once



class MergeKLists
{
public:
	MergeKLists();
	~MergeKLists();

	ListNode * mergeKLists(vector<ListNode*>& lists);
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2);
};

