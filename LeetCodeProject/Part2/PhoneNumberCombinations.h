#pragma once
class PhoneNumberCombinations
{
public:
	PhoneNumberCombinations();
	~PhoneNumberCombinations();
	vector<string> numberCombinations(string digits);
	vector<string> letterCombinations(string digits);
	void letterCombinationsDFS(string & digits, vector<string>& dict, int level, string out, vector<string>& res);
};

