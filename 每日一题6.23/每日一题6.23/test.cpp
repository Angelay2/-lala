#include <stdio.h>
#include <stdlib.h>
#include <iostream>

bool fun(int n){// Sum=[(1+(2n-1))n]/2=n^2  ʵ���ж�һ�����Ƿ�Ϊ��ȫƽ����
	int sum = 0;
	for (int i = 1; n > sum; i = i + 2)
		sum = sum + i;
	return (n == sum);
}
int main1(){
	printf("%d\n",fun(484));
	system("pause");
	return 0;
}