/*
1. ����ˮƿ�� ������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�� ��3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ� ��3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ� 
���������� �����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1<=n<=100������ʾС�����ϵĿ���ˮƿ����n=0��ʾ�����������ĳ���Ӧ������ ��һ�С�
��������� ����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��
 
 ������˼·����
 ��������򵥣�ÿ�ο�ƿ����������2��ֱ������ƿ������������ƿ�����ۼӵ��˿ζһ���������
*/
#include<iostream>
#include<string>
using namespace std; 
int calculateNum(int num) { 
	//�ܶһ��� 
	int sum = 0;
	while (num > 1) { 
		//ÿ��ƿ��һƿ 
		int result = num / 3;
		//ʣ�಻����ƿ���ȱ��� 
		int reminder = num % 3;
		sum = sum + result;
		//��һ�ο��Զһ��Ŀ�ƿ 
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
2.�����������ַ���a,b�е�������Ӵ������������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ��� 
���������� ���������ַ���
��������� �����ظ����ֵ��ַ�

������˼·����
������Ҫ�ö�̬�滮��⣬MCS[i][j]��¼���ַ��� s1 ǰ i ���ַ��ͳ��ַ��� s2 ǰ j ���ַ�����Ӵ��ĳ��ȣ���ʼ������ֵΪ 0���� s1[i-1] = s2[j-1]ʱ��MCS[i][j] = MCS[i - 1][j - 1] + 1������ʹ��һ�������ֵstart ����¼��Ӵ��ڶ��ַ��� s1 �г��ֵ���ʼλ�ã�maxlen��¼��ǰ��Ӵ��ĳ��ȣ���MCS[i][j] >maxlen ʱ��maxlen = MCS[i][j]�� ��start = i - maxlen ����s1[i-1] != s2[j-1]ʱ����Ҫ�κβ���������ȡsubstr(start, maxlen)��Ϊ����
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		//����̵��ַ�����Ϊs1 
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++) {
			for (j = 1; j <= len2; j++) {
				if (str1[i - 1] == str2[j - 1])
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				//����и����Ĺ����Ӵ������³��� 
				if (MCS[i][j] > max) {
					max = MCS[i][j];
					//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max 
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
			swap(s1, s2);	//��֤s1�Ƕ̴� 
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