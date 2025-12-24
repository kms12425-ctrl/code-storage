#include <bits/stdc++.h>
using namespace std;
// BFS(n)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 205;
int n, a, b;
int k[MAXN];  // 存储每一层的数字 K[i]
int dp[MAXN]; // 存储到达每一层的最少步数，-1 表示未访问
queue<int> q;

void bfs()
{

    memset(dp, -1, sizeof(dp));

    q.push(a); // 起点入队
    dp[a] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // 如果到达终点
        if (u == b)
        {
            cout << dp[u] << endl;
            return;
        }

        // 往上走
        int up = u + k[u];
        if (up <= n && dp[up] == -1)
        {
            dp[up] = dp[u] + 1;
            q.push(up);
        }

        // 往下走
        int down = u - k[u];
        if (down >= 1 && dp[down] == -1)
        {
            dp[down] = dp[u] + 1;
            q.push(down);
        }
    }
    cout << -1 << endl; // 如果到不了
}

int main()
{
    // 解题代码
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    bfs();

    return 0;
}