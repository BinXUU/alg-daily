#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
    ll a,b,p,res;
    cin>>a>>b>>p;
    res=0;
    while(b)
    {
        if(b&1)
            res=(res+a)%p;
        b>>=1;
        a=2*a%p;
    }
    cout<<res<<endl;
    return 0;
}