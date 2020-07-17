/*
1. 小易的升级之路 
小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 
如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并且使得自己的能力值增加bi;如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi与c的最大公约数.
那么问题来了,在一系列的锻炼后,小易的最终能力值为多少? 
输入描述： 对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值. 第二行n个整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力 
输出描述： 对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值

【解题思路】：
本题的能力值的累加分两种情况，一种是直接相加bi,一种是累加当前能力值于bi的最大公约数。最大公约数
可以通过碾转相除法求得：a与b的最大公约数相当于b与a,b余数的最大公约数。如果求余结果为0， 则b为所
求结果
*/
#include<vector> 
#include<iostream>
using namespace std;
int GCD(int a, int b) {
	int c;
	while (c = a % b) {
		a = b; 
		b = c;
	}
	return b; 
}
int main() {
	int n, power;
	vector<int> num;
	while (cin >> n >> power) {
		num.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		for (int k = 0; k < n; k++) {
			if (num[k] < power) {
				power += num[k];
			}
			else { 
				power += GCD(power, num[k]);
			}
		}
		cout << power << endl;
	}
	return 0;
}

#include <cstdio> 
#include <cstring> 
#include <cstdlib>
#include <algorithm>
using namespace std;
int gcd(int a,int b){ 
	int tmp;
	while(b){ 
		tmp = b;
		b = a % b ;
		a = tmp;
	}
	return a;
}
int main(){ 
	int n,a;
	while(scanf("%d%d",&n,&a) != EOF){
		for(int i = 0,x;i < n;++ i){ 
			scanf("%d",&x);
			if(x <= a) 
				a += x; 
			else 
				a += gcd(x,a);
		}
		printf("%d\n",a);
	}
	return 0;
}

/*
2.  标题：找出字符串中第一个只出现一次的字符
找出字符串中第一个只出现一次的字符 
输入描述： 输入一个非空字符串 
输出描述： 输出第一个只出现一次的字符，如果不存在输出-1

【解题思路】：
用一个数组的每一个位置表示对应的位置。对应的字符位置存放字符出现的次数。统计完之后，遍历输入字符，遇到第一个只出现一次的字符就停止
*/

#include <string>
#include <iostream>
using namespace std;
int main() { 
	string s;
	while(cin>>s) {
		int hashtable[256] = {0};
		for(auto& e : s) {
			hashtable[e]++;
		}
		int i;
		for(i = 0;i < s.size();i++) {
			if(hashtable[s[i]] == 1) {
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size())
			cout << -1 << endl;
	}
	return 0; 
}