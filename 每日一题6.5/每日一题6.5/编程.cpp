#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector> 
#pragma warning(disable:4996)
using namespace std;

/*
1. ��ͳ�ƻ��ġ������Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
���������� ÿ���������ݹ����С� ��һ��Ϊ�ַ���A �ڶ���Ϊ�ַ���B �ַ������Ⱦ�С��100��ֻ����Сд��ĸ
������������һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ����� 

����Ŀ��������
���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����. ʲô�ǻ����ַ���������һ�������ͷ�����һ�����ַ��� �����Ĵ�Ҳ����ǰ��ԳƵ��ַ������������ж��Ƿ��ǻ��Ĵ��ı����⡣�ַ�������һ���ǻ��ģ��ѵڶ����ַ��������ȥ���Ƿ��ǻ��ġ�
������˼·����
����ʹ�ñ�����ⷽʽ���㼴�ɣ�����str1����str2 insert����str1��ÿ��λ�ã��ж��Ƿ��ǻ��ģ��Ǿ�
++count����Ҫע��������ﲻ�� str1.insert(i, str2)�������Ļ�str1�ı��ˣ��ж���һ��λ�þͲ����ˡ�����ÿ��ʹ��str1��������һ��str��Ȼ��str.insert(i, str2)�����ж�
*/
bool IsCircleText(const string& s){
	size_t begin = 0;
	size_t end = s.size() - 1;
	while(begin < end){
		if (s[begin] != s[end])
			return false;

		++begin;
		--end;
	}
	return true;
}
int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (size_t i = 0; i < str1.size(); ++i){
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			++count;
	}
	cout << count << endl;

	system("pause");
	return 0;

}

/*
2. ���������͡�һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3 
���������� ����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ���
��������� ���������������к�����ֵ��

������˼·����
����sum[i-1]���������е�nums[i-1]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
sum[i]���������е�nums[i]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
��ôsum[i] = max(sum[i-1], 0) + nums[i]�����������������������sum1��ʾsum[i-1]��sum2��ʾ
sum[i]�����������������������򱣴浽result�С����sum[i]����sum2��С��0�ˣ�����Ϊ0����Ϊ��
����������һ�������������������������͡�

*/
int main(){
	int size;
	// ��������Ԫ�ش�С
	cin >> size;
	vector<int> nums(size);
	// ����ÿ��Ԫ��
	for(size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	// ����0
	int sum1 = 0, sum2 = 0;

	// sum[2] = max(sum1, 0) + nums[2]       max(sum1, 0)���ж�sum1(������2����)�Ƿ�Ϊ���� ��0�Ƚ�ȡ���
	for (int i = 0; i < nums.size(); i++){
		// ���㵽num[i]�������������
		sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];
		if(sum2 > result) 
			result = sum2;
		if (sum2 < 0) 
			sum2 = 0; 
		sum1 = sum2; 
	}
	cout << result << endl; 

	system("pause");
	return 0; 
}