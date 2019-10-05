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
typedef pair<int,int> PII;
const int N = 1010, M = 200010;
int h[N],rh[N],e[M],ne[M],we[M],idx=0;
int n,m;
int S,T,k,a,b,c;
int dist[N],f[N];
int st[N];

void add(int* hh,int a,int b,int w){
    e[idx]=b,we[idx]=w,ne[idx]=hh[a],hh[a]=idx++;
}

int dijkstra(){
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    memset(dist,0x3f,sizeof dist);
    heap.push({0,T});
    dist[S]=0;
    while (heap.size())
    {
        auto t=heap.top();
        heap.pop();

        int ver=t.second;
        if(st[ver]) continue;
        st[ver]=1;

        for (int i = rh[ver] ; i!=-1; i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+we[i]){
              dist[j]=dist[ver]+we[i];
              heap.push({dist[j],j});  
            }
        }
        memcpy(f,dist,sizeof dist);
    }
}

int Astar(){
    priority_queue<pair<int,PII>,vector<pair<int,PII>>,greater<pair<int,PII>>> heap;
    heap.push({f[S],{0,S}});
    memset(st,0,sizeof st);
    while (heap.size())
    {
        auto t=heap.top();
        int ver=t.second.second,distance=t.second.first;
        if(st[ver]>=k) continue;
        st[ver]++;
        if(ver==T && st[ver] == k) return distance;

        for (int i = h[ver]; i!=-1 ; i=ne[i])
        {
            int j=e[i];
            if(st[j]<k){
                heap.push({distance+we[i]+f[j],{distance+we[i],j}});
            }
        }
    }
    
    return -1;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(h,a,b,c);
        add(rh,b,a,c);
    }
    
    scanf("%d%d%d",&S,&T,&k);

    if(S==T) k=k+1;
    dijkstra();

    printf("%d",Astar());

    return 0;
}
