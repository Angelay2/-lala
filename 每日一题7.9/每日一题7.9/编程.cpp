/*
1. . 标题：收件人列表 
NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间 会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。 现在给你一组收件人姓名，请你帮他生成相应的收件人列表。 

输入描述： 输入包含多组数据。 每组数据的第一行是一个整数n (1≤n≤128)，表示后面有n个姓名。 紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
输出描述： 对应每一组输入，输出一行收件人列表。

【题目解析】：
基础的字符串处理问题
【解题思路】：
先接收到一个数字，代表接下来是多少组数据，一个一个接，接到一个就拼一个，后面跟上一个逗号和一个空格，
全部接完就给个回车。如果输入的字符串里有逗号或者空格，就要加双引号。可以选择拼接好了输出，也可以选择
一段段直接输出。下面的代码是直接一段段输出的结果。
*/
#include <iostream>
#include <string> 
#include <cstdio> 
int main() { 
	int n; 
	while(std::cin >> n){  //接收数字 
		std::cin.get(); //处理回车 
		std::string name; 
		for(int i=0; i < n; i++){ //名字分别处理 
			bool quote = false; 
			std::getline(std::cin, name); 
			if (name.find(',') != std::string::npos || name.find(' ') != std::string::npos){ //找到逗号或者空格，就要加双引号 
				quote = true;
			}
			if (quote) {
				putchar('\"'); //putchar效率更高 
			}
			std::cout << name;
			if (quote) {
				putchar('\"');
			}
			if (i == n - 1){ //如果已经是最后一个字符串，那就补回车，否则加逗号和空格 
				putchar('\n');
		}
			else {
				putchar(',');
				putchar(' ');
			}
		}
	}
	return 0; 
}

/*
2. 标题：养兔子 
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以 后，他将会得到多少只兔子。

输入描述： 测试数据包括多组，每组一行，为整数n(1≤n≤90)。 
输出描述： 对应输出第n天有几只兔子(假设没有兔子死亡现象)。

【题目解析】：
兔子问题的简化描述版。斐波那契数列的原型。
【解题思路】：
本题的兔子第二天就开始下小兔了，所以这个是从第二项开始的斐波那契数列。前90组的数据恰好还在long long
的范围内，所以不需要高精度，直接long long求解。
*/
#include <iostream>
#include <cstdio> 
int main() { 
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++) {
		n[i] = n[i - 1] + n[i - 2];
	}
	int d;
	while(std::cin >> d) {
		printf("%lld\n", n[d - 1]); 
	}
}