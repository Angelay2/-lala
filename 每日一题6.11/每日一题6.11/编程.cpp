#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;
/*
1. 【井字棋】对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。

【题目解析】：
井字棋，是一种在3*3格子上进行的连珠游戏，三个相同就代表获胜。
【解题思路】：
井字棋有四种情况表示当前玩家获胜，1代表当前玩家棋子 1. 行全为1， 即行的和为3 2. 列全为1， 列的和为
3 3. 主对角全为1， 对角和为3 4. 副对角全为1， 对角和为3 5. 如果扩展为N*N的话，判断和是否等于N，下面代码适用任何情况
*/
class Board{
public: 
	bool checkWon(vector<vector<int>> board){
		int row = board.size(); 
		//检查每一行的和是是否等于row 
		int i,j,sum; 
		for(i=0;i<row;i++){ 
			sum = 0; 
			for(j=0;j<row;j++){ 
				sum += board[i][j]; 
			}
			if(sum==row) 
				return true; 
		}
		//检查每一列的和是是否等于row 
		for(i=0;i<row;i++){ 
			sum = 0; 
			for(j=0;j<row;j++){ 
				sum += board[j][i]; 
			}
			if(sum==row)
				return true; 
		}
		//检查主对角线的和是是否等于row 
		sum = 0;
		for (i = 0; i<row; i++){ 
			sum += board[i][i]; 
		}
		if (sum == row) 
			return true; 
		//检查副对角线的和是是否等于row 
		sum = 0; 
		for(i=0;i<row;i++){ 
			sum += board[i][row-i-1]; 
		}
		if(sum==row) 
			return true; 
		return false; 
	} 
};
/*
2. 【密码强度等级】
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
一、密码长度: 
5 分: 小于等于4 个字符 
10 分: 5 到7 字符 
25 分: 大于等于8 个字符 
二、字母: 
0 分: 没有字母 
10 分: 全都是小（大）写字母 
20 分: 大小写混合字母 
三、数字: 
0 分: 没有数字 
10 分: 1 个数字 
20 分: 大于1 个数字 
四、符号: 
0 分: 没有符号 
10 分: 1 个符号 
25 分: 大于1 个符号 
五、奖励: 
2 分: 字母和数字 
3 分: 字母、数字和符号 
5 分: 大小写字母、数字和符号 
最后的评分标准: 
>= 90: 非常安全 
>= 80: 安全（Secure） 
>= 70: 非常强 
>= 60: 强（Strong） 
>= 50: 一般（Average） 
>= 25: 弱（Weak） 
>= 0: 非常弱

对应输出为： 
VERY_WEAK, 
WEAK, 
AVERAGE, 
STRONG, 
VERY_STRONG, 
SECURE, 
VERY_SECURE 

请根据输入的密码字符串，进行安全评定。 
注：字母：a-z, A-Z 数字：-9 
符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看) 
!"#$%&'()*+,-./ (ASCII码：x21~0x2F) 
:;<=>?@ (ASCII<=><=><=><=><=>码：x3A~0x40) 
[\]^_` (ASCII码：x5B~0x60) 
{|}~ (ASCII码：x7B~0x7E) 
接口描述： 
Input Param 
	String pPasswordStr: 密码，以字符串方式存放。 
	Return Value 
		根据规则评定的安全等级。

输入描述： 输入一个string的密码 
输出描述： 输出密码等级

【题目解析】：
本题考查的是同学们对于字符的使用。
【解题思路】：
这里对于不同种类的字符得分不同，同学们可以现对每一个维度进行单独判断，即对于长度，字母，数字，
符号单独判断，最后把所有的单项值根据题目要求相加，输出对应的安全级别。
*/
int numChar(string str, int k){ 
	//根据ASCII码判断字母大小写 
	int small = 0; 
	int big = 0; 
	for(int i = 0; i < k; i++){ 
		if(str[i] >= 65 && str[i] <= 90) 
			big++; 
		else if(str[i] >= 97 && str[i] <= 122) 
			small++; 
	}
	if((small + big) == 0)
		return 0; 
	else if(small == k || big == k) 
		return 10; 
	else if(small > 0 && big > 0) 
		return 20; 
	return 0;
}
int numNumber(string str, int k){ 
	//根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字 
	int num = 0; 
	for(int i = 0; i < k; i++){ 
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) 
			num++; 
	}
	if(num == 0) 
		return 0; 
	else if(num == 1) 
		return 10; 
	else
		return 20; 
}
int numSymbal(string str, int k){ 
	int num = 0; 
	for (int i = 0; i < k; i++){ 
		//除去字母，数字，其它都为符号 
		if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] - '0' >= 0 && str[i] - '0' <= 9)) 
			num++; 
	}
	if(num == 0) 
		return 0; 
	else if(num == 1) 
		return 10; 
	else
		return 25; 
}
int main(){ 
	string str; 
	while (cin >> str){ 
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0; 
		int k = str.size(); 
		if (k <= 4) 
			sum1 = 5; 
		else if (k >= 8) 
			sum1 = 25; 
		else
			sum1 = 10; 
		sum2 = numChar(str, k); 
		sum3 = numNumber(str, k); 
		sum4 = numSymbal(str, k); 
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0)){ 
			if (sum2 == 10) 
				sum5 = 3; 
			else
				sum5 = 5; 
		}
			else if(sum2 > 0 && sum3 > 0 && sum4 == 0) 
				sum5 = 2; 
		if(sum1 + sum2 + sum3 + sum4 + sum5 >= 90) 
			cout << "VERY_SECURE" << endl;
		else if(sum1 + sum2 + sum3 + sum4 + sum5 >= 80) 
			cout << "SECURE" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70) 
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60) 
			cout << "STRONG" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50) 
			cout << "AVERAGE" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25) 
			cout << "WEAK" << endl; 
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}