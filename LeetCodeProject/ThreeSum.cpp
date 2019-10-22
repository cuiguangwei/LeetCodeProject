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

	sort(nums.begin(), nums.end());//排序
	if (nums.empty() || nums.front() > 0 || nums.back() < 0) return{};//排除最大值小于0、最小值大于0、为空的极端情况




	return res;
}