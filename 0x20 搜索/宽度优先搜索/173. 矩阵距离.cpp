#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, m;
int d[N][N];
char g[N][N];
PII q[N * N];

void bfs()
{
    int hh=0,tt=-1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(g[i][j]=='1'){
                d[i][j]=0;
                q[++tt]={i,j};
            }
        }
    }

    int dx[];
    while(hh>=tt){
        PII t=q[hh++];
        for (int i = 1; i <= ; i++)
        
        
    }
    
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) scanf("%s", g[i] + 1);

    bfs();

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            printf("%d ", max(d[i][j], 0));
        puts("");

    return 0;
}