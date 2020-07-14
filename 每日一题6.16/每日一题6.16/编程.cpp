/*
1. 【计算日期到天数转换】 根据输入的日期，计算是这一年的第几天。。 详细描述： 输入某年某月某日，判断这一天是这一年的第几天？ 
接口设计及说明： /***************************************************************************** 
Description : 数据转换 
Input Param : year 输入年份 
			Month 输入月份 
			Day 输入天 
Output Param : 
Return Value : 成功返回0，失败返回-1（如：数据错误） *****************************************************************************/ 
/*public static int iConverDateToDay(int year, int month, int day) { 
	/* 在这里实现功能，将结果填入输入数组中*/ 
/*	return 0; 
}
/***************************************************************************** 
Description : 
Input Param : 
Output Param : 
Return Value : 成功:返回outDay输出计算后的第几天; 失败:返回-1 *****************************************************************************/ 
/*public static int getOutDay() { 
	return 0; 
}
输入描述： 输入三行，分别是年，月，日
输出描述： 返回outDay输出计算后的第几天; 失败:返回 - 1
【题目解析】：
本题考察日期类，我们课堂已经深入讲解过日期类。
【解题思路】：
用一个数组存放每月的累积天数
输入的日期天数 = 当月的天数 + 当月之前的累积天数
如果包含二月，再去判断是否为闰年，如果是闰年，再加1天即可
*/
//#include <iostream> 
//#include <stdlib.h>
//using namespace std; 
//int main() {
//	int array[12] = {31,59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}; 
//	int year; 
//	int month; 
//	int day; 
//	int sum = 0; 
//	while(cin >> year >> month >> day) {
//		sum = 0; 
//		sum += array[month - 2];
//		sum += day; 
//		if(month > 2) {
//			if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { 
//				sum += 1; 
//			}
//		}
//		cout << sum <<endl;
//	}
//
//	system("pause");
//	return 0;
//}
//int main8(){ 
//	int y,m,d; 
//	while(cin >> y >> m >> d){ 
//		int monthDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}; 
//		int nday = monthDays[m - 1] + d; 
//		if(m > 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))){ 
//			nday++; 
//		}
//		cout<<nday<<endl; 
//	}
//
//	system("pause");
//	return 0; 
//}

/*
【幸运的袋子】一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的,当且仅当所有球的号码的和 大于 所有球的号码的积。 例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3 你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。 
输入描述： 空第一行输入一个正整数n(n ≤ 1000) 第二行为n个数正整数xi(xi ≤ 1000)
输出描述： 输出可以产生的幸运的袋子数

【题目解析】：
本题的本质是求符合条件的子集个数。
【解题思路】：
每次从全集中选择若干元素（小球）组成子集（袋子）。对于任意两个正整数a,b如果满足a+b>ab，则必有一个数为1.可用数论证明：
设a=1+x,b=1+y，则1+x+1+y>(1+x)(1+y)，---> 1>xy，则x，y必有一个为0，即a,b有一个为1.推广到任意k个正整数，假设a1,a2,...ak，如果不满足给定条件，即和sum小于等于积pi。如果此时再选择一个数b,能使其满足sum+b > pi*b，则b必然为1，且为必要非充分条件。反之，如果选择的b>1，则sum+b <= pi*b，即a1,a2,...,ak,b不满足给定条件。
因此，将球按标号升序排序。每次从小到大选择，当选择到a1,a2,...,ak-1时满足给定条件，而再加选择ak时不满足条件（ak必然大于等于max(a1,a2,...,ak-1)），继续向后选择更大的数，必然无法满足！此时不必再继续向后搜索。如果有多个1，即当k=1时，sum(1)>pi(1)不满足，但下一个元素仍为1，则可以满足1+1>1*1，
所以要判断当前ak是否等于1，如果等于1，虽然不能满足，组合的个数不能增加，但是继续向后搜索，仍然有满足条件的可能.对于重复数字，组合只能算一个，要去重。
*/
#include <iostream> 
#include <algorithm> 
using namespace std; 

/* 
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束 
x[]: 袋子中的所有球 
n: 球的总数 
pos: 当前搜索的位置 
sum: 到目前位置的累加和 
multi: 到目前位置的累积值 
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi) { 
	int count = 0;  
	//循环，搜索以位置i开始所有可能的组合 
	for (int i = pos; i<n; i++) {
		sum += x[i]; 
		multi *= x[i]; 
		if (sum > multi) { 
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合 
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1) {
			//如何不符合要求，且当前元素值为1，则继续向后搜索 
			count += getLuckyPacket(x, n, i + 1, sum, multi); 
		}
		else { 
			//如何sum大于multi,则后面就没有符合要求的组合了 
			break;
		}
		//要搜索下一个位置之前，首先恢复sum和multi 
		sum -= x[i]; 
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过 
		while (i < n - 1 && x[i] == x[i + 1]) { 
			i++;
		}
	}
	return count;
}
int main() { 
	int n = 0,x[1000]; 
	// 输入n个数
	while (cin >> n) {
		//int* x = new int[n];
		for (int i = 0; i < n; i++) { 
			cin >> x[i];
		}
		sort(x, x + n); 
		//从第一个位置开始搜索 
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}