#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#pragma warning(disable:4996)
using namespace std;
#pragma pack(4)
struct A{
	int a;
	short b;
	int c;
	char d;//13
};
struct B{
	int a;
	short b;
	char c;
	int d;//12
};
int main(){
	printf("%d\n", sizeof(A));// 16
	printf("%d\n", sizeof(B));// 12

	system("pause");
	return 0;
}
//class A{
//public:
//	void foo(){
//		printf("1");
//	}
//	virtual void fun(){
//		printf("2");
//	}
//};
//class B : public A{
//public:
//	void foo(){
//		printf("3");
//	}
//	void fun(){ 
//		printf("4");
//	}
//};
//int main5(void){
//	A a;
//	B b;
//	A* p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//	A* ptr = (A*)&b;
//	ptr->foo();
//	ptr->fun();
//
//	system("pause");
//	return 0;
//}
//class A{
//public:
//	virtual void func(int val = 1){
//		cout << "A->" << val << endl;
//	}
//	virtual void test(){ // 1
//		func();
//	}
//};
//class B :public A{
//public:
//	void func(int val = 0){ // 2
//		std::cout << "B->" << val << endl;
//	}
//};
//int main4(int argc, char* argv[]){
//	B* p = new B;
//	p->test(); // B->1
//
//	system("pause");
//	return 0;
//}

int foo(int n){
	if (n < 2){
		return n;
	}
	else
		return 2 * foo(n - 1) + foo(n - 2);
}
int main3(){
	cout << foo(5);//29

	system("pause");
	return 0;
}
int main2(){
	int x = 3, y = 3;
	switch (x % 2){
	case 1:switch (y){
	case 0:cout << "first";
	case 1:cout << "second";
		break;
	default:cout << "hello";
	}
	case 2:cout << "third";
	}

	system("pause");// hellothird
	return 0;
}
#define N 5
int x[N];
int count = 0;
void dump(){
	int i = 0;
	for (int i = 0; i < N; i++){
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b){
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}
void run(int n){
	int i;
	int count = 0;
	if (N - 1 == n){
		dump();
		count++;
		return;
	}
	for (i = n; i < N; i++){//
		swap(n, i);//
		run(n + 1);
		swap(n, i);//3¸ön
	}
}

int main1(){
	int i;
	int count = 0;
	for (i = 0; i < N; i++){
		x[i] = i + 1;
	}
	run(0);
	printf("*Total: %d\n", count);

	system("pause");
	return 0;
}