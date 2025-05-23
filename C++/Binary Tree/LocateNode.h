BiTNode *LocateNode(BiTree T, KeyType e)
// 查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTNode *stack[100];
    BiTNode *p = T;
    int top = 0;
    if (T)
        stack[top++] = T;
    while (top)
    {
        p = stack[--top];
        if (p->data.key == e)
            return p;
        if (p->rchild != NULL)
        {
            stack[top++] = p->rchild;
        }
        if (p->lchild != NULL)
        {
            stack[top++] = p->lchild;
        }
    }
    return NULL;
    /********** End **********/
}