int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
        return -1;
    else
    {
        LinkList p = L->next;
        int count = 0;
        while (p != NULL)
        {
            p = p->next;
            count++;
        }
        return count;
    }
    /********** End **********/
}
