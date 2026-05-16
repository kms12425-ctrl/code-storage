/*
2D单通道空洞卷积底层实现
步骤：
1.输入特征图padding填充
2.计算有效卷积核尺寸与输出特征图尺寸
3.滑动窗口遍历与空洞卷积核心计算
4.输出结果

输入：
4 6
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
3
1 0 -1 1 0 -1 1 0 -1
1
1
2
输出：
-32 -8 -8 30
-20 -8 -8 18


输入：
3 3
1 2 3 4 5 6 7 8 9
3
1 0 -1 1 0 -1 1 0 -1
1
0
1
输出：
-6

输入：
5 5
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
3
1 0 1 0 1 0 1 0 1
1
0
2
输出：
5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<vector<ll>> a(h, vector<ll>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    int k;
    cin >> k;

    vector<vector<ll>> kernel(k, vector<ll>(k));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> kernel[i][j];
        }
    }

    int stride, padding, dilation;
    cin >> stride >> padding >> dilation;

    int ph = h + 2 * padding;
    int pw = w + 2 * padding;

    vector<vector<ll>> padded(ph, vector<ll>(pw, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            padded[i + padding][j + padding] = a[i][j];
        }
    }

    int effective_k = (k - 1) * dilation + 1;
    int out_h = (ph - effective_k) / stride + 1;
    int out_w = (pw - effective_k) / stride + 1;

    vector<vector<ll>> ans(out_h, vector<ll>(out_w, 0));

    for (int i = 0; i < out_h; i++)
    {
        for (int j = 0; j < out_w; j++)
        {
            ll sum = 0;

            int start_x = i * stride;
            int start_y = j * stride;

            for (int u = 0; u < k; u++)
            {
                for (int v = 0; v < k; v++)
                {
                    int x = start_x + u * dilation;
                    int y = start_y + v * dilation;
                    sum += padded[x][y] * kernel[u][v];
                }
            }

            ans[i][j] = sum;
        }
    }

    for (int i = 0; i < out_h; i++)
    {
        for (int j = 0; j < out_w; j++)
        {
            if (j)
                cout << ' ';
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}