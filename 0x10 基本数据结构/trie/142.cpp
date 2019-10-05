//用数组模拟trie，这就是典型的用数组模拟链表

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1e6 + 10;
const int mod = 1e9 + 7;
int n,m;

//开一个较大的数组，模拟trie树，默认根节点是不存放字母
int trie[M][27]; //记录下下一个节点所在的位置，默认的根就是trie[0]
int tail[M];
int idx; //记录在子节点在数组中的索引

void insert(string s){
    int p=0,ch;
    for (int i = 0; s[i]; i++)
    {
        ch=s[i]-'a';
        if(trie[p][ch]==0) trie[p][ch]=++idx;
        p=trie[p][ch];
    }
    tail[p]++;
}


int search(string s){
    int p=0,ch,cnt=0;
    for (int i = 0; s[i]; i++)
    {
        ch=s[i]-'a';
        if(trie[p][ch]==0) break;
        p=trie[p][ch];
        cnt+=tail[p];
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        insert(s);
    }
    for(int i=0;i<m;i++){
        cin>>s;
        int res = search(s);
        cout<<res<<endl;
    }
    return 0;
}
