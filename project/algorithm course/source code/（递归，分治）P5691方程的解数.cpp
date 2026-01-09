#include <bits/stdc++.h>
using namespace std;
// 折半搜索
typedef long long ll;

int n, m;
int k[10], p[10];
unordered_map<ll, int> counts;
ll ans = 0;

// 预计算幂
ll quick_pow(ll a, ll b)
{
    ll res = 1;
    for (int i = 0; i < b; i++)
        res *= a;
    return res;
}

// step: 当前处理第几个变量, sum: 当前累加和, limit: 搜索截止位置, is_first_half: 是否是前半部分
void dfs(int step, ll sum, int limit, bool is_first_half)
{
    if (step > limit)
    {
        if (is_first_half)
        {
            counts[sum]++;
        }
        else
        {
            if (counts.count(-sum))
            {
                ans += counts[-sum];
            }
        }
        return;
    }

    for (int x = 1; x <= m; x++)
    {
        dfs(step + 1, sum + (ll)k[step] * quick_pow(x, p[step]), limit, is_first_half);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i] >> p[i];
    }

    int mid = n / 2;

    // 搜索前半部分
    dfs(1, 0, mid, true);

    // 搜索后半部分并匹配
    dfs(mid + 1, 0, n, false);

    cout << ans << endl;

    return 0;
}