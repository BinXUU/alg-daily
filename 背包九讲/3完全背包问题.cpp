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

const int M = 1e3 + 10;
const int mod = 1e9 + 7;
int weight[M],value[M];

//表示总体积为i的情况下，最大价值为多少
int dp[M];
int n,total;
//O(NV)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>total;
    for (int i = 1; i <= n; i++) cin>>weight[i]>>value[i];

    //不断的考虑把第i个物品加进去的情况
    for (int i = 1; i <= n; i++)
    {
        for (int j = weight[i]; j <=total; j++)
        {
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    
    cout<<dp[total];
    
    return 0;
}
