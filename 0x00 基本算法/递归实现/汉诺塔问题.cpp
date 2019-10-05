#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e4 + 10;
const int mod = 1e9 + 7;

int t=0;

//层数，起始柱，过渡柱，结束柱
void h(int z,char A,char B,char C){
    if (z==1){
        t++;
        printf("%c-->%c\n", A,C);
        return;
    }
    h(z-1,A,C,B);
    t++;
    printf("%c-->%c\n", A,C);
    h(z-1,B,A,C);
}

int main(){
    int z;
    printf("the number of layers:\n");
    scanf("%d",&z);
    h(z,'A','B','C');
    printf("total cost:%d\n",t);
    return 0;
}
