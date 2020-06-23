#include <stdio.h>
#include <stdlib.h>
#include <iostream>

bool fun(int n){
	int sum = 0;
	for (int i = 1; n > sum; i = i + 2)
		sum = sum + i;
	return (n == sum);
}
int main(){
	printf("%d\n",fun(484));
	system("pause");
	return 0;
}