#include "stdafx.h"
#include "StringAtoi.h"


StringAtoi::StringAtoi()
{
}


StringAtoi::~StringAtoi()
{
}

int StringAtoi::strAtoi(string str) {
	if (str.empty()) return 0;

	int sign = 1, base = 0, i = 0, n = str.size();
	while (i < n && str[i] == ' ')//remove space
	{
		++i;
	}
	if (i < n && (str[i] == '+' || str[i] == '-')) {//处理++ +- -+ --等
		sign = (str[i++] == '+') ? 1 : -1;
	}

	while (i < n && str[i] >= '0' && str[i] <= '9')//数字
	{
		int ss = str[i] - '0';
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {//数值范围为 [−231,  231 − 1] 次方 2147483646
			return (sign == 1) ? INT_MAX : INT_MIN;
		}
		base = 10 * base + (str[i++] - '0');
	}

	return base * sign;
}