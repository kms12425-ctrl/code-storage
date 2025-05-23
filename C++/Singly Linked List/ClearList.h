
status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
        return -1;
    else
    {
        LinkList temp_1 = L->next;
        LinkList temp_2;
        while (temp_1 != NULL)
        {
            temp_2 = temp_1;
            temp_1 = temp_1->next;
            free(temp_2);
        }
        L->next = NULL;
        return 1;
    }
    /********** End **********/
}
