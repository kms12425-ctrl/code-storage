#include <bits/stdc++.h>
using namespace std;
// 线段树，扫描线，离散化(N*L)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int height[5003] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 解题代码
    int cnt = 0;
    int a, h, b;
    int max_b = 0;
    while (scanf("%d%d%d", &a, &h, &b) != EOF)
    {
        for (int i = a; i < b; i++)
        {
            height[i] = max(h, height[i]);
        }
        cnt++;
        max_b = max_b > b ? max_b : b;
    }
    for (int i = 1; i <= max_b; i++)
    {
        if (height[i] != height[i - 1])
        {
            printf("%d %d ", i, height[i]);
        }
    }
    return 0;
}