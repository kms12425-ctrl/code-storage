status ClearBiTree(BiTree &T)
{
    if (T && (T->lchild || T->rchild))
    {
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    return 1;
}