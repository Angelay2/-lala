#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#pragma warning(disable:4996)
using namespace std;


class Printer{
public:
	ostream operator<<(string s){

	}
	Printer(std::string name){
		cout << name; // 打印ab
	}
};
class Container{
public:
	Container()
		: b("b")
		, a("a"){}
	Printer a;
	Printer b;
};
int main6(){
	Container c;

	system("pause");
	return 0;
}

struct A{
	void foo(){
		printf("foo"); // 2
	}
	virtual void bar(){
		printf("bar"); // 1
	}
	A(){
		bar();
	}
};
struct B:A{
	void foo(){
		printf("b_foo");
	}
	void bar(){
		printf("b_bar"); // 3
	}
};
int main5(){
	A* p = new B;
	p->foo();
	p->bar(); // 最终输出barfoob_bar

	system("pause");
	return 0;
}
int fun(int x){ 
	int count = 0;
	while (x){
		count++;
		x = x&(x - 1);// 与运算 : 0&0=0;0&1=0;1&0=0;1&1=1
		// 10011100001111 & 10011100001110 = 10011100001110
		// 10011100001110 & 10011100001101 = 10011100001100
		// 10011100001100 & 10011100001011 = 10011100001000
		// 每次消1, 8个1, 消8次 循环8次 count = 8
	}
	return count;
}
int main4(){
	cout << fun(9999); // 8
	system("pause");
	return 0;
}
template<class T>
class Foo{
	T tvar;
public:
	Foo(T t) :tvar(t){}
};
template<class T>
class FooDerived :public Foo<T>{
	/*FooDerived(int n){

	}*/
};
int main3(){
	// FooDerived<int> d(5);// 没有与参数匹配的构造函数

	system("pause");
	return 0;
}

int fun1(int n){
	if (n == 5)
		return 2;
	else
		return 2 * fun(n + 1); 
	// n = 5 --> fun(5) = 2
	// n = 4 --> fun(4) = 2*fun(5) = 2*2 = 4
	// n = 3 --> fun(3) = 2*fun(4) = 2*4 = 8
	// n = 2 --> fun(2) = 2*fun(3) = 2*8 = 16
}
int main2(){
	int s = fun(2);
	system("pause");
	return 0;
}
/*
%可以理解为一个转义符（像\一样), %%前面的%告诉（编译）系统后面的%是字符%，系统是由前到后处理的，故d前面的%被系统认为是字符而不具备转义功能
*/
int main1(){
	int I = 1;
	if (I <= 0)
		printf("****\n");// ****
	else
		printf("%%%%%d\n", I);// %%1
	// printf("%%%%d\n", I);// %%d  
	// printf("%%%%%\n", I);// %%

	system("pause");
	return 0;
}