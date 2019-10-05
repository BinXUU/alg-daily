#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int cows[N];
double sum[N];

bool check(double avg)
{
    for (int i = 1; i <= n; i ++ )
        sum[i] = sum[i - 1] + cows[i] - avg;

    double mins = 0;
    for (int i = m, j = 0; i <= n; i ++, j ++ )
    {
        mins = min(mins, sum[j]);
        if (sum[i] - mins >= 0) return true;
    }

    return false;
}

int main()
{
    cin >> n >> m;
    double l = 0, r = 0;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> cows[i];
        r = max(r, (double)cows[i]);
    }

    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    printf("%d\n", (int)(r * 1000));

    return 0;
}
