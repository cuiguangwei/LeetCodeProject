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

	for (int k = 0; k < (int)nums.size() - 2; ++k) {
		if (nums[k] > 0) break;
		if (k > 0 && nums[k] == nums[k - 1]) continue;
		int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] == target) {
				res.push_back({ nums[k], nums[i], nums[j] });
				while (i < j && nums[i] == nums[i + 1]) ++i;
				while (i < j && nums[j] == nums[j - 1]) --j;
				++i; --j;
			}
			else if (nums[i] + nums[j] < target) ++i;
			else --j;
		}
	}

	return res;
}