#include <bits/stdc++.h>
using namespace std;
// ST表，RMQ，倍增法
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 100004;

int m, n;
int zhangmu[MAXN];
int st[MAXN][20];
int Log[MAXN] = {0};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%d", &zhangmu[i]);
    // 预处理
    for (int i = 2; i <= m; i++)
    {
        Log[i] = Log[i / 2] + 1;
    }
    for (int i = 1; i <= m; i++)
        st[i][0] = zhangmu[i];
    for (int j = 1; j <= Log[m]; j++)
        for (int i = 1; i + (1 << j) - 1 <= m; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    // 求每个问题区间最小值
    for (int i = 1; i <= n; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        int k = Log[right - left + 1];
        printf("%d ", min(st[left][k], st[right - (1 << k) + 1][k]));
    }
    return 0;
}