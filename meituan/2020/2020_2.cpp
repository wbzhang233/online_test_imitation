// 字符串最长公共前缀
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


int commlength(string s1,string s2)
{
    if(!s1.length() || !s2.length() ){
        return 0;
    }
    int res=0;
    int min_length = min(s1.length(),s2.length());
    for(int i=0;i<min_length;i++){
        if(s1[i]==s2[i]){
            res++;
        }else break;
    }

    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<string> strings;
    // 输入字符串
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        strings.push_back(str);
    }

    // 后面多次查询
    int ind1,ind2;
    while(cin>>ind1>>ind2){
        cout<<commlength(strings[ind1-1],strings[ind2-1])<<endl;
    }
    
    return 0;
}