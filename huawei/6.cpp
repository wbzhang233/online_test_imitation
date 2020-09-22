#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ss;
    //cin>>ss;
    //ss="ABCDD ID";
    ss="XSUWHQ";
    
    int ans = 0;
    for(auto iter=ss.rbegin();iter!=ss.rend();iter++){
        if(*iter != ' '){
            ans++;
        }
        else break;
    }
    
    cout<<ans<<endl;
    return 0;
}