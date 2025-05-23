#include <string.h>
void AddList(LISTS &Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    SqList L;
    Lists.elem[Lists.length++].L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    Lists.elem[Lists.length - 1].L.length = 0;
    Lists.elem[Lists.length - 1].L.listsize = LIST_INIT_SIZE;
    strcpy(Lists.elem[Lists.length - 1].name, ListName);
    /********** End **********/
}