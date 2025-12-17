#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;
int n, a, b; // a楼到b楼，一共有n层楼
int K[202];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf("%d", &K[i]);

    return 0;
}