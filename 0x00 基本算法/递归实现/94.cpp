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
vector<int> nums,ans;
int n,used[M];

void genPermutation(int idx){
    if(idx==n){
        for (int i = 0; i < n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i = 1; i <=n ; i++)
    {
        if(!used[i]){
            ans.push_back(i);
            used[i]=1;
            genPermutation(idx+1);
            used[i]=0;
            ans.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    genPermutation(0);
    system("pause");
    return 0;
}
