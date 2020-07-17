/*
1. С�׵�����֮· 
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. 
��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,����ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi��c�����Լ��.
��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����? 
���������� ����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ. �ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ����� 
��������� ����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ

������˼·����
���������ֵ���ۼӷ����������һ����ֱ�����bi,һ�����ۼӵ�ǰ����ֵ��bi�����Լ�������Լ��
����ͨ����ת�������ã�a��b�����Լ���൱��b��a,b���������Լ�������������Ϊ0�� ��bΪ��
����
*/
#include<vector> 
#include<iostream>
using namespace std;
int GCD(int a, int b) {
	int c;
	while (c = a % b) {
		a = b; 
		b = c;
	}
	return b; 
}
int main() {
	int n, power;
	vector<int> num;
	while (cin >> n >> power) {
		num.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		for (int k = 0; k < n; k++) {
			if (num[k] < power) {
				power += num[k];
			}
			else { 
				power += GCD(power, num[k]);
			}
		}
		cout << power << endl;
	}
	return 0;
}

#include <cstdio> 
#include <cstring> 
#include <cstdlib>
#include <algorithm>
using namespace std;
int gcd(int a,int b){ 
	int tmp;
	while(b){ 
		tmp = b;
		b = a % b ;
		a = tmp;
	}
	return a;
}
int main(){ 
	int n,a;
	while(scanf("%d%d",&n,&a) != EOF){
		for(int i = 0,x;i < n;++ i){ 
			scanf("%d",&x);
			if(x <= a) 
				a += x; 
			else 
				a += gcd(x,a);
		}
		printf("%d\n",a);
	}
	return 0;
}

/*
2.  ���⣺�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ� 
���������� ����һ���ǿ��ַ��� 
��������� �����һ��ֻ����һ�ε��ַ���������������-1

������˼·����
��һ�������ÿһ��λ�ñ�ʾ��Ӧ��λ�á���Ӧ���ַ�λ�ô���ַ����ֵĴ�����ͳ����֮�󣬱��������ַ���������һ��ֻ����һ�ε��ַ���ֹͣ
*/

#include <string>
#include <iostream>
using namespace std;
int main() { 
	string s;
	while(cin>>s) {
		int hashtable[256] = {0};
		for(auto& e : s) {
			hashtable[e]++;
		}
		int i;
		for(i = 0;i < s.size();i++) {
			if(hashtable[s[i]] == 1) {
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size())
			cout << -1 << endl;
	}
	return 0; 
}