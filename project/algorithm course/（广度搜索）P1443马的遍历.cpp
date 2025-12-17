#include <bits/stdc++.h>
using namespace std;
// BFS,广度搜索
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;
int n, m;
int x, y;
int da[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // 行的8个方向
int db[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // 列的8个方向
int qipan[MAXN][MAXN];
void bfs(int a, int b) // a：行，b:列
{
    queue<pii> que;
    que.push({a, b});

    while (!que.empty())
    {
        auto [a, b] = que.front();
        que.pop();

        for (int i = 0; i < 8; i++)
        {
            int new_a = a + da[i], new_b = b + db[i];
            if (new_a < 1 || new_b < 1 || new_a > n || new_b > m)
                continue;
            if (qipan[new_a][new_b] != -1)
                continue;
            qipan[new_a][new_b] = qipan[a][b] + 1;
            que.push({new_a, new_b});
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            qipan[i][j] = -1;
    //
    qipan[x][y] = 0;
    bfs(x, y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%d ", qipan[i][j]);
        printf("\n");
    }
    return 0;
}