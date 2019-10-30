#include "stdafx.h"
#include "RemoveListNodeFromEnd.h"


RemoveListNodeFromEnd::RemoveListNodeFromEnd()
{
}


RemoveListNodeFromEnd::~RemoveListNodeFromEnd()
{
}

ListNode* RemoveListNodeFromEnd::removeNthFromEnd(ListNode* head, int n) 
{
	if (!head || !head->next) return nullptr;//�ų������ٽ����

	ListNode *pre = head, *cur = head;
	for (int i = 0; i < n; ++i) {
		cur = cur->next;//����Ҷ˺���
	}
	if (!cur)//���curΪ�գ����ʾ�����Ⱦ���n���Ƴ���Ԫ�ط���next����
		return head->next;
	while (cur->next) {
		cur = cur->next;
		pre = pre->next;
	}
	pre->next = pre->next->next;

	return head;
}