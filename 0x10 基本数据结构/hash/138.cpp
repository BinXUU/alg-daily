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
const int base = 13331;

char DNA[M];
ull H[M],bsqrt[M];
int loop,l1,r1,l2,r2;


bool query(int l1,int r1){
   return H[r1]-H[l1]*bsqrt[r1-l1+1];
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>DNA;
   cin>>loop;
   int len=strlen(DNA);
   bsqrt[0]=1;
   for (int i = 1; i <= len; i++)
   {  
      bsqrt[i]=bsqrt[i-1]*base;
      H[i]=H[i-1]*base+DNA[i-1]-'a'+1;
   }
   
   while (loop--)
   {
      cin>>l1>>r1>>l2>>r2;
      if(query(l1,r1)==query(l2,r2)) cout<<"YES";
      else{cout<<"No";}
   }
   
   system("pause");
   return 0;
}
