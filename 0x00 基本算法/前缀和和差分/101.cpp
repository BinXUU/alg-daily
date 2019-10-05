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

int n,p,h,m;
int h[M],diff[M];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>p>>h>>m;
   
   int a,b;
   while (m--)
   {
      cin>>a>>b;
      if(a>b) swap(a,b);
      diff[a+1]--;diff[b]++;
   }
   
   for (int i = 1; i <=n ; i++)
      h[i]=h[i-1]+diff[i];
   cout<h[]
   system("pause");
   return 0;
}
