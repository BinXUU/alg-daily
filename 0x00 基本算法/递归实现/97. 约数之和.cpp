#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e4 + 10;
const int mod = 9901;

int a,b;

int qmi(int a,int k){
    a%=mod;
    int res=1;
    while(k){
        if (k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

int sum(int p,int k){
    if (k==0) return 1;
    else if (k%2==0) return (p%mod*sum(p,k-1)%mod+1)%mod;
    return sum(p,k/2)%mod*(1+qmi(p,k/2+1))%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int res=1;
    cin>>a>> b;
    for (int i = 2; i <=a; ++i) {
        int s=0;
        while(a%i==0){
            s++;
            a/=i;
        }
        if (s) res=res*sum(i,s*b)%mod;
    }

    if (!a) res = 0;
    cout<<res;
    return 0;
}
