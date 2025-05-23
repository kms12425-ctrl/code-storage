#include <string.h>
void AddList(LISTS &Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    Lists.elem[Lists.length++].L = (LinkList)malloc(sizeof(LNode));
    Lists.elem[Lists.length - 1].L->next = NULL;
    strcpy(Lists.elem[Lists.length - 1].name, ListName);
    /********** End **********/
}