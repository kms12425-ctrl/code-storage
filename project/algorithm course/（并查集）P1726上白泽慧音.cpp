#include <bits/stdc++.h>
using namespace std;
// 并查集
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1000005;
int n, m;
int liantongfenliang;
vi adj[MAXN];
int dfn[MAXN], low[MAXN], timer;
bool instack[MAXN];
stack<int> st;
vi current_scc, best_scc;
void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    st.push(u);
    instack[u] = 1;
    for (int v : adj[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        current_scc.clear();
        while (true)
        {
            int node = st.top();
            st.pop();
            instack[node] = 0;
            current_scc.push_back(node);
            if (node == u)
                break;
        }
        sort(current_scc.begin(), current_scc.end());
        // 比较并更新最优解
        if (current_scc.size() > best_scc.size())
        {
            best_scc = current_scc;
        }
        else if (current_scc.size() == best_scc.size())
        {
            if (current_scc < best_scc)
                best_scc = current_scc;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        adj[u].push_back(v);
        if (t == 2)
            adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    printf("%d\n", (int)best_scc.size());
    for (int i = 0; i < best_scc.size(); i++)
        printf("%d ", best_scc[i]);
    return 0;
}