#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n,cnt,t,m,p,ans;//ans:全部进程都运行完毕的时刻,cnt:被放入过等待队列的进程总数
queue<PII> waits; //等待队列，first: 内存长度，second: 占用时间
set<PII> runs;     //当前进程，first: 起始下标，sercond：长度
priority_queue<PII, vector<PII>, greater<PII>> endts;    //小根堆，维护释放顺序，first: 释放时间，second: 起始下标  
bool give(int t, int m, int p)
{
    for(auto it=runs.begin();it!=runs.end();it++)//扫描所有的红色部分
    {
        auto jt=it;
        jt++;//jt相当于i+1,it相当于i
        if (jt!=runs.end())
        {
            int start=it->first+it->second;
            if (m<=jt->first-start)//如果说本空余内存段满足条件
            {
                runs.insert({start,m});//加入
                endts.push({t+p,start});//记录下来
                return true;
            }
        }
    }
    return false;
}
void finish(int t)
{
    while (endts.size() && endts.top().first<=t)//判断小根堆顶的进程（结束时间最早的）是否能结束
    {
        int f=endts.top().first;
        while (endts.size() && endts.top().first==f)////可能有多个结束进程时间相同的进程
        {
            auto top=endts.top();
            endts.pop();//出堆
            auto it=runs.lower_bound({top.second, 0});
            runs.erase(it);
        }
        ans=f;//更新
        while (waits.size())//检查等待队列的队首是否能安排
        {
            auto front=waits.front();//等待的队头
            if (give(f,front.first,front.second))//可以放入
                waits.pop();
            else
                break;
        }
    }
}
void init()
{
    ios::sync_with_stdio(false);
    cin>>n;
    runs.insert({-1, 1}),runs.insert({n, 1});//边界处理
    while (cin>>t>>m>>p,t || m || p)
    {
        finish(t);//先释放,确保剩余内存最大化.
        if (!give(t,m,p))//不可以加入
        {
            waits.push({m,p});//等待队列欢迎你
            cnt++;//记录,题目的计划二
        }
    }
    finish(2e9);//你可以认为全部释放.
    cout<<ans<<endl<<cnt<<endl;
}
int main()
{
    init();
    return 0;
}
