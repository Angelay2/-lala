#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

static int a = 1;
void fun1(){
	a = 2;// 这个才对a进行了重新赋值
}
void fun2(){
	int a = 3;// 局部变量
}
void fun3(){
	static int a = 4;// 局部变量
}
int main(){
	printf("%d", a);// 1
	fun1();
	printf("%d", a);// 2
	fun2();
	printf("%d", a);// 2
	fun3();
	printf("%d", a);// 2

	system("pause");
	return 0;
}
class A{
public:
	A(){
		printf("A ");
	}
	~A(){
		printf("deA ");
	}
};
class B{
public:
	B(){
		printf("B ");
	}
	~B(){
		printf("deB ");
	}
};
class C :public A, public B{
public:
	C(){
		printf("C ");
	}
	~C(){
		printf("deC ");
	}
};
int main3(){
	A* a = new C();
	delete a;// A B C deA

	system("pause");
	return 0;
}
//class A{
//public:
//	void f(){
//		printf("A\n");
//	}
//};
//class B :public A{
//public:
//	virtual void f(){
//		printf("B\n");
//	}
//};
//int main2(){
//	A* a = new B;
//	a->f();
//	delete a;
//
//	system("pause"); // 输出A 然后崩掉
//	return 0;
//}
int FindSubString(char* pch){
	int count = 0;
	char* p1 = pch;
	while (*p1 != '\0'){
		if (*p1 == p1[1] - 1){
			p1++;
			count++;
		}
		else{
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0'){
		if (*p1 == p1[1] + 1){
			p1++;
			count2--;
		}
		else{
			break;
		}
	}
	if (count2 == 0)
		return count;
	return 0;
}
void ModifyString(char* pText){
	char* p1 = pText;
	char* p2 = p1;
	while (*p1 != '\0'){
		int count = FindSubString(p1);
		if (count > 0){
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while (*p2 != '\0'){
				p2++;
			}
			p1 += count + count + 1;
		}
		else{
			*p2++ = *p1++;
		}
	}
}
int main1(){
	char test[32] = "XYBCDCBABABA";
	ModifyString(test);
	printf(test);//  XYBCDCBA1BAA

	system("pause");
	return 0;

}