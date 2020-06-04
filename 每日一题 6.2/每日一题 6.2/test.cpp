#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Sample{
public: 
	Sample(int x){
		//p = &x;// 
		//p = new int(x);
		//*p = new int(x); // 无法从int*转换为int
		*p = x; // 崩了 这是要写入的样子 修改值为x的样子  写入地址冲突
	}
	~Sample(){
		if (p)
			delete p;
	}
	int show(){
		return *p;
	}
private:
	int* p;
};
void test(){
	Sample S(5);
	cout << S.show() << endl;
}
void test1(){
	char acx[] = "abc";// 里面有四个 a b c 0
	char acy[] = { 'a', 'b', 'c' };// 里面只有三个 a b c 
	printf("%d, %d\n", sizeof(acx), sizeof(acy));// 4, 3
	char* szx = "abc";
	char* szy = "abc"; // szx与szy指向同一个地址
	szx++;
}
void sss(char[], int[]){

}
void test2(){
	int a[10];
	char b[80];
	sss(b, a);
}
void test3(){

	float a[3][4] = { 1, 3, 4, 5, 2 };
	int i = 1, j = 0;
	printf("%d\n", *(*a + i) + j);
	printf("%d\n", *(a[i] + j));
	printf("%d\n", *(a + i * 4 + j));
	printf("%d\n", a[i][j]);

}



int main2(){
	test3();
	system("pause");
	return 0;
}
int main1(){

	int a[] = { 1, 2, 3, 4 };
	int* b = a; // 等于&a[0]
	*b += 2;// a[0] = 3
	*(b + 2) = 2;// a[2] = 2
	b++;// b = &a[1]
	printf("%d, %d\n", *b, *(b + 2)); // 2, 4

	system("pause");
	return 0;
}