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
int weight[M],value[M],nums[M];

//优化一：二维数组变为一维数组 
// int dp[M][M];
int dp[M];
int n,total;
//O(NV)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int add_w=0,add_v=0;
    cin>>n>>total;
    for (int i = 1; i <= n; i++) cin>>weight[i]>>value[i]>>nums[i];
    for (int i = 1; i <=n ; i++)
    {
        for (int j = total; j >=0; j--)
        {
            for (int k = 0; k <nums[i]; k++)
            {
                add_w+=weight[i];
                add_v+=value[i];
                if(j-add_w<0){break;}
                dp[j]=max(dp[j-add_w]+add_v,dp[j]);
            }
            add_w=0;
            add_v=0;
        }
        
    }
    
   
    cout<<dp[total];
    
    return 0;
}
