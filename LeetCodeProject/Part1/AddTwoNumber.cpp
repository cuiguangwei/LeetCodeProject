#include "stdafx.h"
#include "AddTwoNumber.h"


AddTwoNumber::AddTwoNumber()
{
}


AddTwoNumber::~AddTwoNumber()
{
}

/*
���������±������ӣ�ע���λcarry��ֱ����������Ϊ�գ�ע��һ������Ľ�λ��Ȼ��ȥ����һ���ڵ�-1���ɡ�
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