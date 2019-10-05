#include <bits/stdc++.h>
using namespace std;
int n,f[1<<20][21],i,j,k;
int weight[21][21];
int main()
{
    ios::sync_with_stdio(false);//加快cin的读入速度，但是scanf将会不能用。
    cin>>n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            cin>>weight[i][j];
    memset(f,0x3f, sizeof(f));
    f[1][0]=0;
    //目前状态到i
    for (i = 1; i < (1<<n); ++i) {
        //目前到达了点j
        for (j = 0; j < n; ++j) {
            if ((i>>j)&1){
                //从k点过来的
                for (k = 0;  k< n; ++k) {
                    //要求k点也被用过
                    if ((i-(1<<j))>>k&1)
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+weight[k][j]);
                    }
                }
            }
        }
    cout<<f[(1<<n)-1][n-1];
    return 0;
}
