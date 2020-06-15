#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class parent{
	int i;
protected:
	int x;
public:
	parent(){
		x = 0;
		i = 0;
	}
	void change(){
		x++;
		i++;
	}
	void display();
};
class son:public parent{
public:
	void modify();
};
void parent::display(){
	cout << "x = " << x << endl;
}
void son::modify(){
	x++;
}
int main6(){
	son A;
	parent B;
	A.display();// x= 0
	A.change();
	A.modify();
	B.display(); // x= 0
	B.change();
	B.display(); // x= 1

	system("pause");
	return 0;

}
int main5(){
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
	if (b != 2 || c-- != 3)
		printf("%d, %d,%d\n", a, b, c);
	else
		printf("%d, %d,%d\n", a, b, c);
	else
		printf("%d, %d,%d\n", a, b, c);
	system("pause"); // 1,3,3
	return 0;

}
int main4(){
	int a = 1, b = 0, c = -1, d = 0;
	d = ++a || ++b && ++c; // a = 2, b = 0, c= -1
	cout << d << endl; // 1
	system("pause");
	return 0;
}

template<class T>
class Bignumber{
	long n;
public:
	Bignumber(T i) :n(i){}
	Bignumber operator+(Bignumber b){
		return Bignumber(n + b.n);
	}
};
int main3(){
	Bignumber<int> v = 2;
	Bignumber<int> v2 = 4;
	Bignumber<int> ret = v + v2;
	Bignumber<int> ret2 = v + 3;
	Bignumber<int> ret3 = 3 + 3; // 这三都能过
	//Bignumber<int> ret4 = 3 + v2;// 没有与 int + Bignubmer<int> 匹配的运算符重载, 

	system("pause");
	return 0;
}
int p[][4] = { { 1 }, { 3, 2 }, { 4, 5, 6 }, { 0 } };

class A{
	friend long fun(A s){
		if (s.x < 3){
			return 1;
		}
		return s.x + fun(A(s.x - 1));
	}
public:
	A(long a){
		x = a--;
	}
private:
	long x;
};
int main2(){
	printf("%d", p[1][2]); // 0

	int sum = 0;
	for (int i = 0; i < 5; i++){
		sum += fun(A(i));
	}
	cout << sum; // 15
	system("pause");
	return 0;
}
class B{
public:
	B(int aa, int bb){
		int a = aa--; // 4
		int b = a*bb; // 20
	}
};
void test(){
	B x(4, 5);
}
int main1(){
	test();

	system("pause");
	return 0;
}