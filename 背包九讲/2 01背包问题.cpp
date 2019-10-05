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

//优化一：二维数组变为一维数组 
// int dp[M][M];
int dp[M];
int n,total;
//O(NV)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>total;
    for (int i = 1; i <= n; i++) cin>>weight[i]>>value[i];

    // 两个选择：装或者不装第i个物品
    for (int i = 1; i <= n; i++)
    {
        for (int j = total; j >=weight[i]; j--)
        {
            //dp枚举的就是小于等于 情况下的最大价值
            //dp[j-weight[i]]保证了dp中保留的是在加入第i个物品后的状态
            //为下一次循环枚举第i+1个物品做准备
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            // dp[i][j]=dp[i-1][j];
            // if(j>=weight[i]) dp[i][j]=max(dp[i][j],value[i]+dp[i-1][j-weight[i]]); 
        }
    }

    cout<<dp[total];
    
    return 0;
}
