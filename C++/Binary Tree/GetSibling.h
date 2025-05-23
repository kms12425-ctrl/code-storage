BiTNode *GetSibling(BiTree T, KeyType e)
// 实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTNode *stack[100];
    BiTree p = T;
    int top = 0;
    if (T)
        stack[top++] = p;
    while (top)
    {
        p = stack[--top];
        if (p->rchild != NULL && p->lchild != NULL && p->lchild->data.key == e)
            return p->rchild;
        if (p->lchild != NULL && p->rchild != NULL && p->rchild->data.key == e)
            return p->lchild;
        if (p->rchild)
            stack[top++] = p->rchild;
        if (p->lchild)
            stack[top++] = p->lchild;
    }
    return NULL;
    /********** End **********/
}