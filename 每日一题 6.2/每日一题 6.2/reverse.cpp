#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//void reverse(char* str, int num){
//	int* cur1 = str; 
//	int cur2 = str[num - 1];
//	int* begin = str;
//	int* end = str[num - 1];
//	if(*(begin++) == ' '){
//		if(*(end--) == ' '){
//			swap();
//		
//	}
//}
//int main(){
//	char* str[] = "I like Beijing.";
//	int num = sizeof(str) / sizeof(str[0]);
//	
//	reverse(str, num);
//	printf("%s", str);
//}
// ��ֻ�е��ʷ�ת�����������ĸ����ת��
void rotate_sentence(char* s, int bigen, int end)
{
	while (bigen < end)
	{
		char temp = s[bigen];
		s[bigen] = s[end];
		s[end] = temp;
		end--;
		bigen++;
	}
}
void test6()
{
	char s[] = "i am student.";
	char* temp = s;
	int i = 0;
	int j = i;
	for (i = 0; i <= strlen(s); i++)
	{
		if (s[i] == ' ' || s[i] == '\0')
		{
			rotate_sentence(s, j, i - 1);//�Ե������ʽ��з�ת
			j = i + 1;
		}
	}
	rotate_sentence(s, 0, strlen(s) - 1);//���������ӽ��з�ת
	cout << s;
}
int main(){
	test6();

	system("pause");
	return 0;
}











