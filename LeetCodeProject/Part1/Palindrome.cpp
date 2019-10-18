#include "stdafx.h"
#include "Palindrome.h"


Palindrome::Palindrome()
{
}


Palindrome::~Palindrome()
{
}

bool Palindrome::isNumberPalindrome(int x)
{
	//if (x < 0) return false;

	//int div = 1;
	//while (x /div >= 10)//取位数
	//{
	//	div *= 10;
	//}
	//while (x > 0)
	//{
	//	int left = x / div;//首位
	//	int right = x % 10;//末位
	//	if (left != right) return false;
	//	x = x % div / 10;
	//	div /= 100;
	//}
	//return true;
	if (x < 0 || (x % 10 == 0 && x != 0)) return false;
	int num = 0;
	while (x > num) {
		num = num * 10 + x % 10;
		x /= 10;
	}
	return x == num || x == num / 10;
}