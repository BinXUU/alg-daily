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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x=0,y=0;
        int m=matrix.size(),n=matrix[0].size(),tot=m*n;
        vector<int> res;
        vector<vector<bool>> st(m, vector<bool>(n, false));
        int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
        
        int d=0;
        for (int i = 0; i < tot; i++)
        {
            int a=x+dx[d],b=y+dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]){
                d=(d+1)%4;
                a=x+dx[d],y=y+dy[d];
            }
            res.push_back(matrix[a][b]);
            st[a][b]=1;
            x=a,y=b;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    system("pause");
    return 0;
}
