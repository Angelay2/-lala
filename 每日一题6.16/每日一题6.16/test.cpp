#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#pragma warning(disable:4996)
using namespace std;

int main6(){
	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??";
	strcpy(ccString1, "No");
	if (strcmp(ccString1, ccString2) == 0)
		cout << ccString2;
	else
		cout << ccString1;// ����� String2 > String1

	system("pause");
	return 0;

}
int main5(){
	char dog[] = "Wang\0miao";
	printf("%d\n", sizeof(dog)); // 10
	printf("%d\n", strlen(dog)); // 4

	system("pause");
	return 0;
}
class Base{
public:
	Base(int j)
		:i(j){} // 2
	virtual ~Base(){}
	void func1(){ // 5
		i *= 10;
		func2(); // 7
	}
	int getValue(){ // 9
		return i;
	}
protected:
	virtual void func2(){
		i++;
	}
protected:
	int i;
};
class Child :public Base{
public:
	Child(int j)
		:Base(j){} // 1 3
	void func1(){
		i *= 100;
		func2();
	}
protected:
	void func2(){ // 6
		i += 2; // 10+2
	}
};
int main3(){
	Base* pb = new Child(1); // 4
	pb->func1();
	cout << pb->getValue() << endl; // 12  8
	delete pb;

	system("pause");
	return 0;
}
int function(unsigned int n){
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}
int main2(){
	printf("%d\n", function(197));// 4, ��ȡ2����ʱ�м���1  197 = 11000101

	system("pause");
	return 0;
}
//class A{
//public:
//	int GetValue() {
//		vv = 1;
//		return vv;
//	}
//private:
//	int vv;
//};
//int main(){
//	A a;
//	int ret = A::GetValue();
//}
//void swap(int* a, int* b){
//	int* tmp = a;
//	a = b;
//	b = tmp;
//}
//void perm(int list[], int k, int m){
//	if (k == m){
//	//if (k != m){
//		copy(list, list + m, ostream_iterator<int>(cout, " "));
//		cout << endl;
//		return;
//	}
//	for (int i = k; i <= m; i++){
//		swap(&list[k], &list[i]);
//		// A
//		perm(list, k + 1, m);
//		// B
//		// perm(list, k, m);
//		// C
//		// perm(list, k + 1, m);//
//		// D
//		//perm(list, k, m);
//		swap(&list[k], &list[i]);
//	}
//}
//int main(){
//	int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int k = 0;
//	int m = sizeof(list) / sizeof(int) - 1 ;
//	perm(list, k, m);
//
//	system("pause");
//	return 0;
//}

/*
reinterpret_cast<new_type> (expression)
reinterpret_cast����������������޹�����֮���ת�����������һ���µ�ֵ�����ֵ������ԭʼ������expression������ȫ��ͬ�ı���λ��
reinterpret_cast��������ָ�루�����ã�����֮���ת�����Լ�ָ�����㹻�����������֮���ת�������������ͣ�����ö�����ͣ���ָ�����ͣ����Ӵ�С��
*/
int main1(){
	char str[] = "glad to test something";
	char* p = str;
	p++;
	int* p1 = reinterpret_cast<int*>(p);// ��һchar*��ָ��ת��Ϊint*��ָ��.
	p1++;// Ȼ��++ ��һ++,�൱��+4�ֽ�, ֱ�ӵ�to
	p = reinterpret_cast<char*>(p1);// ��һ�����ε�ָ��ת��������char*��ָ��, 
	printf("result is %s\n", p);// result is to test something

	system("pause");
	return 0;
}
