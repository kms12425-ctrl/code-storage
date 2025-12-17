#include <bits/stdc++.h>
using namespace std;
// 递归，分治
int L, N, M;   // L:起点到终点的距离，N:起点和终点之间的岩石数(一共N+1块石头)，M:组委会至多移走的岩石数。
int D[500000]; // 表示第 i 块岩石与起点的距离

bool judge(int x)
{
    int now = 0;   // 当前所在的石头
    int next = 0;  // 下一个石头
    int count = 0; // 移走石头数
    for (next = 1; next <= N + 1; next++)
    {
        if (D[next] - D[now] >= x)
            now = next;
        else
            count++;
    }
    if (count > M)
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 解题代码
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> D[i];
    }
    D[N + 1] = L;
    int left = 1;
    int right = L;
    int ans = 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (judge(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}