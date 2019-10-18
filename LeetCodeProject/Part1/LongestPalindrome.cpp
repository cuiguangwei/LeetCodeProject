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
	//����֪����ͳ����֤���Ĵ��ķ����������������ĶԳ���֤�Ƿ���ȣ���ô�����һ����ִ������⣬��Ҫ��ÿһ���ַ�Ϊ���ģ�
	//��������ɢ��Ѱ�һ��Ĵ�������㷨��ʱ�临�Ӷ��� O(n*n)������ͨ�� OJ������Ҫע����ż��������ڻ��Ĵ��ĳ��ȿ���
	//��ż������ "bob" ��������ʽ�Ļ��ģ�"noon" ����ż����ʽ�Ļ��ģ�������ʽ�Ļ��Ķ�Ҫ����������������ʽ�ģ����Ǿ�
	//�ӱ�������λ��Ϊ���ģ������߽�����ɢ������ż����������ǾͰѵ�ǰλ�ú���һ��λ�õ���ż���л��ĵ����м������ַ�
	//��Ȼ�������߽����������μ��������£�
	/*if (s.size() < 2) return s;//1
	int n = s.size(), maxLen = 0, start = 0;
	for (int i = 0; i < n - 1; ++i) {
		searchPalindrome(s, i, i, start, maxLen);
		searchPalindrome(s, i, i + 1, start, maxLen);//?
	}
	return s.substr(start, maxLen);*/

	//����Ҳ���Բ�ʹ���Ӻ�����ֱ����һ�������и㶨�����ǻ���Ҫ������������ start �� maxLen��
	//�ֱ��ʾ������Ӵ����������ȣ��ڱ���s�е��ַ���ʱ�����������ж�ʣ����ַ����Ƿ�С�ڵ��� 
	//maxLen ��һ�룬�ǵĻ���������ӵ�ǰ��ĩβ���Ӵ��ǰ�����Ĵ�����ô�������Ĵ��������Ҳ���� maxLen��
	//��Ȼ maxLen �޷��ٱ䳤�ˣ�������Щ��û�����壬ֱ���ڵ�ǰλ�� break �������ˡ������Ҫ�����жϣ�
	//�������������� left �� right �ֱ�ָ��ǰλ�ã�Ȼ��������Ҫ���������ұ��������ظ����������ܱ�Ҫ��
	//������� noon��i�ڵ�һ��o��λ�ã����������oΪ��������������ɢ�����޷��õ�����Ϊ4�Ļ��Ĵ��ģ�ֻ���������ظ���
	//��ʱleftָ���һ��o��rightָ��ڶ���o��Ȼ������������ɢ�������� bob��i�ڵ�һ��o��λ��ʱ���޷����������ظ���
	//��ʱ left �� right ͬʱָ��o������������ɢҲ����ȷ�ģ����Կ���ͬʱ����������ż���Ļ��Ĵ���֮��Ĳ������Ǹ�
	//�� maxLen �� start �ˣ�������Ĳ���һ�����μ��������£�
	//if (s.size() < 2) return s;//2
	//int n = s.size(), maxLen = 0, start = 0;
	//for (int i = 0; i < n;) {
	//	if (n - i <= maxLen / 2) break;
	//	int left = i, right = i;
	//	while (right < n - 1 && s[right + 1] == s[right]) //�����ظ���
	//		++right;
	//	i = right + 1;
	//	while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {//��������
	//		++right; --left;
	//	}
	//	if (maxLen < right - left + 1) {
	//		maxLen = right - left + 1;
	//		start = left;
	//	}
	//}
	//return s.substr(start, maxLen);

	//���Ҫ���ľ��Ǵ����������������㷨 Manacher's Algorithm������㷨������֮�����ڽ�ʱ�临�Ӷ��������� O(n) ��������ĵز������㷨����Ҳ��Ƶĺ������ֵ����������
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