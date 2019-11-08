// LeedCodeProject.cpp : 定义控制台应用程序的入口点。
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

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//两数相加
	AddTwoNumber tn;
	ListNode l1(1);
	ListNode l2(3);
	ListNode l3(5);
	l1.next = &l2;
	l2.next = &l3;
	cout << tn.addTwoNumbers(&l1, &l1);

	//求最长无重复子串
	LengthOfLongestSubstring ls;
	ls.lengthOfLongestSubstring("pwwkew");

	//寻找两个有序数组的中位数
	FindMedianSortedArrays fsa;

	vector<int> nums1{1,2,3};
	vector<int> nums2{6,8};
	double a = fsa.findMedianSortedArrays(nums1, nums2);

	//最长回文子串
	LongestPalindrome lp;
	string lpss = lp.longestPalindrome("babad");

	//整数翻转
	intReverse ir;
	int irret = ir.reverse(964632435);

	//string to int
	StringAtoi sa;
	int sares = sa.strAtoi("2147483646");

	//回文
	Palindrome pd;
	pd.isNumberPalindrome(12321);

	//电话号码的字母组合
	PhoneNumberCombinations pnc;
	vector<string> pncres = pnc.numberCombinations("23");

	string aaaa = "121212";
	string b = move(aaaa);

	//有效的括号
	ValidParentheses vps;
	bool vpsres = vps.isValid("([)]");


	ListNode l4(2);
	ListNode l5(3);
	ListNode l6(7);
	l4.next = &l5;
	l5.next = &l6;
	MergeTwoLists mtl;
	ListNode *mtlret = mtl.mergeTwoLists(&l1, &l4);

	system("pause");

	return 0;
}

