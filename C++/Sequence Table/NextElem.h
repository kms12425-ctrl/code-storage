status NextElem(SqList L, ElemType e, ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int temp;
    if (L.elem == NULL)
        return -1;
    else
    {
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e && i < L.length - 1)
            {
                next = L.elem[i + 1];
                return 1;
            }
        }
        return 0;
    }
    /********** End **********/
}
