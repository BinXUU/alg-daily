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

//把地图化为一个数组

int map[M][M],loop,R;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int x,y,w,res=0;
   cin>>loop>>R;
   int n=R,m=R;
   while (loop--)
   {
      cin>>x>>y>>w;
      map[x][y]+=w;
      x++;y++;
      n=max(n,x);
      m=max(m,y);
   }

   for (int i = 1; i <=n; i++)
      for (int j = 1; j <= m; j++)
         map[i][j]=map[i-1][j]+map[i][j-1]+map[i][j]-map[i-1][j-1];          
          

   //算边长为r-1的矩形
   for (int i = R; i <= n; i++)
       for (int j= R; j <=m; j++)
         res=max(res,map[i][j]+map[i-R][j-R]-map[i][j-R]-map[j-R][i]); 
         
   cout<<res;   
   system("pause");
   return 0;
}
