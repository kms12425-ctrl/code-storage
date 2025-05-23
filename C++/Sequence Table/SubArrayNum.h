void SubArrayNum(SqList L)
{
    if (L.elem == NULL || L.length == 0)
    {
        printf("线性表为空\n");
        return;
    }
    int k;
    printf("请输入你想求和的连续子数组k\n");
    int result = 0;
    scanf("%d", &k);

    for (int i = 0; i < L.length; i++)
    {
        int count = 0;
        for (int j = i; j < L.length; j++)
        {
            count = count + L.elem[j];
            if (count == k)
            {
                result++;
            }
        }
    }

    printf("有%d个这样的子数组", result);
    return;
}