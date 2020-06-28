#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
 
int main8(){
	char* ptr;
	char myString[] = "abcdefg";
	ptr = myString;
	ptr += 5;

	printf("%s", ptr);
	system("pause");
	return 0;
}
int main7(){
	char* p = "abc";
	char* q = "abc123";
	while (*p = *q)
		printf("%c %c", *p, *q);

	system("pause");
	return 0;
}
int main6(){
	int a[] = { 1, 2, 3, 4, 5 };
	int* p[] = { a, a + 1, a + 2, a + 3 };
	int **q = p;
	printf("%d\n", *(p[0] + 1) + **(q + 2));// 5

	system("pause");
	return 0;
}
class A{
public:
	A(){
		p();
	}
	virtual void p(){ printf("A"); }
	virtual ~A(){ p(); }
};
class B :public A{
public:
	B(){
		p();
	}
	void p(){
		printf("B");
	}
	~B(){ p(); }
};
int main5(){
	A* a = new B();
	delete a;

	system("pause");
	return 0;
}
int main(){
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c); // 1 0 2
	system("pause");
	return 0;
}
//class A{
//public:
//	~A(){
//		cout << "~A()";
//	}
//};
//class B{
//public:
//	virtual ~B(){
//		cout << "~B()";
//	}
//};
//class C: public A, public B{
//public:
//	~C(){
//		cout << "~C()";
//	}
//};
//int main2(){
//	C* c = new C;
//	B* b1 = dynamic_cast<B*>(c);
//	A* a2 = dynamic_cast<A*>(b1);
//	delete a2;
//	// 输出了~A()就崩掉了
//	system("pause");
//	return 0;
//}
//template<class T>
//struct sum{
//public:
//	static void foo(T op1, T op2){
//		cout << op1 << op2;
//	}
//private:
//	int op1;
//	int op2;
//};
//sum<int>:: foo(1, 3);
// 找出了字符串长度最短的字符串，并输出其长度
#define M 5
#define N 20
int fun(char(*ss)[N], int* n){
	int i, k = 0, len = N;
	for (i = 0; i < M; i++){
		len = strlen(ss[i]);
		if (i == 0)
			*n = len;
		if (len < *n){
			*n = len;
			k = i;
		}
	}
	return k;
}
int main1(){
	char ss[M][N] = { "shanghai", "guangzhou", "beijing", "tianjing", "chongqing" };
	int n, k, i;
	printf("\nThe originalb stringsare:\n");
	for (i = 0; i < M; i++)
		puts(ss[i]);
	k = fun(ss, &n);
	printf("\nThe length of shortest string is: %d\n", n);// 7
	printf("\nThe shortest string is: %s\n", ss[k]);// beiging
	
	system("pause");
	return 0;
}

