status GetElem(LinkList L, int i, ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
        if (i < 1 || i > count)
            return 0;
        else
        {
            p = L->next;
            for (int j = 0; j < i - 1; j++)
            {
                p = p->next;
            }
            e = p->data;
            return 1;
        }
    }
    /********** End **********/
}
