status ListDelete(LinkList &L, int i, ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
        return -1;
    LNode *p = L;
    LNode *q = L;
    int count = -1;
    while (p)
    {
        p = p->next;
        count++;
    }
    if (i <= 0 || i > count)
        return 0;
    p = L;
    for (int j = 0; j < i - 1; j++)
        p = p->next;
    e = p->next->data;
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
    /********** End **********/
}
