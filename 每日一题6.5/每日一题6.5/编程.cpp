#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector> 
#pragma warning(disable:4996)
using namespace std;

/*
1. 【统计回文】“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
输入描述： 每组输入数据共两行。 第一行为字符串A 第二行为字符串B 字符串长度均小于100且只包含小写字母
输出描述：输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数 

【题目解析】：
输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数. 什么是回文字符串，就是一个正读和反读都一样的字符串 ，回文串也就是前后对称的字符串。本题是判断是否是回文串的变形题。字符串本身不一定是回文，把第二个字符串插入进去看是否是回文。
【解题思路】：
本题使用暴力求解方式计算即可，遍历str1，将str2 insert进入str1的每个位置，判断是否是回文，是就
++count；需要注意的是这里不能 str1.insert(i, str2)，这样的话str1改变了，判断下一个位置就不对了。所以每次使用str1拷贝构造一个str，然后str.insert(i, str2)，再判断
*/
bool IsCircleText(const string& s){
	size_t begin = 0;
	size_t end = s.size() - 1;
	while(begin < end){
		if (s[begin] != s[end])
			return false;

		++begin;
		--end;
	}
	return true;
}
int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (size_t i = 0; i < str1.size(); ++i){
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			++count;
	}
	cout << count << endl;

	system("pause");
	return 0;

}

/*
2. 【连续最大和】一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 
输入描述： 输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述： 所有连续子数组中和最大的值。

【解题思路】：
假设sum[i-1]是以数组中第nums[i-1]为最后一个元素的一段子数组最大和，
sum[i]是以数组中第nums[i]为最后一个元素的一段子数组最大和，
那么sum[i] = max(sum[i-1], 0) + nums[i]，理解了这个，下面代码中用sum1表示sum[i-1]，sum2表示
sum[i]，如果计算出更大的子数组和则保存到result中。如果sum[i]，及sum2都小于0了，则置为0，因为他
加上数组下一个数，不会计算出更大的子数组和。

*/
int main(){
	int size;
	// 输入数组元素大小
	cin >> size;
	vector<int> nums(size);
	// 输入每个元素
	for(size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	// 和置0
	int sum1 = 0, sum2 = 0;

	// sum[2] = max(sum1, 0) + nums[2]       max(sum1, 0)是判断sum1(倒数第2个和)是否为正数 和0比较取最大
	for (int i = 0; i < nums.size(); i++){
		// 计算到num[i]的子数组的最大和
		sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];
		if(sum2 > result) 
			result = sum2;
		if (sum2 < 0) 
			sum2 = 0; 
		sum1 = sum2; 
	}
	cout << result << endl; 

	system("pause");
	return 0; 
}