
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	void getAns(int N, vector<int> nums, int &ans) {
		// 以每个点为起点，往后寻找区间，累加和直到遇到一个比它小的数或者到尽头
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum=nums[i];//假设该点为最小值，则求该点为最小值时的最大区间和
			int j=i+1;
			while (nums[j]>=nums[i] &&j<nums.size() ){
				sum+=nums[j++];
			}
			int k=i-1;
			while (nums[k]>=nums[i] && k>=0){
				sum+=nums[k--];
			}
			ans = max(ans,sum*nums[i]);
		}
	};
};

class Solution2{
public:
	void getAns(int N,vector<int> nums,int &ans){
		vector<vector<int> > dp(N,vector<int>(N,0)); //表示
		// 2.二维数组动态规划
		// 初始条件，dp[0][0]=
		for(int i=1;i<=N;i++){
			int sum = 0;
			int min_num = nums[N-i]; //集合中的最小值


			// ans =max(ans,curr_max);
		}
	}
};


int main()
{
    int N;
#if 0
     cin>>N;
     vector<int> nums;

     for(int i=0;i<N;i++){
         int x;
         cin >> x ;
         nums.push_back(x);
     }
#elif 1
    N = 10;
    vector<int> nums={81,87,47,59,81,18,25,40,56,0};
#elif 0
     N = 3;
     vector<int> nums={6,2,1};
#endif

    int ans = 0;
	Solution solu;
	solu.getAns(N,nums,ans);

    cout<<ans<<endl;

    return 0;
}