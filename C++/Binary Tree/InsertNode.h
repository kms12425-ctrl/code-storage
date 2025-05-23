int list_treaverse(BiTree T, TElemType value);
status InsertNode(BiTree &T, KeyType e, int LR, TElemType c)
// 插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (list_treaverse(T, c))
        return 0;
    BiTree p;
    p = new BiTNode;
    p->data = c;
    if (LR == -1)
    {
        p->rchild = T;
        p->lchild = NULL;
        T = p;
        return 1;
    }
    BiTNode *stack[100];
    BiTree q = T;
    int top = 0;
    if (T)
        stack[top++] = q;
    while (top)
    {
        q = stack[--top];
        if (q->data.key == e)
        {
            if (LR == 0)
            {
                BiTree temp = q->lchild;
                q->lchild = p;
                p->rchild = temp;
                p->lchild = NULL;
            }
            else if (LR == 1)
            {
                BiTree temp = q->rchild;
                q->rchild = p;
                p->rchild = temp;
                p->lchild = NULL;
            }
            return 1;
        }
        if (q->rchild)
        {
            stack[top++] = q->rchild;
        }
        if (q->lchild)
            stack[top++] = q->lchild;
    }
    return 0;
    /********** End **********/
}
int list_treaverse(BiTree T, TElemType value)
{
    BiTNode *stack[100];
    BiTree p = T;
    int top = 0;
    if (T)
        stack[top++] = p;
    while (top)
    {
        p = stack[--top];
        if (p->data.key == value.key)
            return 1;
        if (p->rchild)
        {
            stack[top++] = p->rchild;
        }
        if (p->lchild)
            stack[top++] = p->lchild;
    }
    return 0;
}