status InvertTree(BiTree &T)
{
    if (T)
    {
        BiTree p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
        InvertTree(T->lchild);
        InvertTree(T->rchild);
    }
    return 1;
}