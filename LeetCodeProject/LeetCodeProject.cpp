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
#include "PhoneNumberCombinations.h"
#include "ValidParentheses.h"
#include "MergeTwoLists.h"
#include "TwoArrayIntersect.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "InsertSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//�������
	AddTwoNumber tn;
	ListNode l1(1);
	ListNode l2(3);
	ListNode l3(5);
	l1.next = &l2;
	l2.next = &l3;
	cout << tn.addTwoNumbers(&l1, &l1);

	//������ظ��Ӵ�
	LengthOfLongestSubstring ls;
	ls.lengthOfLongestSubstring("pwwkew");

	//Ѱ�����������������λ��
	FindMedianSortedArrays fsa;

	//vector<int> nums1{1,2,3};
	//vector<int> nums2{6,8};
	//double a = fsa.findMedianSortedArrays(nums1, nums2);

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

	//�绰�������ĸ���
	PhoneNumberCombinations pnc;
	vector<string> pncres = pnc.numberCombinations("23");

	string aaaa = "121212";
	string b = move(aaaa);

	//��Ч������
	ValidParentheses vps;
	bool vpsres = vps.isValid("([)]");


	ListNode l4(2);
	ListNode l5(3);
	ListNode l6(7);
	l4.next = &l5;
	l5.next = &l6;
	MergeTwoLists mtl;
	ListNode *mtlret = mtl.mergeTwoLists(&l1, &l4);

	TwoArrayIntersect tai;
	vector<int> nums1{ 1,6,8,5,8 };
	vector<int> nums2{ 6,8 };
	vector<int> taires = tai.intersect(nums1, nums2);

	BubbleSort bs;
	int bsarr[] = {1,6,4,3,8,3};
	bs.bubbleSort(bsarr, 6);

	SelectSort ss;
	int ssarr[] = { 1,6,4,3,8,3 };
	ss.selectSort(ssarr, 6);

	InsertSort is;
	int isarr[] = { 1,6,4,3,8,3 };
	is.insertSort(isarr, 6);

	QuickSort qs;
	int qsarr[] = { 5, 3, 8, 6, 4 };
	qs.qucikSort(qsarr, 5);

	HeapSort hs;
	int hsarr[] = {16, 7, 3, 20, 17, 8};
	hs.heapSort(hsarr, 6);

	system("pause");

	return 0;
}

