#include <string.h>
status RemoveList(LISTS &Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < Lists.length; i++)
    {
        if (strcmp(Lists.elem[i].name, ListName) == 0)
        {
            DestroyGraph(Lists.elem[i].T);
            strcpy(Lists.elem[i].name, "0");
            return 1;
        }
    }
    return 0;
    /********** End **********/
}