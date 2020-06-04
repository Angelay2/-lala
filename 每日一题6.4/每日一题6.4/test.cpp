#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class A{
public:
	A(char* s){
		cout << s << endl;
	}
	~A(){};
};
class B :virtual public A{
public:
	B(char* s1, char* s2) :A(s1){
		cout << s2 << endl;
	}
};
class C :virtual public A{
public:
	C(char* s1, char* s2) : A(s1){
		cout << s2 << endl;
	}
};
class D :public B, public C{
public:
	D(char* s1, char* s2, char* s3, char*s4) :B(s1, s2), C(s1, s3), A(s1){
		cout << s4 << endl;
	}
};
int main3(){
	D* p = new D("class A", "class B", "class C", "class D"); //����ӡ���Ϊclass A....class D
	delete p;

	system("pause");
	return 0;
}

/*
a��&aָ�����ͬһ���ַ��������+1���Ч����ͬ��
a+1��һ��Ԫ�ص��ڴ��С�����4������&a+1��ӵ�������������ڴ��С����� 4 * 5 = 20����
*/
int main2(){
	int a[5] = { 1, 3, 5, 7, 9 };
	int* p = (int*)(&a + 1); // �����������С 0x14 = 20
	printf("%d, %d\n", *(a + 1), *(p - 1)); // p-1 = &a[4], aִ�е��Ǽӷ�, ���Բ���, ��a+1=&a[1]

	system("pause");
	return 0;
}

/*
ÿһ����n^2����
   					 8
			7					6
		6		5			5		4
	5	 4	 4	  3		  4   3	  3	  2
*/
int cnt = 0;
int fid(int n){
	cnt++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 2;
	return fid(n - 1) + fid(n - 2);
}
int main1(){
	fid(8);

	printf("%d\n", cnt);

	system("pause");
	return 0;
}