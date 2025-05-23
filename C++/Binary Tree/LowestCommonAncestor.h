BiTree LowestCommonAncestor(BiTree &T, int p, int q)
{
    if (T == NULL)
        return NULL;
    if (T->data.key == p || T->data.key == q)
        return T;
    BiTree l = LowestCommonAncestor(T->lchild, p, q);
    BiTree r = LowestCommonAncestor(T->rchild, p, q);
    if (l && r)
        return T;
    else if (l && !r)
        return l;
    else if (!l && r)
        return r;
    else
        return NULL;
}