/*
1. ���ʵ��� 
���ַ����е����е��ʽ��е��š� ˵����1��ÿ����������26����д��СдӢ����ĸ���ɣ� 2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������ 3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո��� ���� 4��ÿ�������20����ĸ�� ���������� ����һ���Կո����ָ��ľ��� ��������� ������ӵ�����

����Ŀ��������
��������ǰ������ַ������������� �з� �� �ϲ� ��Ȼ���� C ���Կ��Ͻ������Ƶ�����, �����������ı�
���ǶԵ��ʷָ����������, ֻҪ����ĸ, ����Ҫ���ɷָ��, ���ҷָ������Ŀ��������.
������˼·����
���������˼·��Ȼ��
1. ���з�(�з�ǰ�ȶԷָ��������, ͳһ�ָ��) , ��ʱ����ʹ�� stringstream �����з�
2. �ٺϲ�(���зֽ������ϲ�) ֱ���ַ���ƴ�Ӻϲ�����.
*/
#include<iostream>
#include<sstream>
#include<string>
#include<vector> 
using namespace std;
void deal(vector<string>&res,string& str, char delim = ' ') { 
	// ���ַ��������з�, ���� stringstream ���. Ĭ�Ϸָ���ǿո�. 
	// stringstream ����������з�, ��������ַ���������֮���ת��.
	stringstream ss;
	ss << str; 
	string tmp;
	while (ss>>tmp) {
		res.push_back(tmp);
	}
}
int main() {
	string str;
	while (getline(cin, str)) {
		vector<string> res;
		for (int i = 0; i < str.size(); i++){ // �ȶԷָ�����д���. ������ַָ��, ��ͳһ����ɿո�. 
			if (!isalnum(str[i])){
				str[i] = ' '; 
			}
		}
		// ���ַ��������з� 
		deal(res, str);
		cout << res[res.size() - 1];
		for (int i = res.size() - 2; i >= 0; i--)
			cout << " " << res[i];
		cout << endl;
	}
	return 0;
}
/*
2. ����������
��C/C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ������ �ʣ����硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�� ���硰helloWorld���� ���������ĳ���Ա���Զ�ת���������� ���������� ��������������ݡ� ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100�� ��������� ��Ӧÿһ�����ݣ������������Ӧ��������������
������˼·����
����һ���ַ�һ���ַ��Ķ�ȡ����
1. ���� _ ��ֱ������
2. �����һ���ַ��� _ ����һ���ַ�ת��д��ĸ
*/
#include<iostream> 
#include<vector> 
#include<string> 
#include<algorithm>
#include<functional> 
#include <map>
#include <set> 
#include <unordered_set>
#include <unordered_map>
#include <exception> 
#include <iomanip>
#include <memory> 
#include <sstream> 
#define INF 1000000
using namespace std;
int main(int argc, char** argv) {
	string s;
	while (cin >> s) { 
		for (int i = 0; i < s.size(); ++i) {
			// 1. ���� _ ��ֱ������
			if (s[i] == '_') 
				continue; 
			// 2. �����һ���ַ��� _ ����һ���ַ�תΪ��д��ĸ
			if (i > 0 && s[i - 1] == '_') 
				cout << (char)toupper(s[i]);
			else 
				cout << s[i];
		}
		cout << endl;
	}
	return 0; 
}