// 回文子串
// Created by wbzhang on 2020/9/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/* 中心扩展法
	 * 枚举所有可能回文区间的中心的左右边界l和r，奇数个数的回文区间即l==r
	 * (1,1),(1,2)...随后向两端扩展
	 * 若总长为6,则中心可能值为：
	 * 0,0; 0,1 ;1,1; 1,2; 2,2; 2,3... 5,5; 5,6; 6,6
	 * 即l=i
	 * */
	int countSubstrings(string s) {
		int n = s.size(), ans = 0;

		for (int i = 0; i < 2 * n - 1; ++i) {
			int l = i / 2, r = i / 2 + i % 2;
			while (l >= 0 && r < n && s[l] == s[r]) {
				--l;
				++r;
				++ans;
			}
		}
		return ans;
	}
};

int main()
{
	string string1;
	getline(cin,string1);

	Solution solu;
	cout<<solu.countSubstrings(string1)<<endl;

	return 0;
}
