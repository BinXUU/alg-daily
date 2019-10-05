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

int n;

void dfs(int num,int state){
    if(num==n){
        for (int i = 0; i < n; i++)
        {
            if((state>>i)&1){
                cout<<i+1<<" ";
            }
            return;
        }
        cout<<endl;
    }
    dfs(num+1,state);
    dfs(num+1,state|(1<<num));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    dfs(0,0);
    system("pause");
    return 0;
}
