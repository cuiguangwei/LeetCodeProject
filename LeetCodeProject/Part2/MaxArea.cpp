#include "stdafx.h"
#include "MaxArea.h"


MaxArea::MaxArea()
{
}


MaxArea::~MaxArea()
{
}

//这道题的核心就是从两端向中间搜索，依次计算边距乘以两个边缘中较小值的乘积即面积，取最大的即可。
int MaxArea::maxArea(vector<int> height)
{
	int ret = 0, left = 0, right = height.size() - 1;
	while (left < right)
	{
		ret = max(ret, (right - left) * min(height[left], height[right]));
		height[left] < height[right] ? ++left : --right;
	}
	return ret;
}