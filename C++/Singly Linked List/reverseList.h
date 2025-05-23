status reverseList(LinkList &L)
{
    if (L == NULL)
        return -1;
    if (L->next->next == NULL)
        return 0;
    LinkList pre = L->next->next, pro = L->next, temp = pro->next;
    pro->next = NULL;
    while (pre->next)
    {
        temp = pre;
        pre = pre->next;
        temp->next = pro;
        pro = temp;
    }
    temp = pre;
    temp->next = pro;
    pro = temp;
    L->next = pre;
    return 1;
}