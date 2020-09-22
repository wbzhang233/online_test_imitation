#include <iostream>
#include <vector>
#include <iomanip>  
using namespace std;

int main(){
	//筛选法求素数（删除所有素数的倍数）
	vector<int> v(1000,1);
	for(int i=2;i<1000;++i){
		for(int j=2;i*j<1000;++j){
			if(v[i]){
				v[i*j]=0;
			}
		}
	}
	int x;
	cin>>x;
	int res=0;
	for(int i=2;i<=x/2;++i){
		if(v[i]&&v[x-i]) ++res;
	}
	cout<<res<<setprecision(2)<<endl;	
	cout<<double(1)/3<<setprecision(2)<<endl;	

}