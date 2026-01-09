#include <bits/stdc++.h>
using namespace std;
// 区间动态规划 O(n^3)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;
int dp[MAXN][MAXN];
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码

    if (!(cin >> s))
        return 0;
    int n = s.length();

    // 初始化 DP 数组为最大值
    memset(dp, 0x3f, sizeof(dp));

    // 基础情况：长度为 1 的区间
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    // 枚举区间长度
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            if (s[i] == s[j])
            {
                // 两端颜色相同
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }
            else
            {
                // 两端颜色不同，枚举分割点
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}