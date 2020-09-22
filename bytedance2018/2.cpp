#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;

#if 0
	cin >> N;
	vector<int> nums;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
#elif 1
    N = 10;
    vector<int> nums={81,87,47,59,81,18,25,40,56,0};
#elif 0
	N = 3;
	vector<int> nums = {6, 2, 1};
#endif



	long long ans = 0;
	// 1.排序
	sort(nums.begin(), nums.end());
	// 2.求容量为n的密集的最大的值
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		int min_num = nums[N - i]; //集合中的最小值
		for (int j = 1; j <= i; j++) {
			sum += nums[N - j]; //求最大的i个数
		}
		long long curr_max = sum * min_num;
		// ans = curr_max>ans ? curr_max :ans;
		ans = max(ans, curr_max);
	}

	cout << ans << endl;

	return 0;
}