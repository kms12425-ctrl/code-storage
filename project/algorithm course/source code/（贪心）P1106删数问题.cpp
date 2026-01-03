#include <bits/stdc++.h>
using namespace std;
// 贪心算法(k*n)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;

string n;
int k;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 解题代码
    cin >> n >> k;

    while (k > 0)
    {
        int len = n.length();
        int i = 0;

        // 寻找第一个比后面数字大的位置（峰值）
        while (i < len - 1 && n[i] <= n[i + 1])
            i++;

        n.erase(i, 1); // 删掉那个位置
        k--;
    }

    // 处理前导零
    while (n.length() > 1 && n[0] == '0')
    {
        n.erase(0, 1);
    }

    cout << n;
    return 0;
}