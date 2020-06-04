#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++){
		if (*itor == 300){
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++){
		cout << *itor << " ";
	}

	system("pause");
	return 0;
}

int main4(){
	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' }, *p;
	int i;
	i = 8;
	p = a + i;
	
	printf("%s\n", p - 3);
	system("pause");
	return 0;
}


int func(){
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; j++){
		k++;
	}
	return k;
}
int main3(){
	cout << (func());
	system("pause");
	return 0;
}

//int add(int a, int b){
//	int a = 9;
//	int b = 4;
//	return a, b;
//}
//int a = 0;
//int b = 9;
int main2(){
	int a = 3;
	int b = 2;
	printf("%d %d\n", a, b);

	system("pause");
	return 0;
}
//int main1(){
//	int a[2][4] = { { 0, 1, 2 }, { 3, 4 }, { 5 } }; // 初始值设置太多
//	int a[][3] = { { 0, 1, 2 }, { 3, 4, 5 } };
//	int a[][3] = { { 0, ,2 }, {}, { 3, 4, 5 } };
//	int a[2][] = { { 0, 1, 2 }, { 3, 4, 5 } };
//
//}