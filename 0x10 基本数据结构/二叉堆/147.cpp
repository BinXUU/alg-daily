#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,K,a[N],pre[N],nxt[N];
bool del[N];
ll ans=0;
struct cmp
{
    bool operator()(int x,int y)
    {
        return a[x]>a[y];
    }
};
priority_queue<int,vector<int>,cmp>q;
int main()
{
    n=read();
    K=read();
    a[1]=read();
    for(int i=2; i<=n; i++) 
        a[i]=read(),a[i-1]=a[i]-a[i-1];
    n--;
    a[0]=inf;
    for(int i=1; i<=n; i++) 
        q.push(i),pre[i]=i-1,nxt[i]=i+1>n?0:i+1;
    while(K--)
    {
        int x=q.top();
        q.pop();
        while(del[x])
        {
            x=q.top();
            q.pop();
        }
        ans+=a[x];
        del[pre[x]]=1;
        del[nxt[x]]=1;
        a[x]=a[pre[x]]+a[nxt[x]]-a[x];
        q.push(x);
        pre[x]=pre[pre[x]];
        nxt[x]=nxt[nxt[x]];
        nxt[pre[x]]=x;
        pre[nxt[x]]=x;
    }
    cout<<ans;
    return 0;
}
