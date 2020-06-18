#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#pragma warining(disable:4996)

class D{
public:
	D(){
		cout << "default constructor" << " ";
	}
	~D(){
		cout << "destructed" << " ";
	}
	D(int i) :data(i){
		cout << "constructed by parameter" << data << " ";
	}
private:
	int data;
};
D Play(D b){
	return b;
}
int main6(int argc, char* argv[]){
	
	D temp = Play(5); // constructed by parrameter5 destructed

	system("pause");
	return 0;
}

int main5(){
	int i, a[10];
	for (i = 9; i >= 0; i--)
		a[i] = 10 - i; // a[9] = 1, a[8] = 2, a[7] = 3, a[6] = 4...
	printf("%d%d%d", a[2], a[5], a[8]);// 8,5,2

	system("pause");
	return 0;
}
class A{
public:
	virtual void print(){
		cout << "A::print()" << "\n";
	}
};
class B :public A{
public:
	virtual void print(){
		cout << "B::print()" << "\n";
	}
};
class C :public A{
public:
	virtual void print(){
		cout << "C::print()" << "\n";
	}
};
void print(A a){
	a.print();
}
int main4(){
	A a, *aa, *ab, *ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print(); // A::print()
	b.print(); // B::print()
	c.print(); // C::print()
	aa->print(); // A::print()
	ab->print(); // B::print()
	ac->print(); // C::print()
	print(a); // A::print()
	print(b); // A::print()
	print(c); // A::print()

	system("pause");
	return 0;
}
int main3(){
	int i = 1;
	int* p = &i;
	cout << sizeof(i) << ',' << sizeof(p) << endl;// 32位下 4,4 / 64位下 4,8

	system("pause");
	return 0;
}
int main2(){
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	printf("%d %d %d %d", i, a, b, c);// 1,2,2,3
	
	system("pause");
	return 0;
}

struct str_t{
	long long len;
	char data[32];
};
struct data1_t{
	long long len;
	int data[2];
};
struct data2_t{
	long long len;
	char* data[1];
};
struct data3_t{
	long long len;
	void* data[];
};
int main1(){
	struct str_t str;
	memset((void*)&str, 0, sizeof(struct str_t));
	str.len = sizeof(struct str_t) - sizeof(int);
	_snprintf_s(str.data, str.len, "hello");

	// 除了A没有崩掉 其他都可以打出data: hellohello
	// A
	/*struct data2_t* pData1 = (struct data2_t*)&str;
	printf("data:%s%s\n", str.data, (char*)(pData1->data[0]));*/
	// B
	struct data1_t* pData2 = (struct data1_t*)&str;
	printf("data:%s%s\n", str.data, (char*)(pData2->data));
	// C
	struct data3_t* pData3 = (struct data3_t*)&str;
	printf("data:%s%s\n", str.data, (char*)(&(pData3->data[0])));
	// D
	struct str_t* pData = (struct str_t*)&str;
	printf("data:%s%s\n", str.data,	(char*)(pData->data));

	system("pause");
	return 0;
}