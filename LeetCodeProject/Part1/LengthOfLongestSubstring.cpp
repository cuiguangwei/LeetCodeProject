#include "stdafx.h"
#include "LengthOfLongestSubstring.h"

#include <unordered_map>
#include <algorithm>
#include <iostream>


LengthOfLongestSubstring::LengthOfLongestSubstring()
{
}


LengthOfLongestSubstring::~LengthOfLongestSubstring()
{
}

//3
static int x = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

//求最长无重复子串
int LengthOfLongestSubstring::lengthOfLongestSubstring(string s)
{
	//1  
	/*int res = 0, left = -1;
	unordered_map<char, int> map;
	for (int  i = 0; i < s.size(); ++i)
	{
		if (map.count(s[i]) && map[s[i]] > left) {
			left = map[s[i]];
		}
		map[s[i]] = i;
		res = max(res, i - left);
	}*/

	//2
	vector < int > m(128, -1);
	int res = 0, left = -1;
	for (int i = 0; i < s.size(); ++i) {
		left = max(left, m[s[i]]);
		m[s[i]] = i;
		res = max(res, i - left);
	}


	return res;
}