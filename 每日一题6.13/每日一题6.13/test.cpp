#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
using namespace std;
void fun(const int& v1, const int& v2){
	cout << v1 << ' ';
	cout << v2 << ' ';
}
int main(int argc, char* argv){
	int i = 0;
	fun(++i, i++);

	system("pause");
	return 0;
}

#define SQR(A) A*A
int main4(){
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z); // /的优先级大于/=, y+z*y+z/y+z*y+z = 3+6+3/2+6+2=  
	// 先执行(z*y+y)+(z/y)+z ; 再z*y, 最终结果相加 = 9+2/3+2 = 11+2/3 +z*y = 17+2/3
	cout << x << endl; // 0

	system("pause");
	return 0;
}
class Base{
public:
	int Bar(char x){
		return (int)(x);
	}
	virtual int Bar(int x){
		return (2 * x);
	}
};
class Derived :public Base{
public:
	int Bar(char x){
		return (int)(-x);
	}
	int Bar(int x){
		return (x / 2);
	}
};
int main3(){
	Derived Obj;
	Base* pObj = &Obj;
	printf("%d, ", pObj->Bar((char)(100)));
	printf("%d, ", pObj->Bar(100));

	system("pause");
	return 0;
}
int main2(){
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl; // 10,20,30

	system("pause");
	return 0;
}
//class myClass{
//public:
//	myclass(int y){}
//	~myclass(){
//
//	}
//private:
//	int y;
//};
//myClass::~myclass(){
//	delete this;
//	this = NULL;
//}
struct st_task{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};
void fool(){
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%llu, %llu, %llu", task.id, task.value, task.timestamp); // 1, 0 , 0
}
int main1(){
	fool();

	system("pause");
	return 0;
}