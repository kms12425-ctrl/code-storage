#include <bits/stdc++.h>
using namespace std;
// 动态规划(行*列)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int s[201][201] = {0}; // 记住之前遍历过的节点的最长距离
int arr[201][201];
int dx[4] = {0, 0, -1, 1}; // 上下左右
int dy[4] = {-1, 1, 0, 0}; // 上下左右
int Row, Col;
int dfs(int hang, int lie)
{
    if (s[hang][lie]) // 记忆化,之前有存过就不用再搜了
        return s[hang][lie];
    s[hang][lie] = 1;
    for (int i = 0; i < 4; i++)
    {
        int new_y = hang + dy[i];
        int new_x = lie + dx[i];
        if (new_y > 0 && new_y <= Row && new_x > 0 && new_x <= Col && arr[new_y][new_x] < arr[hang][lie])
        {
            dfs(new_y, new_x);
            s[hang][lie] = max(s[hang][lie], s[new_y][new_x] + 1);
        }
    }
    return s[hang][lie];
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // 解题代码
    int ans = 0;

    scanf("%d %d", &Row, &Col);
    for (int i = 1; i <= Row; i++)
        for (int j = 1; j <= Col; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= Row; i++)
        for (int j = 1; j <= Col; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    cout << ans;

    return 0;
}
