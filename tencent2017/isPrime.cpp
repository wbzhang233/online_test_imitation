#include<bits/stdc++.h>
using namespace std;

bool isPrime(unsigned long long n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (unsigned short i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

bool isPrime2(long long n){
    if(n<=3) return n>1;
    else if(n % 2 == 0 || n % 3 == 0) return false;
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}


int main(){
    long long n=89;
    cout<<isPrime2(n)<<endl;
    return 0;
}