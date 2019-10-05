#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e4 + 10;
const int mod = 1e9 + 7;

char g[10][10];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

void turnOn(int x,int y){
    for (int i = 0; i <5; ++i) {
        int newx=x+dx[i],newy=y+dy[i];
        if (newx>=0&&newx<5&&newy>=0&&newy<5){
//            g[newx][newy]^=1;
            g[newx][newy] = '0' + !(g[newx][newy] - '0');
        }
    }
}

int work(){
    int ans=1e7;
    for (int k = 0; k <(1<<5); ++k) {
        int res=0;
        char backup[10][10];
        memcpy(backup,g, sizeof(g));

        //因为不清楚第一行到底怎么样才是最优情况，所以选择暴力枚举
        for (int j = 0; j < 5; ++j) {
            if (k>>j&1){
                res++;
                turnOn(0,j);
            }
        }

        for (int i = 0; i <4; ++i) {
            for (int j = 0; j <5; ++j) {
                if (g[i][j]=='0'){
                    res++;
                    turnOn(i+1,j);
                }
            }
        }

        int flag=1;
        for (int i = 0; i <5; ++i) {
            if (g[4][i]=='0'){
                flag=0;
                break;
            }
        }
        if (flag==1) ans=min(ans,res);
        memcpy(g,backup,sizeof(backup));
    }

    if(ans>6) return -1;
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        for (int i = 0; i < 5; i ++ ) cin >> g[i];
        cout << work() << endl;
    }
    return 0;
}


