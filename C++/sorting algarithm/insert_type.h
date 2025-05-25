void insertsort(SqList &L)
{
    int temp;
    if (L.length == 1)
        return;
    for (int i = 1; i < L.length; i++)
    {
        temp = L.elem[i];
        int j;
        for (j = i - 1; L.elem[j] > temp && j >= 0; j--)
            L.elem[j + 1] = L.elem[j];
        L.elem[j + 1] = temp;
    }
    return;
}
void Binsersort(SqList &L)
{
    if (L.length == 1)
        return;
    int temp;
    for (int i = 1; i < L.length; i++)
    {
        temp = L.elem[i];
        int mid, high = i - 1, low = 0;
        while (high >= low)
        {
            mid = (high + low) / 2;
            if (L.elem[mid] > temp)
                high = mid - 1;
            else if (L.elem[mid] <= temp)
                low = mid + 1;
        }
        for (int j = i - 1; j > high; j--)
        {
            L.elem[j + 1] = L.elem[j];
        }
        L.elem[high + 1] = temp;
    }
    return;
}
void shell_sort(SqList &L)
{
}