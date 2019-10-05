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
vector<int> path;
void dfs(int i,int state){
    if(i==n){
        for (int i = 0; i < n; i++)
        {
            if((state>>i)&1){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    
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
