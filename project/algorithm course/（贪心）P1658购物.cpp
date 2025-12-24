#include <bits/stdc++.h>
using namespace std;
// 贪心算法(nlgn)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1005;
int X, N; // N:面值，X:要能组合出 1 到 X 之间的任意值
int pocket[11];
int cnt[11];
int sum;
int main()
{
    // 解题代码
    scanf("%d %d", &X, &N);
    for (int i = 1; i <= N; i++)
    {
        cin >> pocket[i];
        cnt[i] = 1;
    }
    sort(pocket + 1, pocket + N + 1);
    // pocket[N+1]
    if (pocket[1] != 1)
    {
        printf("-1");
        return 0;
    }
    sum++;
    for (int i = 1; i < X;)
    {
        for (int j = N; j >= 1; j--)
        {
            if (pocket[j] <= i + 1) // 从右往左找第一个<=i+1的面值
            {
                sum++;
                i = i + pocket[j];
                break;
            }
        }
    }
    printf("%d", sum);
    return 0;
}