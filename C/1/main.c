#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isprime(int n);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void quickSort(int arr[], int low, int high);
int binary_low(int arr[], int n, int p);
int binary_high(int arr[], int n, int p);
int unique(int *solve, int n);
int compare(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}
int main()
{

    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int medianOfThree(int arr[], int low, int high) // 三数取中法选择 pivot
{
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);
    return mid;
}
int partition(int arr[], int low, int high) // 分区函数
{
    int pivotIndex = medianOfThree(arr, low, high);
    swap(&arr[pivotIndex], &arr[high]);
    int pivot = arr[high];

    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        int pi = partition(arr, low, high);

        // 递归较小部分，迭代较大部分
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
            low = pi + 1; // 迭代右半部分
        }
        else
        {
            quickSort(arr, pi + 1, high);
            high = pi - 1; // 迭代左半部分
        }
    }
}
int binary_low(int arr[], int n, int p) // 二分查找下界（第一个 >= p）
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= p)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int binary_high(int arr[], int n, int p) // 二分查找上界（最后一个 <= p）
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= p)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
int unique(int *solve, int n)
{
    int slow = 0;
    for (int fast = 1; fast < n; fast++)
    {
        if (solve[fast] != solve[slow])
            solve[++slow] = solve[fast];
    }
    return slow + 1;
}
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