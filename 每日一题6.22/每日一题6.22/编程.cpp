/*
1. 【汽水瓶】 有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子 换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后 用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？ 
输入描述： 输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理 这一行。
输出描述： 对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
 
 【解题思路】：
 本题题意简单，每次空瓶的数量除以2，直到最后空瓶的数量少于两瓶，就累加到了课兑换的数量。
*/
#include<iostream>
#include<string>
using namespace std; 
int calculateNum(int num) { 
	//总兑换数 
	int sum = 0;
	while (num > 1) { 
		//每三瓶换一瓶 
		int result = num / 3;
		//剩余不足三瓶的先保留 
		int reminder = num % 3;
		sum = sum + result;
		//下一次可以兑换的空瓶 
		num = result + reminder;
		if (num == 2) {
			++sum;
			break;
		}
	}
	return sum;
}
int main(){
	int number;
	while (cin >> number) {
		cout << calculateNum(number) << endl;
	}
	return 0;
}


/*
2.【查找两个字符串a,b中的最长公共子串】查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。 
输入描述： 输入两个字符串
输出描述： 返回重复出现的字符

【解题思路】：
本题需要用动态规划求解，MCS[i][j]记录短字符串 s1 前 i 个字符和长字符串 s2 前 j 个字符的最长子串的长度，初始化所有值为 0。当 s1[i-1] = s2[j-1]时，MCS[i][j] = MCS[i - 1][j - 1] + 1，这里使用一个额外的值start 来记录最长子串在短字符串 s1 中出现的起始位置，maxlen记录当前最长子串的长度，当MCS[i][j] >maxlen 时，maxlen = MCS[i][j]， 则start = i - maxlen ；档s1[i-1] != s2[j-1]时不需要任何操作，最后获取substr(start, maxlen)即为所求。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		//以最短的字符串作为s1 
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++) {
			for (j = 1; j <= len2; j++) {
				if (str1[i - 1] == str2[j - 1])
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				//如果有更长的公共子串，更新长度 
				if (MCS[i][j] > max) {
					max = MCS[i][j];
					//以i结尾的最大长度为max, 则子串的起始位置为i - max 
					start = i - max;
				}
			}
			cout << str1.substr(start, max) << endl;
		}
	}
	return 0; 
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s1;
	string s2;
	while(cin>>s1>>s2) {
		int len1 = s1.size();
		int len2 = s2.size();
		string tmp;
		string ret;
		if (len1>len2) {
			swap(s1, s2);	//保证s1是短串 
		}
		int len = s1.size();
		while (len) {
			for (int i = 0; i <= s1.size()-len; i++) {
				tmp = s1.substr(i, len);
				/*if (strstr(s2.c_str(), tmp.c_str())) {
				ret = tmp;
				break;
				}*/ 
				if (s2.find(tmp) != string::npos) {
					ret = tmp;
					break;
				}
			}
			if (ret.size() > 0) {
				break;
			}
			len--;
		}
		cout << ret << endl;
	}
	return 0;
}