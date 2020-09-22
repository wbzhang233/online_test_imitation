// 美团2020春招，最优前缀树
// Created by wbzhang on 2020/9/20.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	int cnt;
	Node* next[26];  //26个小写的字母 a-z

	Node():cnt(1) // 对于最优前缀树的每个节点都要将指 指针数组初始化为nullptr, 每一个cnt都要初始化为1
	{
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}

	}
};

int main()
{
	Node*root = new Node();
	int n = 0;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp; //对于每一个输入的字符串，就构造前缀树，加入七十中
		strs[i] = tmp;
		Node* p = root;
		for (int j = 0; j < tmp.size(); j++)
		{
			if (p->next[tmp[j] - 'a'] != nullptr) // 节点的下一个 next[tmp[j] - 'a']不为空
			{
				p->next[tmp[j] - 'a']->cnt++; // 对这个节点的标记值 cnt++
			}
			else
			{
				p->next[tmp[j] - 'a'] = new Node();  //创建新的节点
			}
			p = p->next[tmp[j] - 'a']; // 将指针指向 下一个节点
		}
	}
	// 在最优前缀树中寻找结果
	for (int i = 0; i < n; i++)
	{
		Node* p = root;
		int j = 0;
		for (; j < strs[i].size(); j++)
		{
			if (p->next[strs[i][j] - 'a']->cnt == 1)
			{
				cout << strs[i].substr(0, j + 1) << endl;  // 输处从头结点到 cnt=1位置的整个字符
				break;
			}
			p = p->next[strs[i][j] - 'a'];
		}
		if (j == strs[i].size())  // 代表整个字符串才是唯一可区分的
		{
			cout << strs[i] << endl;
		}
	}
	system("pause");
}
