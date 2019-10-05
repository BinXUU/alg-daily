#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e4 + 10;
const int mod = 1e9 + 7;
const int base=131;

char  str[M];
ull h[M];
int SA[M],Height[M],hl[M],p[M],len;

//hash (x,y] 模板
inline int getHashValue(int x,int y){
    return hl[y]-hl[x]*p[y-x];
}


int getMaxPrefix(int x,int y){
    int l=0,r=min(len-x,len-y);
    int mid;
    while (l<r)
    {
        mid=l+r>>1;
        if(getHashValue(x,x+mid)==getHashValue(y,y+mid)){l=mid;}
        else{r=mid-1;}
    }
    
    return l;
 
}
bool cmp(int x,int y){
    int max_pre=getMaxPrefix(x,y);
    int xvalue=((x+max_pre+1)>len)?INT_MIN:str[x+max_pre+1];
    int yvalue=((y+max_pre+1)>len)?INT_MIN:str[y+max_pre+1];
    return xvalue<yvalue;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%s",str);
    len=strlen(str);

    p[0]=1;
    for (int i = 1; i <= len; i++)
    {
        hl[i]=hl[i-1]*base+str[i]-'a'+1;
        p[i]=p[i-1]*base;
        SA[i]=i;
    }
    sort(SA+1,SA+len+1,cmp);

    for (int i = 0; i <= len ; i++) cout<<SA[i];
    puts("");
    
    for (int i = 1; i <=len ; i++){
        if(i==1) cout<<"0"<<" ";
        else cout<<getMaxPrefix(i,i-1)<<" ";
    }
        
    return 0;
}
