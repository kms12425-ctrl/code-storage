#include "string.h"
int list_treaverse(BiTree T, KeyType e, TElemType value);
status Assign(BiTree &T, KeyType e, TElemType value)
// 实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTNode *stack[100];
    BiTree p = T;
    int top = 0;
    if (list_treaverse(T, e, value))
        return 0;
    if (T)
        stack[top++] = p;
    while (top)
    {
        p = stack[--top];
        if (p->data.key == e)
        {
            p->data.key = value.key;
            strcpy(p->data.others, value.others);
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
int list_treaverse(BiTree T, KeyType e, TElemType value)
{
    BiTNode *stack[100];
    BiTree p = T;
    int top = 0;
    if (T)
        stack[top++] = p;
    while (top)
    {
        p = stack[--top];
        if (p->data.key == value.key && p->data.key != e)
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
