#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 26;
const int mod = 1e9 + 7;
int ans[M],n,m;
//组合问题
void genCombination(int u,int idx){
    ans[idx]=u;
    if(idx==m){
        for (int i = 1; i <= m; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    for (int i = u+1; i <=n; i++)
        genCombination(i,idx+1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    genCombination(0,0);
    return 0;
}
