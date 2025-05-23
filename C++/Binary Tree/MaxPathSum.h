void travers(BiTree &p, int &result, int &temp_result);
void MaxPathSum(BiTree &T, int &result)
{
    BiTree p = T;
    int temp_result = 0;
    travers(p, result, temp_result);
    return;
}
void travers(BiTree &p, int &result, int &temp_result)
{
    temp_result = temp_result + p->data.key;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        result = temp_result > result ? temp_result : result;
    }
    if (p->lchild)
    {
        travers(p->lchild, result, temp_result);
        temp_result = temp_result - p->lchild->data.key;
    }
    if (p->rchild)
    {
        travers(p->rchild, result, temp_result);
        temp_result = temp_result - p->rchild->data.key;
    }
    return;
}