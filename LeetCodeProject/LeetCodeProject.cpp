// LeedCodeProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include <algorithm>
#include <Windows.h>
#include <vector>
#include <iostream>

#include "AddTwoNumber.h"
#include "LengthOfLongestSubstring.h"
#include "FindMedianSortedArrays.h"
#include "LongestPalindrome.h"
#include "intReverse.h"
#include "StringAtoi.h"
#include "Palindrome.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//�������
	AddTwoNumber tn;
	ListNode l1(5);
	ListNode l2(5);
	ListNode l3(5);
	l1.next = &l2;
	l2.next = &l3;
	cout << tn.addTwoNumbers(&l1, &l1);

	//������ظ��Ӵ�
	LengthOfLongestSubstring ls;
	ls.lengthOfLongestSubstring("pwwkew");

	//Ѱ�����������������λ��
	FindMedianSortedArrays fsa;

	vector<int> nums1{1,2,3};
	vector<int> nums2{6,8};
	double a = fsa.findMedianSortedArrays(nums1, nums2);

	//������Ӵ�
	LongestPalindrome lp;
	string lpss = lp.longestPalindrome("babad");

	//������ת
	intReverse ir;
	int irret = ir.reverse(964632435);

	//string to int
	StringAtoi sa;
	int sares = sa.strAtoi("2147483646");

	//����
	Palindrome pd;
	pd.isNumberPalindrome(12321);


	system("pause");

	return 0;
}

