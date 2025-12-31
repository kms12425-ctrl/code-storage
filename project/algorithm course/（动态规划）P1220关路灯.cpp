#include <bits/stdc++.h>
using namespace std;
// 动态规划
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 105;
int n, c;
int pos[MAXN], w[MAXN], sum[MAXN];
int dp[MAXN][MAXN][2];

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &pos[i], &w[i]);
        sum[i] = sum[i - 1] + w[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[c][c][0] = dp[c][c][1] = 0;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {                        // 左端点
            int j = i + len - 1; // 右端点

            // 转移到 dp[i][j][0] (停在左端点 i)
            dp[i][j][0] = min(
                dp[i + 1][j][0] + (pos[i + 1] - pos[i]) * (sum[i] + sum[n] - sum[j]),
                dp[i + 1][j][1] + (pos[j] - pos[i]) * (sum[i] + sum[n] - sum[j]));

            // 转移到 dp[i][j][1] (停在右端点 j)
            dp[i][j][1] = min(
                dp[i][j - 1][0] + (pos[j] - pos[i]) * (sum[i - 1] + sum[n] - sum[j - 1]),
                dp[i][j - 1][1] + (pos[j] - pos[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
        }
    }
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));

    return 0;
}