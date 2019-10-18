#pragma once


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x),
		next(NULL)
	{

	}
};

class AddTwoNumber
{
public:
	AddTwoNumber();
	~AddTwoNumber();
	ListNode* addTwoNumbers(ListNode * l1, ListNode * l2);
};

