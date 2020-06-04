#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class A{
public:
	A(char* s){
		cout << s << endl;
	}
	~A(){};
};
class B :virtual public A{
public:
	B(char* s1, char* s2) :A(s1){
		cout << s2 << endl;
	}
};
class C :virtual public A{
public:
	C(char* s1, char* s2) : A(s1){
		cout << s2 << endl;
	}
};
class D :public B, public C{
public:
	D(char* s1, char* s2, char* s3, char*s4) :B(s1, s2), C(s1, s3), A(s1){
		cout << s4 << endl;
	}
};
int main3(){
	D* p = new D("class A", "class B", "class C", "class D"); //最后打印结果为class A....class D
	delete p;

	system("pause");
	return 0;
}

/*
a和&a指向的是同一块地址。但他们+1后的效果不同。
a+1是一个元素的内存大小（添加4），而&a+1添加的是整个数组的内存大小（添加 4 * 5 = 20）。
*/
int main2(){
	int a[5] = { 1, 3, 5, 7, 9 };
	int* p = (int*)(&a + 1); // 加整个数组大小 0x14 = 20
	printf("%d, %d\n", *(a + 1), *(p - 1)); // p-1 = &a[4], a执行的是加法, 所以不变, 则a+1=&a[1]

	system("pause");
	return 0;
}

/*
每一行有n^2的数
   					 8
			7					6
		6		5			5		4
	5	 4	 4	  3		  4   3	  3	  2
*/
int cnt = 0;
int fid(int n){
	cnt++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 2;
	return fid(n - 1) + fid(n - 2);
}
int main1(){
	fid(8);

	printf("%d\n", cnt);

	system("pause");
	return 0;
}