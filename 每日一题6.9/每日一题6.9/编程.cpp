#include <stdlib.h>
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

/*
1. ���������򷽷���������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺 "car" < "carriage" < "cats" < "doggies < "koala" 2.�����ַ����ĳ����������磺 "car" < "cats" < "koala" < "doggies" < "carriage" ������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤�� 
���������� �����һ��Ϊ�ַ�������n(n �� 100) ��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ��� 
��������� �����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically", ������ݳ������ж������ֵ����������"lengths", ������ַ�ʽ���������"both"���������"none"   

������˼·����
˼·�ܼ򵥣������ܵ��ַ������ŵ�vector�����У�����string��operator>=�������������ascii�Ƚ��ַ�
��������string��size���Ƚ��ַ����ĳ���
*/
int main4(){
	int n; 
	cin >> n; 
	vector<string> v; 
	v.resize(n); 
	for (auto& str : v) 
		cin >> str; 
	bool lenSym = true, lexSym = true; 
	// ����Ҫע���i=1��ʼ������ǰ��Ƚϣ��Ƚϳ��� 
	for(size_t i = 1; i < v.size(); ++i){ 
		if(v[i-1].size() >= v[i].size()){ 
			lenSym = false; 
			break; 
		} 
	}
	//�Ƚ�ASCII�� 
	for(size_t i = 1; i < v.size(); ++i){ 
		if(v[i-1] >= v[i]){ 
			lexSym = false; 
			break; 
		} 
	}
	if (lenSym&& lexSym)
		cout << "both" << endl; 
	else if (!lenSym && lexSym) 
		cout << "lexicographically" << endl; 
	else if (lenSym && !lexSym) 
		cout << "lengths" << endl; 
	else if (!lenSym&&!lexSym) 
		cout << "none" << endl; 
	return 0;
}

/*
2. ������С�������� ������A��������B����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С�������� 
���������� ��������������A��B��
��������� ���A��B����С��������

������˼·����
��С������ = ����֮���������Լ��������ʹ����ת������������Լ������⣺��a��b�����Լ��
����ת��Ϊa��b֮�������Ϊ����֮����С����֮��Ĺ�Լ�������Զ�������������������������ֱ࣬��
����Ϊ0������ķ�ĸ��Ϊ�����

*/
int gcd(int a, int b){ 
	int r; 
	while(r = a%b){ // ����  �����ܳ�����ʱ��
		a = b; // �ڶ���������һ����
		b = r; // �������ڶ�����
	}
	return b; 
}
int main(){ 
	int a, b; 
	while(cin >> a >> b){ 
		cout << a*b / gcd(a, b) << endl; // ����֮��/��������һ������
	}
	system("pause");
	return 0; 
}