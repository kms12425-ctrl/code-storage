void delete_right_node(BiTree &q, BiTree &p, KeyType e);
void delete_left_node(BiTree &q, BiTree &p, KeyType e);
status DeleteNode(BiTree &T, KeyType e)
// 删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTNode *stack[100];
    BiTree p = T;
    if (p->data.key == e)
    {
        if (p->lchild == NULL && p->rchild == NULL)
            free(p);
        else if (p->lchild == NULL && p->rchild != NULL)
        {
            T = p->rchild;
            free(p);
        }
        else if (p->rchild == NULL && p->lchild != NULL)
        {
            T = p->lchild;
            free(p);
        }
        else if (p->lchild != NULL && p->rchild != NULL)
        {
            T = T->lchild;
            BiTree temp = p->rchild;
            BiTNode *temP_2 = p->lchild;
            free(p);
            while (temP_2->rchild)
            {
                temP_2 = temP_2->rchild;
            }
            temP_2->rchild = temp;
        }
        return 1;
    }
    int top = 0;
    if (T)
        stack[top++] = p;
    while (top)
    {
        p = stack[--top];
        if (p->lchild != NULL && p->lchild->data.key == e)
        {
            delete_left_node(p, p->lchild, e);
            return 1;
        }
        if (p->rchild != NULL && p->rchild->data.key == e)
        {
            delete_right_node(p, p->rchild, e);
            return 1;
        }
        if (p->rchild)
        {
            stack[top++] = p->rchild;
        }
        if (p->lchild)
            stack[top++] = p->lchild;
    }
    return 0;
    /********** End **********/
}
void delete_left_node(BiTree &q, BiTree &p, KeyType e)
{
    if (p->lchild == NULL && p->rchild == NULL)
    {
        free(p);
        q->lchild = NULL;
    }
    else if (p->lchild == NULL && p->rchild != NULL)
    {
        BiTree temp = p;
        q->lchild = p->rchild;
        free(temp);
    }
    else if (p->rchild == NULL && p->lchild != NULL)
    {
        BiTree temp = p;
        q->lchild = p->lchild;
        free(temp);
    }
    else if (p->rchild != NULL && p->lchild != NULL)
    {
        BiTree temp_2 = p->rchild;
        BiTree temp_3 = p;
        q->lchild = p->lchild;
        free(temp_3);
        BiTree temp_1 = q->lchild;
        while (temp_1->rchild)
        {
            temp_1 = temp_1->rchild;
        }
        temp_1->rchild = temp_2;
    }
    return;
}
void delete_right_node(BiTree &q, BiTree &p, KeyType e)
{
    if (p->lchild == NULL && p->rchild == NULL)
    {
        free(p);
        q->rchild = NULL;
    }
    else if (p->lchild == NULL && p->rchild != NULL)
    {
        BiTree temp = p;
        q->rchild = p->rchild;
        free(temp);
    }
    else if (p->rchild == NULL && p->lchild != NULL)
    {
        BiTree temp = p;
        q->rchild = p->lchild;
        free(temp);
    }
    else if (p->rchild != NULL && p->lchild != NULL)
    {
        BiTree temp_2 = p->rchild;
        BiTree temp_3 = p;
        q->rchild = p->lchild;
        free(temp_3);
        BiTree temp_1 = q->rchild;
        while (temp_1->rchild)
        {
            temp_1 = temp_1->rchild;
        }
        temp_1->rchild = temp_2;
    }
}