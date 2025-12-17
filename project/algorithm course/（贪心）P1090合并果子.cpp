#include <bits/stdc++.h>
using namespace std;
// 贪心算法
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n; // 果子种类
priority_queue<int, vector<int>, greater<int>> que;
int ans = 0; // 消耗总的体力值
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 解题代码
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        que.push(temp);
    }
    while (que.size() != 1)
    {
        int x = que.top();
        que.pop();
        int y = que.top();
        que.pop();
        int sum = x + y;
        ans = ans + sum;
        que.push(sum);
    }
    cout << ans;
    return 0;
}