#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	//int i = 3;
	//printf("%d %d", ++i, ++i);// 5 5
	double b = 0;
	if (b == 0.0){
		printf("����\n");
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
//		//��������ֱ���,x��ʼ��u��u��ʼ��v��v��ʼ��w��w����ʱ��
//		//ע��w����ʱ��ʼu���ڵ��ÿ������캯�����ڶ��ε��� f() ����ʱ���൱��u�Ľ�ϻ��ٵ���һ�Σ��������䣬
//		//�����������Ϊ4+3 = 7��
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
		return sizeof(x) + 10;// x������Ϊchar*ָ��
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
	cout << "a = " << a << ", *p = " << *p << endl;// a = 10, *p = 20 �൱�ڿ���, ������ı�aֵ,

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
//		printf("%c", *s);// �ո�suiene (��һ����ӡ����0,תΪ�ַ�Ϊ�ո�)
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
//public:// ���غ������public, ���޶���
//	Test(int){}
//	Test(){}
//	void fun(){}
//};
//int main1(){
//	Test a(1);
//	a.fun();
//	//Test b();// ����
//	Test b;// �Ŷ�
//	b.fun();
//
//	system("pause");
//	return 0;
//}
