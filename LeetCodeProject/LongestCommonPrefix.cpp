#include "stdafx.h"
#include "stdafx.h"
#include "LongestCommonPrefix.h"

LongestCommonPrefix::LongestCommonPrefix()
{
}


LongestCommonPrefix::~LongestCommonPrefix()
{
}
//
//string LongestCommonPrefix::longestCommonPrefix(vector<string>& strs)
//{
//	if (strs.empty()) return "";
//	string res = "";
//	for (int i = 0; i < strs[0].size(); ++i) {
//		char s = strs[0][i];
//		for (int j = 1; j < strs.size(); ++j)
//		{
//			if (strs[j][i] != s || strs[j].size() <= i) return res;
//		}
//		res.push_back(s);
//	}
//
//	return res;
//}

//string LongestCommonPrefix::longestCommonPrefix(vector<string>& strs)
//{
//	if (strs.empty()) return "";
//	for (int i = 0; i < strs[0].size(); ++i) {
//		for (int j = 0; j < strs.size(); ++j)
//		{
//			if (strs[j][i] != strs[0][i] || strs[j].size() <= i)
//				return strs[j].substr(0, i);
//		}
//	}
//	return strs[0];
//}

string LongestCommonPrefix::longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty()) return "";
	sort(strs.begin(), strs.end());
	int i = 0, len = min(strs[0].size(), strs.back().size());
	while (i < len && strs[0][i] == strs.back()[i]) ++i;
	return strs[0].substr(0, i);
}