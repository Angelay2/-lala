/*
1. ���⣺ͳ��ÿ�������ӵ�����
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ������� �Ӷ���������ÿ���µ���������Ϊ���٣� /** * ͳ�Ƴ����������� ** @param monthCount �ڼ����� * @return �������� */ 
/*public static int getTotalCount(int monthCount) { 
	return 0;
}
��������������int�ͱ�ʾmonth 
��������� �����������int��
������˼·����
��n���µ�������������������ɣ�һ�������ϸ��µ�����f(n-1)����һ��������3���´�����ӣ�
����һֻ����f(n-2)�����Ե�n�������������� f(n) = f(n - 1) + f(n - 2)���������ڱ��࿼��쳲���
�����С�
*/
#include <iostream> 
using namespace std;
int main(){
	int month;
	while(cin >> month){
		int first = 1;
		int second = 1;
		int result;
		for(int i = 3; i <= month; ++i){
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	}
	return 0;
}

/*
2.�ַ���ͨ���
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨�� 
Ҫ�� ʵ������2��ͨ����� *��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ�� ����ƥ��1���ַ�
����: ͨ������ʽ�� һ���ַ�����
����� ����ƥ��Ľ������ȷ���true���������false

���������� ������һ������ͨ������ַ�����������һ����Ҫƥ����ַ��� 
��������� ����ƥ��Ľ������ȷ���true���������

������˼·����
�������ͨ���ݹ���⡣��ǰ���һ��ƥ�䣬������ͬ�ַ���������ƶ�һ���ַ������ͨ���
����"?"������ƥ�䣬�Զ�����һ���ַ������ͨ�������"*"�������ƥ���������ַ�������
0������ʱ����������ѡ��1��ƥ��0����ͨ�������ƶ�һ���ַ����ַ���������2��ƥ��1
����ͨ������ַ���������ƶ�һ���ַ���3��ƥ������ͨ����������ַ�������ƶ�һ����
����
�ݹ����ֹ������ͨ��������ַ�������'\0'��������ͬʱ������
*/
#include <iostream> 
#include <string> 
using namespace std;
bool match(const char* pattern, const char *str) {
	//��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?') {
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*') {
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ�� �ַ�)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str) {
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main() {
	string pattern, str;
	while (cin >> pattern >> str) {
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}

/*
1. �������ã�����������p��n���������� 
*/
#include <assert.h>
#include <stdio.h>

void increment_ints(int p[], int n) {
	assert(p != NULL); /* ȷ��p��Ϊ��ָ�� */ 
	assert(n >= 0); /* ȷ��n��Ϊ���� */ 
	while (n) /* ѭ��n��. */ { 
		(*p)++; /* ����p*/
		p++, n--; /* pָ����һλ��n��1 */ }
} 
// *p++ʹ��p�ڽ�����֮ǰ����Ӧ�ø�Ϊ(*p)++

/*
2. ���и��������У�����fun�Ĺ����ǣ����β�a��ָ�����е���Сֵ����Ԫ��a[0]�У����Ű�a��ָ�����е� ���ֵ����a[1]Ԫ����;�ٰ�a��ָ����Ԫ���еĴ�Сֵ����a[2]�У���a��ȡ����Ԫ���еĴδ�ֵ����a[3]���� �����ơ� ����:��a��ָ�����е������������Ϊ��9,1,4,2,3,6,5,8,7;�������ƶ�����������Ϊ:1,9,2,8,3,7,4,6,5���β� n�д��a��ָ���������ݵĸ����� �涨fun�����е�max��ŵĵ�ǰ���ҵ����ֵ,px��ŵ�ǰ�������ֵ���±ꡣ
*/
#include<stdio.h> 
#define N 9 
void fun(int a[ ], int n) {
	int i, j, max, min, px, pn, t;
	for (i = 0; i < n - 1; i += 2) {
		max = min = a[i];
		px = pn = i;
		// ȷ�����ֵ����Сֵ
		for (j = i + 1; j < n; j++) { 
			if (max < a[j]) {
				max = a[j];
				px = j;
			}
			if (min > a[j]) {
				min = a[j];
				pn = j;
			}
		}
		// ��Сֵ���ڵ�iλ�� ����Сֵ������i��λ��, ����
		if (pn != i) {
			t = a[i];
			a[i] = min;
			a[pn] = t;
			// ���ԭʼ��ֵΪ���ֵ, Ҳ�������ֵ���ڵ�i��λ��, ���±��Ϊ����֮���λ��
			if (px == i) 
				px = pn;
		}
		// ��Сֵ�ڵ�i��λ��, ������ֵ���ڵ�i+1��λ��, �����ֵ���ڷŵ�i+1��λ��,����
		if (px != i + 1) {
			t = a[i + 1];
			a[i + 1] = max;
			a[px] = t;
		}
	}
}
#include <stdlib.h>
int main() {
	int b[N] = {9, 1, 4, 2, 3, 6, 5, 8, 7};
	printf("\nThe original data:\n");
	for (int i = 0; i < N; i++)
		printf("% 4d", b[i]);
	printf("\n");
	fun(b, N);
	printf("\nThe data after mocinng \n");
	for (int i = 0; i < N; i++)
		printf("% 4d", b[i]);
	printf("\n");

	system("pause");
	return 0;
}
