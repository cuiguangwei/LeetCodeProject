#include "stdafx.h"
#include "PhoneNumberCombinations.h"


PhoneNumberCombinations::PhoneNumberCombinations()
{
}


PhoneNumberCombinations::~PhoneNumberCombinations()
{
}

//解法一
vector<string> PhoneNumberCombinations::numberCombinations(string digits)
{
	if (digits.empty()) return{};

	//vector<string> res;
	vector<string> res{ "" };
	vector<string> dict{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	for (int i = 0; i < digits.size(); ++i) {
		vector<string> tmp;
		string str = dict[digits[i] - '0'];
		for (int j = 0; j < str.size(); ++j) {
			for (string s : res) {
				tmp.push_back(s + str[j]);
			}
		}
		res = tmp;
	}

	return res;
}

//解法二
vector<string> PhoneNumberCombinations::letterCombinations(string digits)
{
	if (digits.empty()) return{};
	vector<string> res;
	vector<string> dict{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	letterCombinationsDFS(digits, dict, 0, "", res);
	return res;
}

void PhoneNumberCombinations::letterCombinationsDFS(string& digits, vector<string>& dict, int level, string out, vector<string>& res)
{
	if (level == digits.size()) {
		res.push_back(out);
		return;
	}

	string str = dict[digits[level] - '0'];
	for (int i = 0; i < str.size(); ++i) {
		letterCombinationsDFS(digits, dict, level + 1, out + str[i], res);
	}
}