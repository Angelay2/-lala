/*
1. [字符串反转] 写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述: 输入N个字符
输出描述: 输出该字符串反转后的字符串

【解题思路】：
字符串反转，需要交换首尾字符，设置首尾两个位置start，end，每次交换首尾字符，然后start++, end--，
直到start，end相遇，反转完成。
*/
#include<string> 
#include<iostream>
using namespace std; 
string reverseString(string s) { 
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end) {
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}
int main() {
	string s;
	getline(cin,s);
	cout<< reverseString(s) <<endl;
	return 0;
}

/*
2. 题目描述
题目标题： 公共字符串计算
计算两个字符串的最大公共字串的长度，字符不区分大小写

详细描述：
接口说明
原型： int getCommonStrLength(char * pFirstStr, char * pSecondStr);
输入参数：
     char * pFirstStr //第一个字符串
     char * pSecondStr//第二个字符串
输入描述: 输入两个字符串
输出描述: 输出一个整数

【解题思路】：
求最大公共子串，使用递推实现 假设 x(i): 字符串第i个字符 y(j): 字符串第j个字符 dp[i][j]: 以x(i),y(j)结尾的最大子串长度 比如：x: "abcde" y:"bcdae" dp[2][1]: 以x(2),y(1)结尾的最大子串长度 即：x遍历到"abc", y遍历到"bc", 都以字符'c'结尾时最大公共子串为"bc".
故：当计算dp[i][j]时，首先看x(i),y(j)的值： 
1. x(i) == y(j)当前两个字符串结尾的字符相等，dp[i][j] = dp[i-1][j-1] + 1 即之前的长度加1
2. x(i) != y(j) 当前两个字符串结尾的字符不相等，说明没有以这两个字符结尾的公共子串 即dp[i][j] = 0
3. dp[0][j] 和 dp[i][0]表示以某个子串的第一个字符结尾，最大长度为1 如果x(0) == y(j) 或者 x(i) == y(0), 则长度为1，否则为0. 
当dp中的所有元素计算完之后，从中找到最大的值输出
*/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int max = 0; //max初值.
	string str1, str2;
	while (cin >> str1 >> str2) {
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0; 
		//所有值初始化为0 
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		//计算dp
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				//如果当前结尾的字符相等，则在dp[i-1][j-1]的基础上加1
				if (str1[i] == str2[j]) {
					if (i >= 1 && j >= 1) 
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else 
						//dp[i][0] or dp[0][j] 
						dp[i][j] = 1;
				}
				//更新最大值 
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		cout << max << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s1;
	string s2;

	while (cin >> s1 >> s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		string tmp;
		string ret;


		if (len1>len2)
		{
			swap(s1, s2);//保证s1是短串
		}
		int len = s1.size();
		while (len)
		{
			for (int i = 0; i <= s1.size() - len; i++)
			{
				tmp = s1.substr(i, len);
				/*if (strstr(s2.c_str(), tmp.c_str()))
				{
				ret = tmp;
				break;
				}*/
				if (s2.find(tmp) != string::npos)
				{
					ret = tmp;
					break;
				}
			}
			if (ret.size() > 0)
			{
				break;
			}
			len--;
		}

		cout << ret << endl;
	}
	return 0;
}