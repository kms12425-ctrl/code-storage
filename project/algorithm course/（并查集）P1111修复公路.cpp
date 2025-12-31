#include <bits/stdc++.h>
using namespace std;
// 并查集
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1000005;

int n, m;
int liantongfenliang;
struct request
{
    int x, y, t; // 这条公路连着 x,y 两个村庄，在时间 t 时能修复完成这条公路
    bool operator<(request &other)
    {
        return t < other.t;
    }
} req[1000003];
int fa[MAXN];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &req[i].x, &req[i].y, &req[i].t);
    }
    sort(req + 1, req + m + 1);
    int liantongfenliang = n;
    int ans = -1;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int rootx = find(req[i].x);
        int rooty = find(req[i].y);
        if (rootx != rooty)
        {
            liantongfenliang--;
            fa[rootx] = rooty;
        }
        if (liantongfenliang == 1)
        {
            printf("%d", req[i].t);
            return 0;
        }
    }
    printf("%d", ans);
    return 0;
}