// https://www.nowcoder.com/test/question/done?tid=35770036&qid=894530#summary

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<vector<int> > tasks;

    int x,y;
    for (size_t i = 0; i < N; i++)
    {
        vector<int> task;
        cin>>x>>y;
        task.push_back(x);
        task.push_back(y);
        tasks.push_back(task);
    }

    int ans = 0;
    // 动态规划
    
    

    return 0;
}