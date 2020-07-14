/*
1. [�ַ�����ת] д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������ַ������Ȳ�����1000��

��������: ����N���ַ�
�������: ������ַ�����ת����ַ���

������˼·����
�ַ�����ת����Ҫ������β�ַ���������β����λ��start��end��ÿ�ν�����β�ַ���Ȼ��start++, end--��
ֱ��start��end��������ת��ɡ�
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
2. ��Ŀ����
��Ŀ���⣺ �����ַ�������
���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд

��ϸ������
�ӿ�˵��
ԭ�ͣ� int getCommonStrLength(char * pFirstStr, char * pSecondStr);
���������
     char * pFirstStr //��һ���ַ���
     char * pSecondStr//�ڶ����ַ���
��������: ���������ַ���
�������: ���һ������

������˼·����
����󹫹��Ӵ���ʹ�õ���ʵ�� ���� x(i): �ַ�����i���ַ� y(j): �ַ�����j���ַ� dp[i][j]: ��x(i),y(j)��β������Ӵ����� ���磺x: "abcde" y:"bcdae" dp[2][1]: ��x(2),y(1)��β������Ӵ����� ����x������"abc", y������"bc", �����ַ�'c'��βʱ��󹫹��Ӵ�Ϊ"bc".
�ʣ�������dp[i][j]ʱ�����ȿ�x(i),y(j)��ֵ�� 
1. x(i) == y(j)��ǰ�����ַ�����β���ַ���ȣ�dp[i][j] = dp[i-1][j-1] + 1 ��֮ǰ�ĳ��ȼ�1
2. x(i) != y(j) ��ǰ�����ַ�����β���ַ�����ȣ�˵��û�����������ַ���β�Ĺ����Ӵ� ��dp[i][j] = 0
3. dp[0][j] �� dp[i][0]��ʾ��ĳ���Ӵ��ĵ�һ���ַ���β����󳤶�Ϊ1 ���x(0) == y(j) ���� x(i) == y(0), �򳤶�Ϊ1������Ϊ0. 
��dp�е�����Ԫ�ؼ�����֮�󣬴����ҵ�����ֵ���
*/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int max = 0; //max��ֵ.
	string str1, str2;
	while (cin >> str1 >> str2) {
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0; 
		//����ֵ��ʼ��Ϊ0 
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		//����dp
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				//�����ǰ��β���ַ���ȣ�����dp[i-1][j-1]�Ļ����ϼ�1
				if (str1[i] == str2[j]) {
					if (i >= 1 && j >= 1) 
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else 
						//dp[i][0] or dp[0][j] 
						dp[i][j] = 1;
				}
				//�������ֵ 
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
			swap(s1, s2);//��֤s1�Ƕ̴�
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