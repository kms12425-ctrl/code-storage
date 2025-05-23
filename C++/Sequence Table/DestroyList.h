status DestroyList(SqList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem == NULL)
        return -1;
    else
    {
        L.elem = 0;
        free(L.elem);
        return 1;
    }
    /********** End **********/
}
