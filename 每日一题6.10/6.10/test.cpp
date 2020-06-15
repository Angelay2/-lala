#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int fun(int a){
	a ^= (1 << 5) - 1;// a ^= 32-1=31   
	return a;
}
int main(){

	cout << fun(21) << endl;
	// 21 = 1 0101  31 = 1 1111 相同结果为0 ===> 0 1010 = 10
	system("pause");
	return 0;
}

// 取对象地址!=第一个成员变量的地址, &obj+1 = 第一个变量的地址(&obj.a) , &obj+2 = 第二个成员变量的地址(&obj.b)
class Test{
public:
	int a;
	int b;
	virtual void fun(){}
	Test(int temp1 = 0, int temp2 = 0){
		a = temp1;
		b = temp2;
	}
	int getA(){
		return a;
	}
	int getB(){
		return b;
	}
};
int main3(){
	Test obj(5, 10); // a = 5, b = 10
	// changing a and b
	int* pInt = (int*)&obj;// pInt = &obj != &obj.b != &obj.a  pInt + 1 = &obj.a
	*(pInt + 0) = 100; // *pInt = 100
	*(pInt + 1) = 200; // a = 200
	// *(pInt + 2) = -1; // b = -1
	cout << "a = " << obj.getA() << endl; // a = 200
	cout << "b = " << obj.getB() << endl; // b = 10

	system("pause");
	return 0;
}
void func(char** m){
	++m;
	cout << *m << endl; // afternoon
}
int main2(){
	static char* a[] = { "morning", "aftrernoon", "evening" };
	char** p;
	p = a; // p = &a[1]
	func(p);

	system("pause");
	return 0;
}
class Myclass{
public:
	Myclass(int i = 0){
		cout << 1;
	}
	Myclass(const Myclass& x){
		cout << 2;
	}
	Myclass& operator=(const Myclass& x){
		cout << 3;
		return *this;
	}
	~Myclass(){
		cout << 4 << endl; // 调3次
	}
};
int main1(){
	Myclass obj1(1), obj2(2), obj3(obj1); // 112

	system("pause");
	return 0;
}