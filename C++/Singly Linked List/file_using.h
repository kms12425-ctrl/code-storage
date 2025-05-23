status SaveList(LinkList L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if (L == NULL)
        return -1;
    FILE *fp = fopen(FileName, "wb");
    LNode *p = L;
    int count = -1;
    while (p)
    {
        p = p->next;
        count++;
    }
    fwrite(&count, sizeof(ElemType), 1, fp);
    p = L->next;
    for (int i = 0; i < count; i++, p = p->next)
        fwrite(&p->data, sizeof(ElemType), 1, fp);
    fclose(fp);
    return 1;
    /********** End 1 **********/
}

status LoadList(LinkList &L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if (L->next != NULL)
        return -1;
    int count;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *tail = L;
    LinkList p;
    FILE *fp = fopen(FileName, "rb");
    fread(&count, sizeof(ElemType), 1, fp);
    for (int i = 0; i < count; i++, p = p->next)
    {
        p = (LinkList)malloc(sizeof(LNode));
        fread(&p->data, sizeof(ElemType), 1, fp);
        tail->next = p;
        tail = tail->next;
    }
    tail->next = NULL;
    fclose(fp);
    return 1;
    /********** End 2 **********/
}
