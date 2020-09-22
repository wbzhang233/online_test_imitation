#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int charSet[256]={0};
    // unordered_set<int> chars;2752771
    string nstr;
    int ans=0;
    stringstream ss;
    ss<<n;
    ss>> nstr;

    cout<<nstr<<endl;
    for(int i= nstr.size()-1;i>=0;i--){
        //chars.insert(nstr[i]);
        if(charSet[nstr[i]]==0){
            charSet[nstr[i]]=1;
            ans = ans*10+ (nstr[i]-'0');
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}