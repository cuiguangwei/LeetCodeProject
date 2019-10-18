#include "stdafx.h"
#include "LongestPalindrome.h"
#include <algorithm>

LongestPalindrome::LongestPalindrome()
{
}


LongestPalindrome::~LongestPalindrome()
{
}

void searchPalindrome(string s, int left, int right, int &start, int &maxLen)
{
	while (left >= 0 && right < s.size() && s[left] == s[right])
	{
		--left;
		++right;
	}
	if (maxLen < right - left - 1) {
		start = left + 1;
		maxLen = right - left -1;
	}
}

string LongestPalindrome::longestPalindrome(string s)
{
	//我们知道传统的验证回文串的方法就是两个两个的对称验证是否相等，那么对于找回文字串的问题，就要以每一个字符为中心，
	//像两边扩散来寻找回文串，这个算法的时间复杂度是 O(n*n)，可以通过 OJ，就是要注意奇偶情况，由于回文串的长度可奇
	//可偶，比如 "bob" 是奇数形式的回文，"noon" 就是偶数形式的回文，两种形式的回文都要搜索，对于奇数形式的，我们就
	//从遍历到的位置为中心，向两边进行扩散，对于偶数情况，我们就把当前位置和下一个位置当作偶数行回文的最中间两个字符
	//，然后向两边进行搜索，参见代码如下：
	/*if (s.size() < 2) return s;//1
	int n = s.size(), maxLen = 0, start = 0;
	for (int i = 0; i < n - 1; ++i) {
		searchPalindrome(s, i, i, start, maxLen);
		searchPalindrome(s, i, i + 1, start, maxLen);//?
	}
	return s.substr(start, maxLen);*/

	//我们也可以不使用子函数，直接在一个函数中搞定，我们还是要定义两个变量 start 和 maxLen，
	//分别表示最长回文子串的起点跟长度，在遍历s中的字符的时候，我们首先判断剩余的字符数是否小于等于 
	//maxLen 的一半，是的话表明就算从当前到末尾到子串是半个回文串，那么整个回文串长度最多也就是 maxLen，
	//既然 maxLen 无法再变长了，计算这些就没有意义，直接在当前位置 break 掉就行了。否则就要继续判断，
	//我们用两个变量 left 和 right 分别指向当前位置，然后我们先要做的是向右遍历跳过重复项，这个操作很必要，
	//比如对于 noon，i在第一个o的位置，如果我们以o为最中心往两边扩散，是无法得到长度为4的回文串的，只有先跳过重复，
	//此时left指向第一个o，right指向第二个o，然后再向两边扩散。而对于 bob，i在第一个o的位置时，无法向右跳过重复，
	//此时 left 和 right 同时指向o，再向两边扩散也是正确的，所以可以同时处理奇数和偶数的回文串，之后的操作就是更
	//新 maxLen 和 start 了，跟上面的操作一样，参见代码如下：
	//if (s.size() < 2) return s;//2
	//int n = s.size(), maxLen = 0, start = 0;
	//for (int i = 0; i < n;) {
	//	if (n - i <= maxLen / 2) break;
	//	int left = i, right = i;
	//	while (right < n - 1 && s[right + 1] == s[right]) //跳过重复项
	//		++right;
	//	i = right + 1;
	//	while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {//两边扩撒
	//		++right; --left;
	//	}
	//	if (maxLen < right - left + 1) {
	//		maxLen = right - left + 1;
	//		start = left;
	//	}
	//}
	//return s.substr(start, maxLen);

	//最后要来的就是大名鼎鼎的马拉车算法 Manacher's Algorithm，这个算法的神奇之处在于将时间复杂度提升到了 O(n) 这种逆天的地步，而算法本身也设计的很巧妙，很值得我们掌握
	string t = "$#";
	for (int i = 0; i < s.size(); ++i) {
		t += s[i];
		t += '#';
	}
	int *p = new int[t.size()]{0};
	//*p = { 0 };
	int id = 0, mx = 0, resId = 0, resMx = 0;
	for (int i = 1; i < t.size(); ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (t[i + p[i]] == t[i - p[i]]) ++p[i];
		if (mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
		if (resMx < p[i]) {
			resMx = p[i];
			resId = i;
		}
	}
	return s.substr((resId - resMx) / 2, resMx - 1);
}