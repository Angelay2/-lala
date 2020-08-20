/*
1. �����ݿ����ӳء�Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á� �����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�

��������: ��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000������ʾ����������� 
	     ������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����
�������: ��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�

[��Ŀ����] 
1. ��������̨�������ݿ�ʱ����Ҫ���������ݿ⣬��Ϊ���������ݿ⣬��Ҫ���ӷ������ݿ�����ϸ��Զ�Ҫά�����ӣ������ӱ���Ĵ���ά�����гɱ���
2. Ҫ���ٿ���������Ľ���������ǽ���ǰ��mysql���Ӹ����������Ӷ���ʡ�˴��������ٵ�ʱ��ɱ���
����Ŀ���Ǹ����㷨�������־�����㵱ǰ��ҵ����ҪԤ�ȴ����������ӣ�����������ʹ��.
[����˼·]
ʹ��һ��set���������ĳ����¼��connect���ͼӵ�set��ȥ�������disconnect���Ͱ�set�ж�Ӧ��ֵɾ��
�����ڼӽ�ȥ�Ĺ����У������ж�setԪ�ص������������շ���������������ɡ�
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
2. ��mkdir�� �����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin��������Ҫ�˴δ�����/usr������/usr/local���� ����/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ�-p��ѡ�ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼�� ���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����
���������� ��������������ݡ� ÿ�����ݵ�һ��Ϊһ��������n(1��n��1024)�� ������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200���ַ��� 
��������� ��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������ġ�mkdir -p����� ÿ������֮�����һ��������Ϊ�ָ���

[��Ŀ����] 
1. ����Ŀ��Ҫ�����˽� mkdir -p �����������Եݹ鴴��Ŀ¼
2. ���Ǹ���Ŀ��ʵ�������ǽ���������ǣ�����һ�����ݣ��������Ŀ������ô�����ٵ� mkdir -p ����
��������Ҫ�Ķ��Ŀ¼
[����˼·]
ֻҪ�������棬��ǰ׺�ַ���·������ͬ·���޳���ֻmkdir ��p�����Ψһ·���Ϳ��Խ���������
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
		sort(list.begin(), list.end()); //�������ַ����������򣬷���һ�� 
		for (int i = 0; i < list.size() - 1; ++i) { 
			// 1��������ͬ 
			// 2��ǰ���Ǻ󴮵��Ӵ������Һ󴮺�һλ�� '/' 
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