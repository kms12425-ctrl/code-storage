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
            LinkList temp_1 = Lists.elem[i].L->next;
            LinkList temp_2;
            while (temp_1 != NULL)
            {
                temp_2 = temp_1;
                temp_1 = temp_1->next;
                free(temp_2);
            }
            free(Lists.elem[i].L);
            Lists.elem[i].L = NULL;
            Lists.elem[i].name = 0;
            return 1;
        }
    }
    return 0;
    /********** End **********/
}