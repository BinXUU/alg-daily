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

class Solution {
public:
    string simplifyPath(string path) {
        string res,s;
        for(auto c:path){
            if(res.empty()) res+=c;
            else if(c!='/') s+=c;
            else{
                if(s=='..'){

                }
                
            }
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    system("pause");
    return 0;
}
