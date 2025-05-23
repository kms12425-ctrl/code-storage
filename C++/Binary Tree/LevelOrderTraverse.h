status LevelOrderTraverse(BiTree T)
// 按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree queue[100];
    int front = 0, rear = 0;
    if (T)
        queue[rear++] = T;
    BiTree p = T;
    while (front != rear)
    {
        if (p->lchild)
            queue[rear++] = p->lchild;
        if (p->rchild)
            queue[rear++] = p->rchild;
        visit(p);
        p = queue[++front];
    }
    return 1;
    /********** End **********/
}