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
const int N = 1010, C = 110, M = 20010;

const int M = 1e4 + 10;
const int mod = 1e9 + 7;

int n,m;
int h[N],e[M],w[M],next[M],,tot=0;
int price[N];

int dijkstra(int start,int end,int cap){

}

void add(int x,int y,int w){
    e[tot]=;
}


int main(){
    scanf("%d%d", &n, &m);
    memset(h,-1,sizeof h);
    for (int i = 0; i < n; i++) scanf("%d",&price[i]); 
    while (m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }

    int query;
    
    return 0;
}
