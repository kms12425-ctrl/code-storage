#include <malloc.h>
status ListInsert(SqList &L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (i < 1 || i > L.length + 1)
        return 0;
    else if (L.elem == NULL)
        return -1;
    else
    {
        L.elem = (ElemType *)realloc(L.elem, sizeof(ElemType) * 11);
        int j;
        for (j = L.length - 1; j > i - 2; j--)
        {
            L.elem[j + 1] = L.elem[j];
        }
        L.elem[j + 1] = e;
        L.length++;
        return 1;
    }
    /********** End **********/
}