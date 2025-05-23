void MaxSubArray(SqList L)
{
    if (L.elem == NULL || L.length == 0)
    {
        printf("线性表为空\n");
        return;
    }
    int k;
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < L.length; i++)
    {
        count = count + L.elem[i];
        if (count > max_count)
            max_count = count;
        if (count <= 0)
            count = 0;
    }
    printf("最大连续子数组和为:%d", max_count);
    return;
}