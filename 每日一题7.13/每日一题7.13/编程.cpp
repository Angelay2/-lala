/*
1. 【数据库连接池】Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。 现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。

输入描述: 输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000），表示请求的数量。 
	     紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。
输出描述: 对应每一组数据，输出连接池最多需要创建多少个连接。

[题目解析] 
1. 服务器后台访问数据库时，需要先连上数据库，而为了连上数据库，需要连接方和数据库服务上各自都要维护链接，而链接本身的创建维护是有成本的
2. 要减少开销，这里的解决方案就是将以前的mysql链接复用起来，从而节省了创建和销毁的时间成本，
该题目就是根据算法，结合日志，计算当前的业务需要预先创建多少链接，来满足正常使用.
[解题思路]
使用一个set来做，如果某个记录是connect，就加到set中去，如果是disconnect，就把set中对应的值删除
掉。在加进去的过程中，不断判断set元素的最大个数，最终返回这个最大个数即可。
*/
#include <iostream>
#include <fstream> 
#include <algorithm> 
#include <string> 
#include <set> 
using namespace std; 
int main() { 
	int n; 
	while (cin >> n) { 
		set<string> pool; 
		string id, con; 
		int maxSize = 0; 
		for (int i = 0; i < n; ++i) {
			cin >> id >> con;
			if (con == "connect")
				pool.insert(id); 
			else if (con == "disconnect") 
				pool.erase(id); 
			int size = pool.size(); 
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0; 
}

/*
2. 【mkdir】 工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，就需要此次创建“/usr”、“/usr/local”以 及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。 现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。
输入描述： 输入包含多组数据。 每组数据第一行为一个正整数n(1≤n≤1024)。 紧接着n行，每行包含一个待创建的目录名，目录名仅由数字和字母组成，长度不超过200个字符。 
输出描述： 对应每一组数据，输出相应的、按照字典顺序排序的“mkdir -p”命令。 每组数据之后输出一个空行作为分隔。

[题目解析] 
1. 该题目需要我们了解 mkdir -p 命令，改命令可以递归创建目录
2. 但是该题目其实想让我们解决的问题是，给你一组数据（详情见题目），怎么用最少的 mkdir -p 创建
出我们想要的多个目录
[解题思路]
只要按照题面，将前缀字符串路径和相同路径剔除，只mkdir －p最长或者唯一路径就可以解决这个问题
*/
#include <iostream> 
#include <fstream> 
#include <algorithm>
#include <string> 
#include <vector> 
using namespace std;
int main() { 
	int n; 
	while (cin >> n) {
		vector<string> list(n);
		vector<bool> flag(n, true); 
		for (int i = 0; i < n; ++i) 
			cin >> list[i]; 
		sort(list.begin(), list.end()); //将类似字符串经过排序，放在一起 
		for (int i = 0; i < list.size() - 1; ++i) { 
			// 1、两串相同 
			// 2、前串是后串的子串，而且后串后一位是 '/' 
			if (list[i] == list[i + 1]) 
				flag[i] = false; 
			else if (list[i].size() < list[i + 1].size() && list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1] [list[i].size()] == '/') 
				flag[i] = false;
		}
		for (int i = 0; i < list.size();++i) 
		if (flag[i]) 
			cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}