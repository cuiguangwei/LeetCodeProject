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
	if (!head || !head->next) return nullptr;//排除特殊临界情况

	ListNode *pre = head, *cur = head;
	for (int i = 0; i < n; ++i) {
		cur = cur->next;//标尺右端后移
	}
	if (!cur)//如果cur为空，则表示链表长度就是n，移除首元素返回next即可
		return head->next;
	while (cur->next) {
		cur = cur->next;
		pre = pre->next;
	}
	pre->next = pre->next->next;

	return head;
}