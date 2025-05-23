void swap(int *a, int *b);
int medianOfThree(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high); // 快速排序

int sortList(LinkList L)
{
    if (L == NULL || L->next == NULL)
    {
        printf("线性表为空\n");
        return 0;
    }
    LinkList p = L->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    int temp_array[count];
    p = L->next;
    for (int i = 0; i < count; i++, p = p->next)
    {
        temp_array[i] = p->data;
    }
    quickSort(temp_array, 0, count - 1);
    p = L->next;
    for (int i = 0; i < count; p = p->next, i++)
    {
        p->data = temp_array[i];
    }
    return 1;
}

void swap(int *a, int *b) // 交换数
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int medianOfThree(int arr[], int low, int high) // 三个数取中间法来选择 pivot
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
void quickSort(int arr[], int low, int high) // 快排
{
    while (low < high)
    {
        int pi = partition(arr, low, high);
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        }
        else
        {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}