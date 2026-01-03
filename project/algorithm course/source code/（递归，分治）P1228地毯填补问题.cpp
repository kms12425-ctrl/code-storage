#include <bits/stdc++.h>
using namespace std;
// 分治，递归(棋盘面积)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;
int k;
int x, y;
void dp(int x, int y, int hang, int lie, int len)
{
    if (len == 1)
        return;
    if (x <= hang + len / 2 - 1 && y <= lie + len / 2 - 1) // 左上
    {
        printf("%d %d %d\n", hang + len / 2, lie + len / 2, 1);

        dp(x, y, hang, lie, len / 2);
        dp(hang + len / 2 - 1, lie + len / 2, hang, lie + len / 2, len / 2);
        dp(hang + len / 2, lie + len / 2 - 1, hang + len / 2, lie, len / 2);
        dp(hang + len / 2, lie + len / 2, hang + len / 2, lie + len / 2, len / 2);
    }
    else if (x <= hang + len / 2 - 1 && y > lie + len / 2 - 1) // 右上
    {
        printf("%d %d %d\n", hang + len / 2, lie + len / 2 - 1, 2);

        dp(hang + len / 2 - 1, lie + len / 2 - 1, hang, lie, len / 2);
        dp(x, y, hang, lie + len / 2, len / 2);
        dp(hang + len / 2, lie + len / 2 - 1, hang + len / 2, lie, len / 2);
        dp(hang + len / 2, lie + len / 2, hang + len / 2, lie + len / 2, len / 2);
    }
    else if (x > hang + len / 2 - 1 && y <= lie + len / 2 - 1) // 左下
    {
        printf("%d %d %d\n", hang + len / 2 - 1, lie + len / 2, 3);

        dp(hang + len / 2 - 1, lie + len / 2 - 1, hang, lie, len / 2);
        dp(hang + len / 2 - 1, lie + len / 2, hang, lie + len / 2, len / 2);
        dp(x, y, hang + len / 2, lie, len / 2);
        dp(hang + len / 2, lie + len / 2, hang + len / 2, lie + len / 2, len / 2);
    }
    else // 右下
    {
        printf("%d %d %d\n", hang + len / 2 - 1, lie + len / 2 - 1, 4);

        dp(hang + len / 2 - 1, lie + len / 2 - 1, hang, lie, len / 2);
        dp(hang + len / 2 - 1, lie + len / 2, hang, lie + len / 2, len / 2);
        dp(hang + len / 2, lie + len / 2 - 1, hang + len / 2, lie, len / 2);
        dp(x, y, hang + len / 2, lie + len / 2, len / 2);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    cin >> k;
    scanf("%d %d", &x, &y);
    int len = 1 << k;
    dp(x, y, 1, 1, len);
    return 0;
}