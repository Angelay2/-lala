#include <iostream> 
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std; 

/*
1. ��Fibonacci���С�Fibonacci��������������ģ� F[0] = 0 F[1] = 1 for each i �� 2: F[i] = F[i-1] + F[i-2] ��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci���� 
���������� ����Ϊһ��������N(1 �� N �� 1,000,000) 
��������� ���һ����С�Ĳ�����ΪFibonacci��"

����Ŀ��������
�����Ƕ���Fibonacci���е�һ�����죬Fibonacci���е������ǵ�һ��͵ڶ��Ϊ1����������γɵݹ飺
F(n) = F(n - 1) + F(n - 2)��
������˼·����
�������ͨ�����ҵ�����N���������Fibonacci�������������ֱ�ȡ�Ծ���N����������һ����L���ұ�һ
����R��Ȼ��ͨ��min(N - L, R - N)�ҵ���С������
*/
int main(){ 
	int N, f, l = 0,r = 0,f0 = 0,f1 = 1; 
	cin >> N; 
	while(1){ 
		f = f0 + f1; 
		f0 = f1; 
		f1 = f; 
		// �ҵ���NС�Ҿ���N���������������� 
		if(f < N) 
			l = N-f; 
		else if(f > N) { 
			// �ҵ���N���Ҿ���N���������������� 
			// ����쳲�������ʱ���� 0
			r = f - N; 
		} 
		else{
			cout << "��������쳲�������" << endl;
			break;
		}
	} 
	// ��ȡ��С���� 
	cout <<"������С����Ϊ"<< min(l,r) << endl;  

	system("pause");
	return 0; 
}
/*
2.���Ϸ����������жϡ� ����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ��� ����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ��� һ���Ϸ������Ŵ�����Ϊ��1.ֻ���������ַ���2.�����ź�������һһ��Ӧ
���������� "(()())",6    ---->   ���أ�true
���������� "()a()()",7      ---->   ���أ�false 
���������� "()(()()",7      ---->   ���أ�false

������˼·����
��ջ�ṹʵ�֣�ջ�д�������ţ�������������֮�󣬼��ջ���Ƿ��������ţ���������ջ�����û�У�
��˵����ƥ�䡣
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
