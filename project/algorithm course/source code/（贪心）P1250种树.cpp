#include <bits/stdc++.h>
using namespace std;
// 贪心算法
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 30004;
struct request
{
    int b, e, t; // 第 i 个居民想在 bi 和 ei 之间种至少 ti 棵树
    bool operator<(request &other)
    {
        return e < other.e;
    }
} req[5003];
int n; // 区域个数
int h; // 房子数量
bool is_planted[MAXN] = {0};
int ans = 0;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    scanf("%d", &n);
    scanf("%d", &h);
    for (int i = 1; i <= h; i++)
    {
        scanf("%d %d %d", &req[i].b, &req[i].e, &req[i].t);
    }
    sort(req + 1, req + h + 1);
    for (int i = 1; i <= h; i++)
    {
        int k = 0;
        for (int j = req[i].b; j <= req[i].e; j++)
            if (is_planted[j])
                k++;
        if (k < req[i].t)
        {
            for (int j = req[i].e; k < req[i].t; j--)
            {
                if (!is_planted[j])
                {
                    k++;
                    ans++;
                    is_planted[j] = 1;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}