#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 20;
const int mod = 1e9 + 7;

int n,w,cat[M],bag[M],ans=20;

bool cmp(int a,int b){ return a>b;}

void dfs(int cat_idx,int bag_idx){

    if (bag_idx>=ans) return;

    if (cat_idx>n){
        ans=min(ans,bag_idx);
        return;
    }

    for (int i = 1; i <=bag_idx; ++i) {
        if (bag[i]+cat[cat_idx]<=w){
            bag[i]+=cat[cat_idx];
            dfs(cat_idx+1,bag_idx);
            bag[i]-=cat[cat_idx];
        }
    }

    bag[bag_idx+1]+=cat[cat_idx];
    dfs(cat_idx+1,bag_idx+1);
    bag[bag_idx+1]-=cat[cat_idx];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>w;
    for (int i = 1; i <= n; i++)
        cin>>cat[i];
    sort(cat+1,cat+n+1,cmp);
    dfs(1,0);
    cout<<ans;
    return 0;
}
