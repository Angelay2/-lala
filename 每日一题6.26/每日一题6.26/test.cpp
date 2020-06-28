#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <iostream>
using namespace std;

struct Date{
	char a;
	int b;
	int64_t c;
	char d;
};
int main(){
	Date data[2][10];
	printf("%p\n", &data);
	printf("%p\n", &data[1][5].c);// 相减为170 化为10进制为368
	//printf("%x", &(data[1][5].c) - &data);


	system("pause");
	return 0;
}
int main1(){
	int m = 5;
	if (m++ > 5)
		cout << m << endl; 
	else
		cout << --m;// 5

	system("pause");
	return 0;
}
