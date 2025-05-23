status RemoveNthFromEnd(LinkList &L, int n)
{
    if (L == NULL)
        return -1;
    LinkList p = L->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    if (n > count || n < 0)
        return 0;
    p = L->next;
    for (int i = 1; i < count - n; i++)
    {
        p = p->next;
    }
    LinkList temp = p->next;
    p->next = temp->next;
    free(temp);
    return 1;
}