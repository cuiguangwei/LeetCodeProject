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
	unordered_map<int, int> m;
	vector<int> res;

	for (auto i : nums1) ++m[i];
	for (auto i : nums2) {
		if (m[i]-- > 0) res.push_back(i);
	}
	return res;
	/*unordered_map<int, int> m;
	vector<int> res;

	for (auto i : nums1) {
		int a = m[i];
		++m[i];
	}
	for (auto i : nums2) {
		int a = m[i];
		if (a != 0) {
			--m[i];
			res.push_back(i);
		}
	}
	return res;*/
}