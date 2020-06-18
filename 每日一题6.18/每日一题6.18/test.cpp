#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	//int i = 3;
	//printf("%d %d", ++i, ++i);// 5 5
	double b = 0;
	if (b == 0.0){
		printf("可以\n");
	}

	system("pause");
	return 0;
}
class A{
public:
	void FuncA(){
		printf("FuncA called\n");// 1 3
	}
	virtual void FuncB(){
		printf("FuncB called\n");// 4
	}
};
class B :public A{
public:
	void FuncA(){
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB(){
		printf("FuncBB called\n");// 2
	}
};
int main6(){
	B b;
	A* pa;
	pa = &b;
	A* pa2 = new A;
	pa->FuncA();
	pa->FuncB();
	pa2->FuncA();
	pa2->FuncB();
	delete pa2;

	system("pause");
	return 0;
}
//class Widget{
//public:
//	Widget(){}
//	Widget f(Widget u){
//		Widget v(u);
//		Widget w = v;
//		return w;
//	}
//	Widget(const int& f){
//		cout << "a" << endl;
//		//整个程序分别在,x初始化u、u初始化v、v初始化w、w返回时，
//		//注意w返回时初始u不在调用拷贝构造函数，第二次调用 f() 函数时，相当于u的结合会少调用一次，其他不变，
//		//所以总体次数为4+3 = 7次
//	}
//};
//int main(){
//	Widget x;
//	Widget y = f(f(x));
//
//	system("pause");
//	return 0;
//}
class Base{
public:
	virtual int foo(int x){
		return x * 10;
	}
	int foo(char x[14]){// 2
		return sizeof(x) + 10;// x的类型为char*指针
	}
};
class Derived :public Base{
	int foo(int x){// 1
		return x * 20;
	}
	virtual int foo(char x[10]){
		return sizeof(x) + 20;
	}
};
int main5(){
	Derived stDerived;
	Base* pstBase = &stDerived;

	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x));// 2014

	system("pause");
	return 0;
}

int main4(){
	const int a = 10;
	int* p = (int*)(&a);
	*p = 20;
	cout << "a = " << a << ", *p = " << *p << endl;// a = 10, *p = 20 相当于拷贝, 并不会改变a值,

	system("pause");
	return 0;
}
void swap_int(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main3(){
	int str1 = 1;
	int str2 = 3;
	int* a = &str1;
	int* b = &str2;
	swap_int(a, b);

	printf("%d, %d\n", str1, str2);// 3, 1
	system("pause");
	return 0;
}
//void print(char* s){
//	if (*s){
//		print(++s);
//		printf("%c", *s);// 空格suiene (第一个打印的是0,转为字符为空格)
//	}
//}
//int main2(){
//	char str[] = "Geneius";
//	print(str);
//
//	system("pause");
//	return 0;
//}

//struct Test{
//public:// 不关乎这里的public, 有无都可
//	Test(int){}
//	Test(){}
//	void fun(){}
//};
//int main1(){
//	Test a(1);
//	a.fun();
//	//Test b();// 错误
//	Test b;// 才对
//	b.fun();
//
//	system("pause");
//	return 0;
//}
