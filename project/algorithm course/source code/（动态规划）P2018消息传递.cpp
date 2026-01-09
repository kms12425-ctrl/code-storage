#include <bits/stdc++.h>
using namespace std;
// 动态规划O(Nlog(max_degree))
typedef long long ll;
typedef vector<int> vi;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;

vector<int> adj[MAXN];
int n;

// 计算以 u 为根，fa 为父亲时，完成传递的时间
int solve(int u, int fa)
{
    vector<int> times;
    for (int v : adj[u])
    {
        if (v == fa)
            continue;
        times.push_back(solve(v, u));
    }

    if (times.empty())
        return 0;

    // 贪心
    sort(times.begin(), times.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < times.size(); i++)
    {
        res = max(res, times[i] + i + 1);
    }
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    int min_t = 1e9;
    vector<int> results(n + 1);

    for (int i = 1; i <= n; i++)
    {
        results[i] = solve(i, -1);
        min_t = min(min_t, results[i]);
    }

    cout << min_t + 1 << endl;
    bool first = true;
    for (int i = 1; i <= n; i++)
    {
        if (results[i] == min_t)
        {
            cout << i << " ";
            first = 0;
        }
    }
    cout << endl;

    return 0;
}