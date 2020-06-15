#include <iostream> 
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std; 

/*
1. 【Fibonacci数列】Fibonacci数列是这样定义的： F[0] = 0 F[1] = 1 for each i ≥ 2: F[i] = F[i-1] + F[i-2] 因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。 
输入描述： 输入为一个正整数N(1 ≤ N ≤ 1,000,000) 
输出描述： 输出一个最小的步数变为Fibonacci数"

【题目解析】：
本题是对于Fibonacci数列的一个考察，Fibonacci数列的性质是第一项和第二项都为1，后面的项形成递归：
F(n) = F(n - 1) + F(n - 2)。
【解题思路】：
本题可以通过先找到距离N最近的两个Fibonacci数，这两个数分别取自距离N的最近的左边一个数L和右边一
个数R，然后通过min(N - L, R - N)找到最小步数。
*/
int main(){ 
	int N, f, l = 0,r = 0,f0 = 0,f1 = 1; 
	cin >> N; 
	while(1){ 
		f = f0 + f1; 
		f0 = f1; 
		f1 = f; 
		// 找到比N小且距离N最近的数，求出距离 
		if(f < N) 
			l = N-f; 
		else if(f > N) { 
			// 找到比N大且距离N最近的数，求出距离 
			// 就是斐波那契数时返回 0
			r = f - N; 
		} 
		else{
			cout << "该数就是斐波那契数" << endl;
			break;
		}
	} 
	// 获取最小距离 
	cout <<"所需最小距离为"<< min(l,r) << endl;  

	system("pause");
	return 0; 
}
/*
2.【合法括号序列判断】 对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。 给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。 一个合法的括号串定义为：1.只包括括号字符；2.左括号和右括号一一对应
测试样例： "(()())",6    ---->   返回：true
测试样例： "()a()()",7      ---->   返回：false 
测试样例： "()(()()",7      ---->   返回：false

【解题思路】：
用栈结构实现，栈中存放左括号，当遇到右括号之后，检查栈中是否有左括号，如果有则出栈，如果没有，
则说明不匹配。
*/
class Parenthesis{
public: 
	bool chkParenthesis(string A, int n){
		stack<char> sc; 
		for (auto ele : A){ 
			switch (ele){ 
			case '(': sc.push(ele); 
				break; 
			case ')':{ 
						 if (sc.empty() || sc.top() != '(') 
							 return false; 
						 else
							 sc.pop(); 
			}
				break; 
			default: 
				return false; 
			} 
		}
		return true; 
	} 
};
