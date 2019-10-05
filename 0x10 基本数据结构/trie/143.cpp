#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e5+ 10;
const int mod = 1e9 + 7;

int a[M],n;
//1:[1],0:[0]  leave数组记录下数字
int child[M*32][2],tot=0,ans=0;


void insert(int n){
    int p=0,bit;
    for (int i = 30;i>=0;i--)
    {
        bit=(n>>i)&1;
        if(child[p][bit]==0) child[p][bit]=++tot;
        p=child[p][bit];
    }
}

int Search(int n){
    int p=0,bit,res=0;
    for (int i = 30;i>=0;i--)
    {
        bit=(n>>i)&1;
        if(child[p][bit^1]!=0) {
            res+=(1<<i);
            p = child[p][bit^1];
        }
        else{p=child[p][bit];}
    }
    return res;
}



int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        insert(a[i]);
        ans=max(ans,Search(a[i]));//取最大值
    }

    cout<<ans<<endl;
    return 0;
}
