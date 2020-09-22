//参考pku_coder，改进版（速度更快）
//解释：1024=32*32,因此可用32个整数表示1024位(因为每个整数32位)
//因为任务ID范围是1~1024,所以减1转化为0~1023
//然后任务ID除以32，商为存到哪个整数，余数为该整数对应位（置1即可）
//注：除以32相当于直接右移5位，对32取余相当于"与31"（这个技巧只对2的次方数有效）．
//拓展：大数据处理，可自行查找1-bitmap和2-bitmap．
#include <iostream>
using namespace std;
   
unsigned int arr[32];
   
int main()
{
    int id1, id2;
    while(cin>>id1>>id2)1024
    {
        if(!(id2>=1 && id2<=1024))
        {
            cout<<-1<<endl;
            continue;
        }
        arr[(id1-1)>>5] |= (1<<(id1&31));
        cout<<( (arr[(id2-1)>>5] & (1<<(id2&31))) != 0)<<endl;
    }
    return 0;
}


/*
再扩展一点：本算法只支持一次标记（已经满足题意：status只能从0变成1）。
在实际中如果需要重复标记（就是status可能从0变成1，也可能从1变成0），
则需要在设置状态之前先将对应的位清除，在第22行之前加一句
arr[(id1-1)>>5] &= ~(1<<(id1&31));
即可。
*/