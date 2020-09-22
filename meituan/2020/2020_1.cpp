// 外賣小哥的保溫箱
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> boxes(n, vector<int>(2, 0));
    for (int j = 0; j <= 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            boxes[i][j] = x;
        }
    }
    // 排序,按照保溫箱的容量由大到小排序
    auto cmp = [](vector<int> a, vector<int> b) { return a[1] > b[1]; };
    sort(boxes.begin(), boxes.end(), cmp);

    // 思路1：統計所有貨物數目S，求至少前n個箱子容量大於S，以及前N個箱子已有貨物數目N
    // 則答案為n和S-N
    // 統計所有貨物數目
    int sum = 0, topN = 0,time = 0;
    for(auto ele:boxes){
        sum +=ele[0];
    }

    // vector<int> a;
    // a.assign(10);

    int ind = 0,goods = sum;
    while (sum>0 && ind<boxes.size() )
    {
        topN += boxes[ind][0]; // 前N個箱子中的貨物數
        sum -= boxes[ind][1]; //減去容量
        ind++;
    }
    // 直到貨物數目被裝完，即sum<0，此時足夠裝下
    cout<<ind<<" "<<goods-topN<<endl;

    /*
    // 思路2：從最大箱子開始，如果其未裝滿，則ind=0；從1開始，將貨物填滿前ind個箱子，如果滿了，則ind+1
    直到所有箱子結束或者為0
    int ind = 0, time = 0;
    while (boxes[ind][0] >= boxes[ind][1])
    {
        ind ++;
    }
    for (size_t i = ind+1; i < boxes.size(); i++)
    {
        if (boxes[i][0]+boxes[ind][0]>=boxes[ind][1])
        {
            // 轉移時間
            time += (boxes[ind][1]-boxes[ind][0]);
            // 當前減去
            boxes[i][0] -= (boxes[ind][1]-boxes[ind][0]);
            // 第二個可以把ind裝滿，則把ind裝滿
            boxes[ind][0]=boxes[ind][1];
            ind++;
        }else{
            // 當前清空
            time +=  boxes[i][0];
            boxes[ind][0] += boxes[i][0];
            boxes[i][0] = 0;
        }
    }
    cout<<ind<<" "<<time<<endl;
    */

    return 0;
}