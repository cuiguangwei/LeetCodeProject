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
	/*int ret = 0; //������� int�͵���ֵ��Χ�� -2147483648��2147483647�����Ҫ��ת 1000000009 ����ڷ�Χ�ڵ����õ� 9000000001������ת������ͳ����˷�Χ
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