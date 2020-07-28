/*
1.【求正数数组的最小不可组成和】
给定一个全是正数的数组arr，定义一下arr的最小不可组成和的概念： 
1，arr的所有非空子集中，把每个子集内的所有元素加起来会出现很多的值，其中最小的记为min，最大的记为max； 
2，在区间[min,max]上，如果有一些正数不可以被arr某一个子集相加得到，那么这些正数中最小的那个， 就是arr的最小不可组成和； 
3，在区间[min,max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和； 
举例： 
arr = {3,2,5} arr的min为2，max为10，在区间[2,10]上，4是不能被任何一个子集相加得到的值中最小的，所以4是arr的最小不可组成和； 
arr = {3,2,4} arr的min为2，max为9，在区间[2,9]上，8是不能被任何一个子集相加得到的值中最小的，所以8是arr的最小不可组成和； 
arr = {3,1,2} arr的min为1，max为6，在区间[2,6]上，任何数都可以被某一个子集相加得到，所以7是arr的最小不可组成和； 
请写函数返回arr的最小不可组成和

【解题思路】：
这是一个动态规划的01背包问题；
根据承重和已有的重量种类阶段性计算当前承重时能够放入的重量
当数组中只有2重量的时候，背包承重从2~10都可以放入2的数值 
当数组中放入2和3重量的时候，背包承重从5~10可以放入5，3~4放入3，2只能放入2 
当数组中放入2，3，5重量时，背包承重10放入10，8~9放入8，7放入7，5~6放入5...

假设有一个能装入容量为C(C在[min,sum]间取值)的背包和n件重量分别为w1,w2,…,wn的物品，能否从n件物品中挑选若干件恰好装满背包，要求输出不满足条件的最小容量。
重量: 2 3 4 5 6 7 8 9 10
数组中只有2重量: 2 2 2 2 2 2 2 2 2 2
数组中放入2和3重量时: 3 2 3 3 5 5 5 5 5 5
数组中放入2，3，5重量时: 5 2 3 3 5 5 7 8 8 10
最终当每个承重与放入的重量不同时，这个承重就是最小不可求和---4
*/
#include <iostream>
#include <vector> 
using namespace std;

class Solution { 
public: 
	int getFirstUnFormedNum(vector<int>& arr, int length) { 
		int sum = 0, min = arr[0];
		int i, j;
		for(int i = 0; i < length; i++) {
			sum += arr[i]; // 求出最大值
			min = arr[i] <  min ? arr[i] : min; // 找出最小值min
		}

		vector<int> dp(sum + 1, 0);
		for(i = 0; i < length; i++){
			//有length个数据--有length个阶段 
			//{2， 3， 5} 
			//i=0-->  背包中只能放入2时      --> d[10]=2  d[9]=2 d[8]=2 d[7]=2...d[2]=2 
			//i=1-->  背包只能放入2和3时     --> d[10]=5  d[9]=5...d[5]=5 d[4]=3 d[3]=3 
			//i=2-->  背包中可以放入2,3,5时  --> d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5 
			for(j = sum; j >= arr[i]; j--){ 
				//逆序判断背包承重中能够放入的数据
				//当数组中只有2的时候，背包承重从2-10都可以放入2的数值
				//当数组中放入2和3的时候，背包承重从5-10可以放入5，3-4放入3，2只能放入2
				//当数组中放入2，3，5时，背包承重10放入10，8-9放入8，7放入7，5-6放入5... 
				//dp[j-arr[i]]意思是背包承重为j时，如果已经放置了arr[i]的重量后还能放置的最大重量 
				if (dp[j] < dp[j - arr[i]] + arr[i])//对每个承重计算当前最大能放置重量 
					dp[j] = dp[j - arr[i]]+ arr[i];//更新背包中能够放入的最大值 
				else
					dp [j] = dp[j];
			}
		}
		//最后当承重为n时，放入的重量不为n则认为是最大不可求和 
		for (i = min; i <= sum; i++) { 
			if (i != dp[i]) 
				return i;
		}
		return sum + 1; 
	}
};

/*
2. 【有假币】居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。 
输入描述： 1≤n≤2^30,输入0结束程序。 
输出描述： 最多要称几次一定能把那个假币找出来？

【题目解析】：通过对一堆硬币进行均分称重，判断哪一堆中包含假币（因为假币轻）
【解题思路】：
平均分三份是最快的方法，两份进行称重（对比出三个的重量 ），后对最重的那份再次进行称重，直到称重的个数不足2个时则结束，获得假币 如果无法平均分3份则余数要么是1要么是2，因为是要最多称几次，n=n/3+1满足每次取最大 分3份，取两份一样多的过秤，然后把三份中最多的那份继续分，直到硬币剩余0或1时截至
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
int main(){ 
	long long n;
	int cnt = 0;
	while ((scanf("%lld", &n)) != EOF) {
		if (n == 0) 
			break; 
		while (n >= 2) {// 金币的个数若只有两个, 也需要称
			if (n % 3) {// 分三份称
				//不可以整除则取最差情况：最重的一份是 n/3 + 1个金币 
				n = n / 3 + 1; 
			}
			else {
				//可以整除则直接整除，能够获取到最重的一份
				n /= 3;
			}
			cnt++; 
		}
		printf("%d\n",cnt); 
	}
	return 0;
}