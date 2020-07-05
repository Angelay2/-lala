/*
1. 【二进制插入】 有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。 给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
【题目解析】：
本题考察位运算
【解题思路】：
i j
m:1024：100000000 00 n:19 ： 10011 要把n的二进制值插入m的第j位到第i位，只需要把n先左移j位，然
后再进行或运算（|）即可。
m: 10000000000
n: 00001001100
10001001100
*/
class BinInsert{ 
public: 
	int binInsert(int n, int m, int j, int i){ 
		m <<= j; 
		return n | m; 
	} 
};
/*
【查找组成一个偶数最接近的两个素数】任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素 数差值最小的素数对
输入描述： 输入一个偶数
输出描述： 输出两个素数
【解题思路】：
本题首先需要判断素数，素数表示除过1和本身，不能被其它数整除。通过循环遍历来判断一个数是否为素
数。最近的两个素数应该从最中间的位置开始向两边查找。
*/
#include<iostream> 
#include<algorithm> 
using namespace std; 
//判断素数
bool isPrime(int num){
	int tmp = sqrt(num); 
	//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除 
	for(int i = 2; i <= tmp; i++){ 
		if(num %i == 0) 
			return false; 
	}
	return true; 
}
int main(){ 
	int num; 
	int half; 
	int i; 
	while(cin >> num){ 
		half = num / 2; 
		//从中间向两边找 
		for(i = half; i > 0; i--){ 
			if(isPrime(i) && isPrime(num - i))
				break; 
		}
		cout << i << endl << num - i << endl;
	}
	return 0; 
}