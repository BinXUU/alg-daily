#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 110000
ll n,m,i,j,p,q,a[N];
int main()
{
    scanf("%lld",&n);
    for (i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for (i=2;i<=n;i++)
    {
        ll c=a[i]-a[i-1];
        if (c>0)//不要输入 if (c) 因为c是指不为0就好了,如果c为-1,那么最后的布尔值也为1,if(c)的意思是,只要c不为0,那么条件的布尔值都为1
            p+=c;
        else
            q-=c;
    }
    ll ans1=max(p,q),ans2=abs(p-q)+1;
    cout<<ans1<<endl<<ans2;
    return 0;
}
