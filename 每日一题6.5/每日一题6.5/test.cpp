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
class B1:public B0{// ��������
public:
	void display(){
		cout << "B1::display0" << endl;
	}
};
class D1 :public B1{// ��������
public:
	void display(){
		cout << "D1::display0" << endl;
	}
};
void fun(B0 ptr){// ��ͨ����
	ptr.display(); // ��ӡ������"B0::dispaly0"
}
int main8(){// ������
	B0 b0;// ������������ָ��
	B1 b1;// �������������
	D1 d1;// �������������
	fun(b0);//���û���B0������Ա
	fun(b1);//����������B1������Ա
	fun(d1);//����������D1������Ա

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
	printf("%d, %d\n", sizeof(one), sizeof(two));// pack(4)ʱ ��ӡ��16,16;  pack(8)ʱ ��ӡ 16,24

	system("pause");
	return 0;
}

//int main6(){
//	int x = 1;
//	do{
//		printf("%2d\n", x++);// x=1
//	} while (x--);// x=0    // ��ѭ��
//}
int main5(){
	int n[][3] = { 10, 20, 30, 40, 50, 60 };// n[0][0]~n[0][2], n[1][0]~n[1][2]
	int(*p)[3];// ����ָ��, ָ����������Ԫ��
	p = n;// *p[0]=p[0][0]=n[0][0]=10,p[0][1]=n[0][1]=20..p[1][0]=n[1][0]=40, �ڶ���[]�൱�ڽ�����
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
	//a.test(1, 1);// ".test������߱�������/�ṹ/����

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
	// %5.3s�� ��ʾ����ܳ�����5��ȡ�ַ�����ǰ3�������
	// �������COM������COM�ĳ����ֲ���5�����ԣ���COM��ǰ�油��2���ո񣬸պ���5
	printf("%s,%5.3s\n", "computer", "computer");  // computer,  com 
	// С��������Ҫ��ӡ��λ

	system("pause");
	return 0;
}