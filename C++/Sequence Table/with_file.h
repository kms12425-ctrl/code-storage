status SaveList(SqList &L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem == NULL)
        return -1;
    else
    {
        FILE *fp = fopen(FileName, "wb");
        fwrite(&L.length, sizeof(ElemType), 1, fp);
        fwrite(L.elem, sizeof(ElemType), L.length, fp);
        fclose(fp);
        return 1;
    }
    /********** End **********/
}
status LoadList(SqList &L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.length != 0)
        return -1;
    else
    {
        FILE *fp = fopen(FileName, "rb");
        fread(&L.length, sizeof(ElemType), 1, fp);
        L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        fread(L.elem, sizeof(ElemType), L.length, fp);
        fclose(fp);
        return 1;
    }
    /********** End **********/
}