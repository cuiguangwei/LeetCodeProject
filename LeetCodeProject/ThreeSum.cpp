#include "stdafx.h"
#include "ThreeSum.h"


ThreeSum::ThreeSum()
{
}


ThreeSum::~ThreeSum()
{
}

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums)
{
	vector<vector<int>> res;

	sort(nums.begin(), nums.end());//����
	if (nums.empty() || nums.front() > 0 || nums.back() < 0) return{};//�ų����ֵС��0����Сֵ����0��Ϊ�յļ������




	return res;
}