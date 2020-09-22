#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long> getPrime(long x)
{
    if(x<=3) return {x};
    vector<long> res;
    //假设x为合数，则按以下顺序分解
    // 获得2、3的质因子
    while(x%2==0){
        x=x/2;
        res.push_back(2);
    }
    while(x%3==0){
        x = x/3;
        res.push_back(3);
    }
    if(x>=5){
        // 大于3的质数均为6N-1或者6N+1
        cout<<"Mid: "<<x<<endl;
        for(int i=5;i*i<=x;i+=6){
            // 按照当前质因子进行分解
            while( x%i==0){
                x=x/i;
                res.push_back(i);
            }
            while(x%(i+2)==0){
                x=x/(i+2);
                res.push_back(i+2);
            }
            cout<<"i*i: "<<i*i<<endl;
            cout<<"x: "<<x<<endl;
        }
    }
    if(res.size()==0) 
        return {x}; //无法分解，表明x为质数

    cout<<"Final: "<<x<<endl;
    if(x!=1) res.push_back(x); //最后存在一个很大的质因子
    
    return res;
}


int main()
{
    long x;
    // cin>>x;

    x =2*3*5*7*11*13*1277;
    vector<long> res= getPrime(x);
    for(auto ele:res){
        cout<<ele<<" ";
    }
    
    return 0;
}