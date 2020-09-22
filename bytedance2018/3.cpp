
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Idea
{
    /* data */
    int no,time,level,pri;
    Idea(int _no,int _time,int _level,int _pri):
        no(_no),time(_time),level(_level),pri(_pri) {}
};


int main()
{
    int N,M,P;
    cin >>N >>M >>P;
    vector<Idea> nums;

    for(int i=0;i<P;i++){
        int x[4];
        for(int j=0;i<4;j++){
            cin >> x[j] ;
        }
        nums.push_back(Idea(x[0],x[1],x[2],x[3]));
    }

    // 时间点 
    int period[P]={0};

    // M个程序员同时开工，贪心的选择


    return 0;
}