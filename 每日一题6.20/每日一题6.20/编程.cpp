/*
1. 标题：统计每个月兔子的总数
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔 子都不死，问每个月的兔子总数为多少？ /** * 统计出兔子总数。 ** @param monthCount 第几个月 * @return 兔子总数 */ 
/*public static int getTotalCount(int monthCount) { 
	return 0;
}
输入描述：输入int型表示month 
输出描述： 输出兔子总数int型
【解题思路】：
第n个月的兔子数量由两部分组成，一部分是上个月的兔子f(n-1)，另一部是满足3个月大的兔子，
会生一只兔子f(n-2)。所以第n个月兔子总数： f(n) = f(n - 1) + f(n - 2)。本题是在变相考察斐波那
契数列。
*/
#include <iostream> 
using namespace std;
int main(){
	int month;
	while(cin >> month){
		int first = 1;
		int second = 1;
		int result;
		for(int i = 3; i <= month; ++i){
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	}
	return 0;
}

/*
2.字符串通配符
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。 
要求： 实现如下2个通配符： *：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同） ？：匹配1个字符
输入: 通配符表达式； 一组字符串。
输出： 返回匹配的结果，正确输出true，错误输出false

输入描述： 先输入一个带有通配符的字符串，再输入一个需要匹配的字符串 
输出描述： 返回匹配的结果，正确输出true，错误输出

【解题思路】：
本题可以通过递归求解。从前向后一次匹配，遇到相同字符，都向后移动一个字符，如果通配符
遇到"?"，则不需匹配，自动跳过一个字符，如果通配符遇到"*"，则可以匹配任意多个字符，包括
0个，此时可以有三种选择，1，匹配0个，通配符向后移动一个字符，字符串不动。2，匹配1
个，通配符和字符串都向后移动一个字符。3，匹配多个，通配符不动，字符串向后移动一个字
符。
递归的终止条件：通配符或者字符串遇到'\0'。当他们同时结束。
*/
#include <iostream> 
#include <string> 
using namespace std;
bool match(const char* pattern, const char *str) {
	//当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?') {
		//遇到?号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*') {
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个 字符)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str) {
		//如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main() {
	string pattern, str;
	while (cin >> pattern >> str) {
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}

/*
1. 函数作用：将整型数组p中n个数据增大 
*/
#include <assert.h>
#include <stdio.h>

void increment_ints(int p[], int n) {
	assert(p != NULL); /* 确保p不为空指针 */ 
	assert(n >= 0); /* 确保n不为负数 */ 
	while (n) /* 循环n次. */ { 
		(*p)++; /* 增大p*/
		p++, n--; /* p指向下一位，n减1 */ }
} 
// *p++使得p在解引用之前增大，应该改为(*p)++

/*
2. 下列给定程序中，函数fun的功能是：把形参a所指数组中的最小值放在元素a[0]中，接着把a所指数组中的 最大值放在a[1]元素中;再把a所指数组元素中的次小值放在a[2]中，把a索取数组元素中的次大值放在a[3]，以 此类推。 例如:若a所指数组中的数据最初排列为：9,1,4,2,3,6,5,8,7;按规则移动后，数据排列为:1,9,2,8,3,7,4,6,5。形参 n中存放a所指数组中数据的个数。 规定fun函数中的max存放的当前所找的最大值,px存放当前所找最大值得下标。
*/
#include<stdio.h> 
#define N 9 
void fun(int a[ ], int n) {
	int i, j, max, min, px, pn, t;
	for (i = 0; i < n - 1; i += 2) {
		max = min = a[i];
		px = pn = i;
		// 确定最大值和最小值
		for (j = i + 1; j < n; j++) { 
			if (max < a[j]) {
				max = a[j];
				px = j;
			}
			if (min > a[j]) {
				min = a[j];
				pn = j;
			}
		}
		// 最小值不在第i位置 则将最小值赋给第i个位置, 交换
		if (pn != i) {
			t = a[i];
			a[i] = min;
			a[pn] = t;
			// 如果原始的值为最大值, 也就是最大值是在第i个位置, 则将下标变为交换之后的位置
			if (px == i) 
				px = pn;
		}
		// 最小值在第i个位置, 如果最大值不在第i+1个位置, 则将最大值放在放第i+1个位置,交换
		if (px != i + 1) {
			t = a[i + 1];
			a[i + 1] = max;
			a[px] = t;
		}
	}
}
#include <stdlib.h>
int main() {
	int b[N] = {9, 1, 4, 2, 3, 6, 5, 8, 7};
	printf("\nThe original data:\n");
	for (int i = 0; i < N; i++)
		printf("% 4d", b[i]);
	printf("\n");
	fun(b, N);
	printf("\nThe data after mocinng \n");
	for (int i = 0; i < N; i++)
		printf("% 4d", b[i]);
	printf("\n");

	system("pause");
	return 0;
}
