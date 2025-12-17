#include <bits/stdc++.h>
// 拓朴排序+深度搜索
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
// 1e9 + 7
const int MOD = 80112002;
const int MAXN = 5003;
int n, m; // n:生物种类，m：食物链数
vi animal[MAXN];
int in_degree[MAXN];
int out_degree[MAXN];
// bool in_degree_0[MAXN];
// int in_degree_1[MAXN];
int cnt = 0; // 初始入度为0的节点数
// int max_cnt = 1;
// int max_jinwei = 0;
int dp[MAXN];

int dfs(int v)
{
    if (dp[v] != 0)
        return dp[v];
    if (out_degree[v] == 0)
    {
        dp[v] = 1;
        return dp[v];
    }
    for (auto vv : animal[v])
    {
        dp[v] = (dp[v] + dfs(vv)) % MOD;
    }
    return dp[v];
}

int main()
{
    // 解题代码
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int temp_1, temp_2;
        scanf("%d %d", &temp_1, &temp_2);
        animal[temp_1].push_back(temp_2);
        in_degree[temp_2]++; // temp_2的入度加1
        out_degree[temp_1]++;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (in_degree[i] != 0)
    //         continue;
    //     in_degree_0[i] = 1; // 记录入度为0的动物
    //     in_degree_1[cnt++] = i;
    // }

    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] != 0)
            continue;
        cnt = (cnt + dfs(i)) % MOD;
    }
    cout << cnt;
    // for (int i = 0; i < cnt; i++) // 开始统计每个初始入度为0的动物的最长路径
    // {
    //     int max_cnt_temp = 1;
    //     int jinwei = 0;
    //     // memcpy(in_degree_update, in_degree, sizeof(in_degree));
    //     queue<int> S; // 后续操作入度为0的节点
    //     S.push(in_degree_1[i]);
    //     //
    //     while (!S.empty())
    //     {
    //         int u = S.front();
    //         S.pop();
    //         for (auto v : animal[u])
    //         {
    //             if (--in_degree_update[v] == 0 && !in_degree_0[v])
    //             {
    //                 S.push(v);
    //                 max_cnt_temp++;
    //                 if (max_cnt_temp == MOD)
    //                 {
    //                     jinwei++;
    //                     max_cnt_temp = 0;
    //                 }
    //             }
    //         }
    //     }
    //     if (max_jinwei <= jinwei)
    //     {
    //         if (max_cnt_temp > max_cnt)
    //         {
    //             max_cnt = max_cnt_temp;
    //             max_jinwei = jinwei;
    //         }
    //     }
    // }
    // cout << max_cnt;
    return 0;
}