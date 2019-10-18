#include "stdafx.h"
#include "MaxArea.h"


MaxArea::MaxArea()
{
}


MaxArea::~MaxArea()
{
}

//�����ĺ��ľ��Ǵ��������м����������μ���߾����������Ե�н�Сֵ�ĳ˻��������ȡ���ļ��ɡ�
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