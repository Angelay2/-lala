/*
1. 【年终奖】 小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。 
给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。
【解题思路】：
本题需要使用动态规划求解。
定义f(i,j)表示从左上角走到坐标(i，j)处能获得的最大奖励。搜索所有从左上角走到右下角的路径，找到最优路径。
f(i,j)分三种情况：
第一列：f(i, 0) = f(i-1, 0) + board(i, 0) --> 前一行的礼物价值
第一行：f(0, j) = f(0, j - 1) + board(0, j) --->前一列的礼物
其它位置：f(i, j) = max{f(i-1, j), f(i, j - 1)} + board(i, j)  ---> 正上和左边的礼物最大值
最后返回右下角的值。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Bonus {
public: 
	int getMost(vector<vector<int>> board) {
		int length = board.size();
		int wideth = board[0].size(); //第一行的长度
		vector<vector<int>> allPrice; 
		for (int i = 0; i < length; i++) { 
			vector<int> tmp(wideth, 0);
			allPrice.push_back(tmp);
		}
		allPrice[0][0] = board[0][0];
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < wideth; j++) {
				//如果是起点坐标，不做任何处理。
				if (i == 0 && j == 0) 
					continue;
				//如果走在行的临界边，也就是第一行，那么他只能向右走 
				//向右走的时候该点就要将后面的值加起来。
				else if (i == 0) {
					allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
				}
				//如果走在列的临界边，也就是第一列，那么他只能向下走 
				//向下走的时候该点就要将上面的值加起来。 
				else if (j == 0) {
					allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
				}
				else {
					//除去两个临界边，剩下的就是既能向右走，也能向下走， 
					//这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点 
					//各自路径的和是不是这些所有到达该点路径当中最大的了。
					allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i] [j];
				}
			}
		}
		// 返回最后一个坐标点的值，它就表示从左上角走到右下角的最大奖励 
		return allPrice[length - 1][wideth - 1];
	} 
};

/*
【迷宫问题】 定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示： 
int maze[5][5] = { 
0, 1, 0, 0, 0, 
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一 空格是可以走的路。
Input
一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
Output 
左上角到右下角的最短路径，格式如样例所示。 
Sample Input
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0 
Sample Output 
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2) 
(2, 3)
(2, 4) 
(3, 4)
(4, 4) 
输入描述： 输入两个整数，分别表示二位数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
输出描述： 左上角到右下角的最短路径，格式如样例所示。

【解题思路】：
本题可用回溯法求解 具体步骤为：
1. 首先将当前点加入路径，并设置为已走
2. 判断当前点是否为出口，是则输出路径，保存结果；跳转到4 3. 依次判断当前点的上、下、左、右四个点是否可走，如果可走则递归走该点
4. 当前点推出路径，设置为可走

*/
#include<iostream> 
#include<vector> 
using namespace std; 
int N, M;//分别代表行和列 
vector<vector<int>> maze;//迷宫矩阵 
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置 
vector<vector<int>> path_best;//存储最佳路径

void MazeTrack(int i, int j) {
	maze[i][j] = 1;//表示当前节点已走，不可再走 
	path_temp.push_back({ i, j });//将当前节点加入到路径中
	if (i == N - 1 && j == M - 1) //判断是否到达终点 
	if (path_best.empty() || path_temp.size() < path_best.size()) 
		path_best = path_temp; 
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行 
		MazeTrack(i - 1, j); 
	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行 
		MazeTrack(i + 1, j); 
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行 
		MazeTrack(i, j - 1); 
	if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行 
		MazeTrack(i, j + 1); 
	maze[i][j] = 0; //恢复现场，设为未走 
	path_temp.pop_back();
}
int main() { 
	while (cin >> N >> M) {
		maze = vector<vector<int>>(N,vector<int>(M, 0));
		path_temp.clear();
		path_best.clear(); 
		for (auto &i : maze) {
			for (auto &j : i) {
				cin >> j;
			}
		}
		MazeTrack(0, 0);//回溯寻找迷宫最短通路 	
		for (auto i : path_best) 
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路 
	}
	return 0;
}
