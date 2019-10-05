#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


// class Solution {
//     int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
// public:
//     vector<int> printMatrix(vector<vector<int> > matrix) {
//         vector<int> res;
//         int r=matrix.size()-1;
//         int c=matrix[0].size()-1;
//         int tot=r*c;
//         int x=0,y=0,idx=0;
//         for(int i=0;i<tot;i++){
//             res.push_back(matrix[x][y]);
//             int a=dx[idx],b=dy[idx];
//             if(a>||b<){
                
//             }
      
//         }
//     }
// };


class Solution {
public:
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
            stack<int> stk;
            for (int i = 0; i < pushV.size(); i++)
            {
                stk.push(pushV[i]);
                while (stk.top()==popV.){

                }
              
            }
            
    }
};