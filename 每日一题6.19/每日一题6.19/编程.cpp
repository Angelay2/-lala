/*
1. 【iNOC产品部-杨辉三角的变形】 
				1 
			1	1	 1 
		1	 2	 3	2	 1
	1	 3	 6	 7	 6	 3	 1
1	 4	 10	 16	 19	 16	 10	 4	 1 
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。 求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。 输入n(n <= 1000000000)
输入描述： 输入一个int整数
输出描述： 输出返回的int值

【解题思路】：
按照题目意思，可以发现第n行有2n - 1个元素，第i,j元素等于上一行第j - 2,j - 1,j三列元素之和，
每一行的第一列和最后一列都为1，如果是第二列，则只是两个元素之和。
*/
#include<iostream> 
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, m;
	while (cin >> n) {
		m = 2 * n - 1;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++) {
			//第一列和最后一列都为1
			dp[i][0] = dp[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; ++j) {
				if (j == 1) 
					//如果是第二列，则只是两个元素之和 
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
				else 
					//第i,j元素等于上一行第j - 2,j - 1,j三列元素之和 
					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
		int k;
		for (k = 0; k < m; k++) {
			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0) {
				cout << k + 1 << endl; 
				break;
			}
		}
		if (k == m)
			cout << -1 << endl;
	}
	return 0;
}

/*
2.【超长正整数相加】 请设计一个算法完成两个超长正整数的加法。 
接口说明 
/*请设计一个算法完成两个超长正整数的加法。 
输入参数： 
String addend：加数 
String augend：被加数 
返回值：加法结果 
public String AddLongInteger(String addend, String augend) { 
	/*在这里实现功能
	return null; 
}
输入描述： 输入两个字符串数字
输出描述： 输出相加后的结果，string型

【题目解析】：
本题是模拟加法运算。
【解题思路】：
加法运算，每一位的值等于当前对应位的两数之和+进位。由于是加法，所以当前位的和最多是
19（9 + 9 + 进位1)，所以产生的进位最多为1。故
第一步：计算对应位的和，对应位相加 + 上一位的进位
第二步：更新当前位的值， 和 % 10 ，把值转成字符（和 - '0'）存入字符结果中
第三步：更新进位， 和 / 10， 然后计算下一位的值
最后一步：如果计算完之后，进位为1，说明最高位产生了进位，所以需要再加一位，才是最后的
结果。结果产生之后，需要逆置，得到最终结果
*/
#include <string> 
#include <iostream> 
#include <algorithm> 
using namespace std; 
string addStrings(string num1, string num2) { 
	//由低位向高位相加 
	int i = num1.size() - 1; 
	int j = num2.size() - 1;
	string result = ""; 
	//当前位的相加结果
	int carry = 0;
	while (i >= 0 || j >= 0) {
		if (i >= 0) {
			carry += num1[i] - '0';
		}
		if (j >= 0) {
			carry += num2[j] - '0';
		}
		//当前为的最大值不大于10
		result += (char)(carry % 10 + '0');
		//如果大于10,向上进一位
		carry /= 10;
		i--;
		j--;
	}
	//相加完之后，如果还有进位，则再加1
	if (carry == 1) {
		result += '1';
	}
	//整体逆置
	reverse(result.begin(), result.end()); return result;
}
int main() {
	string s1, s2;
	while(cin>>s1>>s2) {
		cout<<addStrings(s1, s2)<<endl;
	}
	return 0;
}