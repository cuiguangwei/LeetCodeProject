#include "stdafx.h"
#include "TwoArrayIntersect.h"
#include <unordered_map>

TwoArrayIntersect::TwoArrayIntersect()
{
}


TwoArrayIntersect::~TwoArrayIntersect()
{
}

vector<int> TwoArrayIntersect::intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res;
	int i = 0, j = 0;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] == nums2[j]) {
			res.push_back(nums1[i]);
			++i; ++j;
		} else if (nums1[i] > nums2[j]) {
			++j;
		} else {
			++i;
		}
	}
	return res;
}

//vector<int> TwoArrayIntersect::intersect(vector<int>& nums1, vector<int>& nums2) {
//	unordered_map<int, int> m;
//	vector<int> res;
//
//	for (auto i : nums1) ++m[i];
//	for (auto i : nums2) {
//		if (m[i]-- > 0) res.push_back(i);
//	}
//	return res;
//	/*unordered_map<int, int> m;
//	vector<int> res;
//
//	for (auto i : nums1) {
//		int a = m[i];
//		++m[i];
//	}
//	for (auto i : nums2) {
//		int a = m[i];
//		if (a != 0) {
//			--m[i];
//			res.push_back(i);
//		}
//	}
//	return res;*/
//}