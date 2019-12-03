#include "stdafx.h"
#include "SortList.h"
#include <map>

using namespace std;

SortList::SortList()
{
}


SortList::~SortList()
{
}

ListNode* SortList::sortList(ListNode* head) {
	if (!head) return nullptr;
	ListNode* res = new ListNode(-1);

	map<int, ListNode*> map;


	//while (head->next) {
	//	map.insert(head->val, head);
	//}

	return res;
}