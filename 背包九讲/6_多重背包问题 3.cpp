#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//二进制优化 算法复杂度：O(n*log(num)*v)
struct MyStruct
{
    int v, w;
};
int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, V; cin >> N >> V;//N 种物品, V 背包体积 

    vector<int>dp(V + 1, 0);
    //把 N 个物品分解 例如 s 个 i 物品, 分解为 1 + 2 + 4 + 8 ...个 i 物品 ,然后组合形成一个新物品,存入 f 中
    vector<MyStruct>f;

    int s, v, w;

    for (int i = 0; i < N; ++i) {
        cin >> v >> w >> s;
        for (int k = 1; k <= s; s -= k, k <<= 1)
            f.push_back({ v * k,w * k });
        if (s)f.push_back({ v * s,w * s });
    }

    for (auto vi : f) {
        for (int i = V; i >= vi.v; --i)
            dp[i] = max(dp[i], dp[i - vi.v] + vi.w);
    }

    cout << dp[V] << endl;

    return 0;
}
