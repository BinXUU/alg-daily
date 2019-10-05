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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str="527389416819426735436751829375692184194538267268174593643217958951843672782965341"
    int cnt=0;
    for(auto s:str){
        cnt++;
    }
    cout<<cnt;
    system("pause");
    return 0;
}
