#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 400005;
int n, m, k;
vector<int> adj[MAXN];
int broken[MAXN];
bool isbroken[MAXN];
int fa[MAXN];
int ans[MAXN];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &broken[i]);
        isbroken[broken[i]] = true;
    }

    // 建立最终废墟状态
    int total = n - k; // 当前存活的星球数
    for (int u = 0; u < n; u++)
    {
        if (isbroken[u])
            continue;
        for (int v : adj[u])
        {
            if (isbroken[v])
                continue;
            int rootU = find(u), rootV = find(v);
            if (rootU != rootV)
            {
                fa[rootU] = rootV;
                total--; // 合并成功，连通块减少
            }
        }
    }
    ans[k + 1] = total;

    // 逆向修复
    for (int i = k; i >= 1; i--)
    {
        int u = broken[i];
        isbroken[u] = false;
        total++; // 修复一个点，连通块先加 1
        for (int v : adj[u])
        {
            if (isbroken[v])
                continue;
            int rootU = find(u), rootV = find(v);
            if (rootU != rootV)
            {
                fa[rootU] = rootV;
                total--; // 合并成功，连通块减少
            }
        }
        ans[i] = total;
    }

    // 输出结果
    for (int i = 1; i <= k + 1; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}