#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e4 + 10;
const int mod = 1e9 + 7;

/*
一个不变量：边的编号

tot就是边的一个编号
edge存放的是实际边的权值
ver[tot]存放编号为tot这条边的终点
nxt存放的是这条边下一条边的编号
head存放的是头插法中直接在头后面的边的编号
 */
int head[M],edge[M],nxt[M],ver[M],tot=1;

//加入有
void addEdge(int x,int y,int w){
    ver[++tot]=y;edge[tot]=w;
    //运用头插法插入节点
    nxt[tot]=head[x];head[x]=tot;
}

//访问从x出发的所有边
for (int i = head[x]; i; i=nxt[i])
{
    int y=ver[i],z=edge[i];
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    system("pause");
    return 0;
}
