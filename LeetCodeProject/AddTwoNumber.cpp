#include "stdafx.h"
#include "AddTwoNumber.h"


AddTwoNumber::AddTwoNumber()
{
}


AddTwoNumber::~AddTwoNumber()
{
}

/*
根据链表下标逐次相加，注意进位carry，直到两个链表都为空，注意一次运算的进位，然后去掉第一个节点-1即可。
*/
ListNode* AddTwoNumber::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* res = new ListNode(-1), *cur = res;

	int carry = 0;
	while (l1 || l2)
	{
		int val1 = l1 ? l1->val : 0;
		int val2 = l2 ? l2->val : 0;
		int sum = val1 + val2 + carry;
		carry = sum / 10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	if (carry) cur->next = new ListNode(1);

	return res->next;
}