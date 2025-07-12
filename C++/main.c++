#include <malloc.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bitset>

// int isprime(int n);
// int partition(int arr[], int low, int high);
// void swap(int *a, int *b);
// void quickSort(int arr[], int low, int high);
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
int main()
{
    int;
    return 0;
}

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// {
//     int mid = low + (high - low) / 2;
//     if (arr[low] > arr[mid])
//         swap(&arr[low], &arr[mid]);
//     if (arr[low] > arr[high])
//         swap(&arr[low], &arr[high]);
//     if (arr[mid] > arr[high])
//         swap(&arr[mid], &arr[high]);
//     return mid;
// }
// int partition(int arr[], int low, int high) // 分区函数
// {
//     int pivotIndex = medianOfThree(arr, low, high);
//     swap(&arr[pivotIndex], &arr[high]);
//     int pivot = arr[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return i + 1;
// }
// void quickSort(int arr[], int low, int high)
// {
//     while (low < high)
//     {
//         int pi = partition(arr, low, high);

//         // 递归较小部分，迭代较大部分
//         if (pi - low < high - pi)
//         {
//             quickSort(arr, low, pi - 1);
//             low = pi + 1; // 迭代右半部分
//         }
//         else
//         {
//             quickSort(arr, pi + 1, high);
//             high = pi - 1; // 迭代左半部分
//         }
//     }
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
int isprime(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// #include <stdio.h>
// #include <stdlib.h>
// int time = 0, tem_sum = 0, sum[4] = {0, 0, 0, 0};
// int current_sum = 0;
// #define mi(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))

// void least_time(int *sub, int sum, int start, int n, int k, int count)
// {
//     if (count == k) // 找到与总时间之和的一半最接近的时间之和，即为最短时间
//     {
//         if (mi(tem_sum, sum / 2) > mi(current_sum, sum / 2) && (double)current_sum >= (double)sum / 2)
//             tem_sum = current_sum;
//         return;
//     }
//     for (int i = start; i < n; i++) // 遍历所有（n个时间中的k个）时间之和，也就是遍历C(n,k)种组合
//     {
//         current_sum += sub[i];
//         least_time(sub, sum, i + 1, n, k, count + 1);
//         current_sum -= sub[i];
//     }
// }

// int main()
// {
//     int s1, s2, s3, s4;
//     scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
//     int A[s1], B[s2], C[s3], D[s4], num[] = {s1, s2, s3, s4};
//     int *sub[] = {&A[0], &B[0], &C[0], &D[0]};
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < num[i]; j++)
//         {
//             scanf("%d", (sub[i] + j));
//             sum[i] += *(sub[i] + j);
//         }
//         tem_sum = sum[i];                         // 求出该任务所有时间之和
//         for (int k = 1; k <= 1 + num[i] / 2; k++) // 从1开始找到C(n,k)中时间组合中的最接近一半的时间
//         {
//             if (tem_sum == sum[i] / 2) // 如果在中途发现有组合相加可以直接等于一半时间，就直接输出
//                 break;
//             least_time(sub[i], sum[i], 0, num[i], k, 0);
//         }
//         time += tem_sum; // 每门科目的最小时间相加
//     }
//     printf("%d", time);
//     return 0;
// }