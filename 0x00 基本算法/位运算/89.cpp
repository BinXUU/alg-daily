#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


//a^b mod p
int main(int argc, char const *argv[]) {
    int a,b,p;
    cin>>a>>b>>p;
    int res=1;
    while (b)
    {
        if(b&1) res=res*1ll*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    cout<<res;
    return 0;
}
