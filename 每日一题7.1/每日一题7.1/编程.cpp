/*
1. 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

【题目解析】：不使用+运算符进行加法运算
【解题思路】：
数字的相加可以转换为二进制的加法，注意每一位相加与进位即可
1. 两个数异或：相当于每一位相加，而不考虑进位；
*/
class Solution {
public: 
	int Add(int num1, int num2) {
		while (num2 != 0){
			int sum = num1 ^ num2; //得到相加后不包含进位的数据 
			int carray = (num1 & num2) << 1; //得到两数相加的进位 
			num1 = sum; //两个结果相加，直到进位为0 
			num2 = carray; 
		}
		return num1; 
	} 
};
/*
2. 三角形
给定三条边，请你判断一下能不能组成一个三角形。
输入描述： 输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10^100）。
输出描述： 对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No

【题目解析】：需要了解三角形的组成条件：任意两边相加大于第三边
【解题思路】：对输入的三个数字分别进行两两相加与另一个数进行比较
*/
#include <iostream> 
#include <string> 
using namespace std;
#define ADD(x, y) ((x) + (y)) 
#define CMP(x, y) ((x) > (y)) 
int main() { 
	double a, b, c; 
	while (cin >> a >> b >> c) { 
		//对两边进行求和与第三遍进行比较 
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) { 
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
