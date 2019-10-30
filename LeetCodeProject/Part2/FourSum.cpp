#include "stdafx.h"
#include "FourSum.h"
#include <vector>
#include <set>

FourSum::FourSum()
{
}


FourSum::~FourSum()
{
}

vector<vector<int>> FourSum::fourSum(vector<int> &nums, int target)
{
	if (nums.size() < 4) return{};
	set<vector<int>> res;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3; ++i) {
		for (int j = i + 1; j < nums.size() - 2; ++j) {
			if (j > i + 1 && nums[j] == nums[j - 1])//j对应的数值和j + 1相同直接后移
				continue;
			int left = j + 1, right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target) {
					vector<int> obj{ nums[i], nums[j], nums[left], nums[right] };
					res.insert(obj);
					++left, --right;
				}
				else if (sum < target)
					++left;
				else
					--right;
			}
		}
	}

	return vector<vector<int>>(res.begin(), res.end());
}