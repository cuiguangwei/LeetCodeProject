#include "stdafx.h"
#include "ValidParentheses.h"
#include <stack>

ValidParentheses::ValidParentheses()
{
}


ValidParentheses::~ValidParentheses()
{
}

//
bool ValidParentheses::isValid(string s) {
	/*vector<char> list;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
			list.push_back(s[i]);
		}
		else {
			if (list.empty()) return false;
			if (s[i] == ']' && list.back() == '[') {
				list.pop_back();
			} else if (s[i] == ')' && list.back() == '(') {
				list.pop_back();
			} else if (s[i] == '}' && list.back() == '{') {
				list.pop_back();
			}
			else {
				return false;
			}
		}
	}
	if (list.empty())
		return true;
	else 
		return false;*/
	stack<char> parentheses;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
		else {
			if (parentheses.empty()) return false;
			if (s[i] == ')' && parentheses.top() != '(') return false;
			if (s[i] == ']' && parentheses.top() != '[') return false;
			if (s[i] == '}' && parentheses.top() != '{') return false;
			parentheses.pop();
		}
	}
	return parentheses.empty();
}