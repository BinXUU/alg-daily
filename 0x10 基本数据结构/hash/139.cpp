#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e6 + 10;
const int mod = 1e9 + 7;
const int base = 13331;

char str[M];
ull hl[M],hr[M],bsqrt[M];
int loop,l1,r1,l2,r2,len,res=0;

//[x,y]
ull getHash(ull h[],int l,int r){
    return h[r]-h[l-1]*bsqrt[r-l+1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>loop;
    int T=1;
    while (scanf("%s", str + 1), strcmp(str + 1, "END")){
        len=strlen(str);
        int tlen=len*2;
        char padding='a'+27;

        for (int i =len,k=tlen; i > 0; i--,k-=2)
        {
            str[k]=str[i];
            str[k-1]=padding;
        }

        bsqrt[0]=1;
        //从str[1]开始： #1#2#3...#len
        for (int i = 1,k=tlen; k>0;i++,k--)
        {
            hl[i]=hl[i-1]*base+str[i]-'a'+1;
            hr[k]=hr[k+1]*base+str[k]-'a'+1;
            bsqrt[i]=bsqrt[i-1]*base;
        }

        //二分答案
        for (int i = 2; i < tlen; i++)
        {
            //回文串长度
            int l=0,r=min(tlen-i,i-1);

            while(l<=r){
                int mid=(l+r)>>1;
                if(getHash(hl,i-mid,i-1)==getHash(hr,i+1,i+mid)) l=mid;
                else r=mid-1;
            }
            if(str[i]<='z'){
                res=max(res,(l-1)>>1);
            }else{
                res=max(res,l>>1);
            }
        }
        printf("Case %d:%d\n",T++,res);
    }
    return 0;
}
