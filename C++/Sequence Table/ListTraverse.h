status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem == NULL)
        return -1;
    if (L.length == 0)
        return 1;
    else
    {
        int i;
        for (i = 0; i < L.length - 1; i++)
            printf("%d ", L.elem[i]);
        printf("%d", L.elem[i]);
        return 1;
    }

    /********** End **********/
}