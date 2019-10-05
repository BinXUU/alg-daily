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
int max_val,sum,true_n;
int stick[M];
bool st[M];
int cmp(int a,int b){return a>b;}

//第几根木棒，目前这根木棒长度，从哪根原始木棒开始枚举,
//相当于从第start根木棍开始枚举试图拼出来第idx根木棒；
/*
如果当前木棍能恰好填满一根原始木棍，但因剩余的木棍无法组合出
合法解而返回，那么让我们考虑接下来的两种策略，一是用更长的木棍来
代替当前木棍，显然这样总长度会超过原始木棍的长度，违法。二是用更
短的木棍组合来代替这根木棍，他们的总长恰好是当前木棍的长度，但是
由于这些替代木棍在后面的搜索中无法得到合法解，当前木棍也不可能替
代这些木棍组合出合法解。因为当前木棍的做的事这些替代木棍也能做到。
所以，当出现加上某根木棍恰好能填满一根原始木棍，但由在后面的搜索中
失败了，就不必考虑其他木棍了，直接退出当前的枚举。（剪枝二）
 */
bool dfs(int idx,int len,int start){
    if(idx*max_val==sum) return true;
    if(len==max_val) return dfs(idx+1,0,0);

    int fail;
    for (int i = start; i <= true_n; i++)
    {
        if(st[i]!=0||stick[i]+len>max_val||stick[i]==fail) continue;
        st[i]=1;
        if(dfs(idx,stick[i]+len,i+1)) return true;
        fail=stick[i];
        st[i]=0;
        /*
        作为第一根木棒拼接失败，即使后面更小的木棍成功也没用，
          因为这根木棒迟早都要用
         */
        if(len==0) return false;
        //作为最后一根木棒拼接失败，其他更短的木棍相对于自己是更优选择，但是他们也拼不出来木棒
        if(stick[i]+len==max_val) return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin>>n,n!=0)
    {
        memset(st,0,n);
        max_val=0,sum=0,true_n=-1;
        int s;
        for (int i = 0; i < n; i++)
        {
            cin>>s;
            if(s>50) continue;
            stick[++true_n]=s;
            sum+=s;
        }
        sort(stick,stick+true_n,cmp);
        max_val=stick[0];

        int half=sum>>1,flag=0;
        while(max_val<=sum)
        {
            if(sum%max_val!=0){
                max_val++;
                continue;
            }
            if(dfs(0,0,0)){flag=1;break;}
            max_val++;
        }

//        if(flag==0) max_val=sum;
        cout<<max_val<<"\n";
    }
    return 0;
}



//另外一个版本
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 70;

int n;
int sum, length;
int sticks[N];
bool st[N];

bool dfs(int u, int cur, int start)
{
    if (u * length == sum) return true;
    if (cur == length) return dfs(u + 1, 0, 0);

    for (int i = start; i < n; i ++ )
    {
        if (st[i]) continue;
        int l = sticks[i];
        if (cur + l <= length)
        {
            st[i] = true;
            if (dfs(u, cur + l, i + 1)) return true;
            st[i] = false;

            // 剪枝3 如果是第一个木棒失败，则一定失败
            if (!cur) return false;

            // 剪枝4 如果是最后一个木棒失败，则一定失败
            if (cur + l == length) return false;

            // 剪枝2 跳过相同木棒
            int j = i;
            while (j < n && sticks[j] == l) j ++ ;
            i = j - 1;
        }
    }


    return false;
}

int main()
{
    while (cin >> n, n)
    {
        sum = 0, length = 0;
        memset(st, false, sizeof st);

        for (int i = 0; i < n; i ++ )
        {
            cin >> sticks[i];
            if (sticks[i] > 50) continue;
            sum += sticks[i];
            length = max(length, sticks[i]);
        }

        // 剪枝：优化搜索顺序
        sort(sticks, sticks + n);
        reverse(sticks, sticks + n);

        for (int i = 0; i < n; i ++ )
            if (sticks[i] > 50)
                st[i] = true;

        while (true)
        {
            if (sum % length == 0 && dfs(0, 0, 0))
            {
                cout << length << endl;
                break;
            }
            length ++ ;
        }
    }

    return 0;
}
