int BiTreeDepth(BiTree T)
// 求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int leftdepth, rightdepth;
    if (T && T->lchild == NULL && T->rchild == NULL)
        return 1;
    else if (!T)
        return 0;
    else if (T->lchild || T->rchild)
    {
        if (T->lchild)
            leftdepth = BiTreeDepth(T->lchild);
        if (T->rchild)
            rightdepth = BiTreeDepth(T->rchild);
    }
    int result = 1 + (leftdepth > rightdepth ? leftdepth : rightdepth);
    return result;
    /********** End **********/
}