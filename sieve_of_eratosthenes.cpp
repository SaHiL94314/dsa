#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//tc-o(nlog(logn))
void sieve(int n,vector<bool> &primes){
    
    
    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i){
                primes[j]=0;
            }
        }
    }
}

int main() {
    // Write C++ code here
    int n=30;
    vector<bool>primes(n+1,1);
    primes[0]=primes[1]=0;
    
    sieve(n,primes);
    
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<primes[i]<<endl;
    }

    return 0;
}
