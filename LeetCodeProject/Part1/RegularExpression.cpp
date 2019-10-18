#include "stdafx.h"
#include "RegularExpression.h"


RegularExpression::RegularExpression()
{
}


RegularExpression::~RegularExpression()
{
}

bool RegularExpression::isMatch(string s, string p)
{
	if (p.empty()) return s.empty();
	if (p.size() > 1 && p[1] == '*') {
		return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
	}
	else {
		return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
}