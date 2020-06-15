#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;


class cla{
	static int n;
public:
	cla(){
		n++;
	}
	~cla(){
		n--;
	}
	static int get_n(){
		return n;
	}
};
int cla::n = 0;
int main3(){
	cla* p = new cla;
	delete p;
	cout << "n = " << cla::get_n() << endl;

	system("pause");
	return 0;
}
class A{
public:
	A() :m_iVal(0){ test(); }
	virtual void func(){
		std::cout << m_iVal << ' ';
	}
	void test(){
		func();
	}
public:
	int m_iVal;
};
class B :public A{
public:
	B(){
		test();
	}
	virtual void func(){
		++m_iVal;
		std::cout << m_iVal << ' ';
	}
};
int main2(int argc, char* argv[]){
	A* p = new B;
	p->test();

	system("pause");
	return 0;
}
void AlphabetCounting(char a[], int n){
	int count[26] = {}, i, kind = 0;
	for (i = 0; i < n; ++i)(1);
	for (i = 0; i < 26; ++i){
		if (++kind > 1)
			putchar(';');
		printf("%c = %d", (2));
	}
}
int main1(){
	int a[4] = { 1, 2, 3, 4 };
	int* ptr = (int*)(&a + 1); // 加整个数组
	printf("%d", *(ptr - 1)); // 4

	system("pause");
	return 0;
}