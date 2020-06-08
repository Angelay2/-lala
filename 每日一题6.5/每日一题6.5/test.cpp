#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class B0{
public:
	virtual void display(){
		cout << "B0::dispaly0" << endl;
	}
};
class B1:public B0{// 公有派生
public:
	void display(){
		cout << "B1::display0" << endl;
	}
};
class D1 :public B1{// 公有派生
public:
	void display(){
		cout << "D1::display0" << endl;
	}
};
void fun(B0 ptr){// 普通函数
	ptr.display(); // 打印了三个"B0::dispaly0"
}
int main8(){// 主函数
	B0 b0;// 声明基类对象和指针
	B1 b1;// 声明派生类对象
	D1 d1;// 声明派生类对象
	fun(b0);//调用基类B0函数成员
	fun(b1);//调用派生类B1函数成员
	fun(d1);//调用派生类D1函数成员

	system("pause");
	return 0;
}


#pragma pack(8)
struct one{
	double d;
	char c;
	int i;
};
struct two{
	char c;
	double d;
	int i;
};
int main7(){
	printf("%d, %d\n", sizeof(one), sizeof(two));// pack(4)时 打印出16,16;  pack(8)时 打印 16,24

	system("pause");
	return 0;
}

//int main6(){
//	int x = 1;
//	do{
//		printf("%2d\n", x++);// x=1
//	} while (x--);// x=0    // 死循环
//}
int main5(){
	int n[][3] = { 10, 20, 30, 40, 50, 60 };// n[0][0]~n[0][2], n[1][0]~n[1][2]
	int(*p)[3];// 数组指针, 指针里有三个元素
	p = n;// *p[0]=p[0][0]=n[0][0]=10,p[0][1]=n[0][1]=20..p[1][0]=n[1][0]=40, 第二个[]相当于解引用
	// *p = p = p[0]
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl; // 10,20,30 
	// *p = p[0][0], 


	system("pause");
	return 0;
}
class A{
	void test(float a){
		cout << "1";
	};
};
class B:public A{
	void test(int b){
		cout << "2";
	}
};
int main4(){
	A* a = new A;
	B* b = new B;
	a = b;
	//a.test(1, 1);// ".test”的左边必须有类/结构/联合

	system("pause");
	return 0;
}
int main3(){
	int a;
	float b, c;
	scanf("%2d%3f%4f", &a, &b, &c);
	printf("\na = %d, b=%d,c=%f\n", a, b, c);// a= 98,b=0,c=0.000000

	system("pause");
	return 0;
}
int main2(){
	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s", str); // xycdBCD

	system("pause");
	return 0;
}

int main1(){
	// %5.3s， 表示输出总长度是5，取字符串的前3个输出。
	// 所以输出COM，但是COM的长度又不够5，所以，在COM的前面补了2个空格，刚好是5
	printf("%s,%5.3s\n", "computer", "computer");  // computer,  com 
	// 小数点后代表要打印几位

	system("pause");
	return 0;
}