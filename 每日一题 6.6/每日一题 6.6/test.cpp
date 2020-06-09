#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int f(int n){
	if (n == 1)
		return 1;
	else
		return (f(n - 1) + n*n*n);// 1,9,9+27=36
}
int main(){
	int s = f(3);
	cout << s << endl;
	system("pause");
	return 0;
}
struct A{
	long a1;// 4
	short a2;// 2 -->6
	int a3;// 4 -->12
	int* a4;//4 -->16
};
int main4(){
	printf("%d\n", sizeof(long)); // 4

	printf("%d\n", sizeof(A)); // 16
	system("pause");
	return 0;
}
int main3(){
	char a = 0, ch;
	while ((ch = getchar()) != '\n'){
		// 偶数位变大写, 奇数位不变
		if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
			ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	}
	printf("\n");

	system("pause");
	return 0;
}
char fun(char x, char y){
	if (x < y)
		return x;
	return y;
}
int main2(){
	int a = '1', b = '1', c = '2';
	cout << fun(fun(a, b), fun(b, c)); // fun(1,1) = 1
	system("pause");
	return 0;
}
int main1(){
	int m = 0123, n = 123; // m = 83, n = 123
	printf("%o %o\n", m, n);// 83-64=19-2*8=3 123, 123-64=59-7*8=3 173
	system("pause");
	return 0;
}