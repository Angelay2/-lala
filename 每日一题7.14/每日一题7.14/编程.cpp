/*
1. 红与黑
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。 

输入描述： 输入包含多组数据。 每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下： 
	1. “.”：黑色的瓷砖；	
	2. “#”：白色的瓷砖； 
	3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。 
输出描述： 对应每组数据，输出总共能够到达多少块黑色的瓷砖。

[题目解析] 
1. 输入的m和n就是代表输入后续会输入几行几列字符
2. 第二行开始，输入的字符就是我们的“行走矩阵”，其中“.”->黑色的瓷砖, “#”->白色的瓷砖, “@”->黑色的瓷
砖，并且你站在这块瓷砖上
3. 这道题的核心问题是，从你站的位置开始，向周边任意位置走，你能直接走过的黑色瓷砖的总数是多少
[解题思路]
该问题可以采用深度优先遍历的方式，统计所有的可能性，

*/

// DFS问题 
#include <iostream>
#include <fstream> 
#include <vector> 
#include <queue> 
using namespace std; 
struct pos { 
	int x, y; 
}; 
int bfs(vector<vector<char>> & map, vector<vector<bool>> & visit, pos & start) { 
	const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; 
	queue<pos> que; 
	int count = 0;
	int m = map.size(), n = map[0].size(); 
	que.push(start); 
	visit[start.x][start.y] = true;
	++count; 
	while (!que.empty()) {
		pos cur = que.front(), next; 
		que.pop(); 
		for (int i = 0; i < 4; ++i) { 
			next.x = cur.x + dir[i][0]; next.y = cur.y + dir[i][1]; 
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && !visit[next.x][next.y] && map[next.x][next.y] == '.') {
				que.push(next); 
				visit[next.x][next.y] = true;
				++count; 
			}
		} 
	}
	return count;
}
int main() {
	int m, n; 
	while (cin >> m >> n && (m*n)) { 
		pos start; 
		vector<vector<char>> map(m, vector<char>(n)); 
		vector<vector<bool>> visit(m, vector<bool>(n)); 
		for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) { 
			visit[i][j] = false; 
			cin >> map[i][j]; 
			if (map[i][j] == '@') 
				start.x = i, start.y = j; 
		}
		cout << bfs(map, visit, start) << endl;
	}
	return 0;
}
	 
/*
2. 题目ID：25951 蘑菇阵
[题目解析]
	该题类似于走迷宫，蘑菇代表不能走通，但不同的是，迷宫可以向前后左右四个方向移动，但该题走的方式
	只能向右或者向下两个方向移动，注意：右边界处只能向一个方向移动，因此走不通路径的概率是不相等的。比如：M = 2 N = 3
		1 2 3
		4 5 6 
	在1时：既可向右走到2，也可向下走到4，因此从1-->2 和从1-->4的概率均为0.5
	在2时：即可向右走到3，也可向下走到5，因此从2-->3和从2-->5的概率均为0.5
	在3时：只能走到6，因此从3-->6概率为1 
	在4、5、6时，只能向右走，因此4-->5和5-->6的概率均为1。

	通过以上分析，可以得到：
	假设P(i, j)表示从起点到(i, j)不踩到蘑菇的概率，那么该位置一定是从(i-1, j)或者(i, j-1)出走过来的。
	而从(i-1, j)或者(i, j-1)到达(i, j)的概率是不等的，比如：如果i或者j在边界，只能向一个方向移动，此时走到(i, j)位置的概率为1，当i或者j不在边界时，走到(i,j)的概率分别为0.5，因此可得出：
				P(i,j) = P(i-1, j) * (i==M? 1 : 0.5)+ P(i, j-1) * (j==N? 1 : 0.5);
	如果(i, j)为蘑菇时，表示不能走到该位置

[解题思路] 
	1. 循环接受输入(注意：一般IO类型算法即需要写main的算法，背后可能有多个测试用例，每个用例必须测试到，因此需要循环输入) 
	2. 按照输入构造蘑菇地图(二维矩阵)，1代表蘑菇，0代表通路，因起点是从(1,1)开始，矩阵多给一个行和列
	3. 构造用来保存走到(i,j)位置不遇到蘑菇的概率容器
	4. 按照上述分析结论：遍历蘑菇地图，当遇到蘑菇时，将概率置为0，即不可能到达该位置
	5. 按照要求输出：注意保留两位精度。 
	
*/

//要使用动态规划 
#include <iostream> 
#include <iomanip> 
#include <algorithm> 
#include <vector> 
using namespace std; 
int main() { 
	int n, m, k; 
	while(cin >> n >> m >> k){ 
		// 用来保存蘑菇地图 
		vector<vector<int>> table((n+1), vector<int>(m+1)); // 构造蘑菇地图 
		int x, y; 
		for(int i = 0; i < k; i++){ 
			cin >> x >> y; 
			table[x][y] = 1;
		}
		//P[i][j]表示不碰到蘑菇走到i，j的概率 
		vector<vector<double> > P((n+1), vector<double>(m+1));
		P[1][1] = 1.0; //起点概率为1 
		for(int i = 1; i <= n; i++){ 
			for(int j = 1; j <= m; j++) { 
				if(!(i == 1 && j ==1)){ 
					//跳过起点 
					P[i][j] = P[i-1][j]*(j == m? 1 : 0.5) + P[i][j-1]*(i == n?1:0.5); // 边界的时候，概率为1
		 if (table[i][j] == 1) 
			 P[i][j] = 0; //如果该点有蘑菇，概率置为0 
				}
			}
		}
		cout << fixed << setprecision(2) << P[n][m] << endl;
	} 
}
*/