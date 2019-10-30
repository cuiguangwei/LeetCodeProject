#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class RemoveListNodeFromEnd
{
public:
	RemoveListNodeFromEnd();
	~RemoveListNodeFromEnd();


	ListNode * removeNthFromEnd(ListNode * head, int n);

};

