// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


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

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
