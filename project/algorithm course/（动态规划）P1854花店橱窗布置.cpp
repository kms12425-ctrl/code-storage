#include <bits/stdc++.h>
using namespace std;
// 动态规划
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;

int arr[105][105];
int sum = 0;
int put[105];
int dp[105][105];
pii pre[105][105];
int main()
{
    // 解题代码
    int F, V;
    scanf("%d %d", &F, &V);
    for (int i = 1; i <= F; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i <= F; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = -INF;
        }
    }

    for (int i = 0; i <= V; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= F; i++)
    {
        for (int j = i; j <= V; j++)
        {                                           // dp(i,j)=max(dp(i-1,j-1)+arr(i,j)+dp(i,j-1))
            int dp1 = dp[i - 1][j - 1] + arr[i][j]; // 第i个花刚好放在第j个花瓶
            int dp2 = dp[i][j - 1];                 // 第i个花不放在第j个花瓶，而是放在了j-1个花瓶中
            if (dp1 >= dp2)
            {
                dp[i][j] = dp1;
                pre[i][j] = {i - 1, j - 1};
            }
            else
            {
                dp[i][j] = dp2;
                pre[i][j] = {i, j - 1};
            }
        }
    }
    cout << dp[F][V] << endl;

    // 回溯
    for (int i = F, j = V; i > 0;)
    {
        int pre_i = pre[i][j].first;
        int pre_j = pre[i][j].second;
        if (pre_i == i - 1)
        {
            put[i] = j;
        }
        i = pre_i;
        j = pre_j;
    }

    for (int i = 1; i <= F; i++)
        cout << put[i] << " ";
    return 0;
}