#include <iostream>
#include <vector>

using namespace std;

void printStr(string s)
{
    int n = s.length();
    // 补充0
    while(s.length()%8!=0)
    {
        s.push_back('0');
    }

    // cout<<"s: "<<s<<endl;
    for(int i =0; i<s.length();i++){
        if(i>1 && i%8==0){
            cout<<endl;
        }
        cout<<s[i];
    }
}

int main()
{
    string s1,s2;
    // cin>>s1;
    s1 = "urivthvtlqqerctlxmjvkgvfclaaduwmaadedpadanl";
    s2="batkqdhjnrwtsmzidswdnenqpsblsszldyttytrgenaizwehntqiaaufble";
    printStr(s1);
    // cin>>s2;
    cout<<endl;
    printStr(s2);

    return 0;
}