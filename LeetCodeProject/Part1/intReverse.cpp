#include "stdafx.h"
#include "intReverse.h"
#include <algorithm>


intReverse::intReverse()
{
}


intReverse::~intReverse()
{
}

int intReverse::reverse(int x)
{
	/*int ret = 0; //整形溢出 int型的数值范围是 -2147483648～2147483647，如果要翻转 1000000009 这个在范围内的数得到 9000000001，而翻转后的数就超过了范围
	bool flag = false;
	if (x < 0) {
		x = x * (-1);
		flag = true;
	}

	while (x != 0) {
		ret = ret * 10 + x % 10;
		x = x / 10;
	}
	ret = ret * 10 + x % 10;
	ret = flag ? ret  * (-1) : ret;
	return ret;*/

	int res = 0;
	while (x != 0)
	{
		if (abs(res) > INT_MAX / 10)
			return 0;
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}