// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cctype>
// #include <vector>
// #include <cmath>
// #include <queue>
// #include <map>
// #include <stack>
// #include <unordered_set>
// #include <deque>
// #include <array>
// #include <list>
// #include <unordered_map>
// #include <windows.h>
// using namespace std;
// void dp(int n, vector<int> &dp);
// int isprime(int n);
// void swap(int *a, int *b);
// int binary_low(int arr[], int n, int p);
// int binary_high(int arr[], int n, int p);
// int unique(int *solve, int n);
// int compare(const void *a, const void *b)
// {
//     int arg1 = *(const int *)a;
//     int arg2 = *(const int *)b;
//     if (arg1 < arg2)
//         return -1;
//     if (arg1 > arg2)
//         return 1;
//     return 0;
// }
// int main()
// {
//     SetConsoleOutputCP(65001); // UTF-8 代码页
//     SetConsoleCP(65001);
//     printf("你好");
//     int n;
//     cin >> n;
//     vector<int> dp_arr;
//     dp_arr.push_back(1);
//     for (int i = 1; i <= n; i++)
//     {
//         dp(n, dp_arr);
//     }
//     cout << dp_arr[n];
//     return 0;
// }
// void dp(int n, vector<int> &dp)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         if (i == 1)
//             return;
//         else
//         {
//             return;
//         }
//     }
// }
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int binary_low(int arr[], int n, int p) // 二分查找下界（第一个 >= p）
// {
//     int low = 0, high = n - 1;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr[mid] >= p)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return low;
// }
// int binary_high(int arr[], int n, int p) // 二分查找上界（最后一个 <= p）
// {
//     int low = 0, high = n - 1;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr[mid] <= p)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return high;
// }
// int unique(int *solve, int n)
// {
//     int slow = 0;
//     for (int fast = 1; fast < n; fast++)
//     {
//         if (solve[fast] != solve[slow])
//             solve[++slow] = solve[fast];
//     }
//     return slow + 1;
// }
// int isprime(int n)
// {
//     if (n == 1 || n == 2)
//     {
//         return 1;
//     }
//     for (int i = 2; i <= n / 2; i++)
//     {
//         if (n % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }