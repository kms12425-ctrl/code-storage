#include "def.h"
#include "with_file.h"
#include "RemoveList.h"
#include "PriorElem.h"
#include "NextElem.h"
#include "LocateList.h"
#include "LocateElem.h"
#include "ListTraverse.h"
#include "ListLength.h"
#include "ListInsert.h"
#include "ListEmpty.h"
#include "ListDelete.h"
#include "GetElem.h"
#include "DestroyList.h"
#include "ClearList.h"
#include "AddList.h"
#include "sortList.h"
#include "SubArrayNum.h"
#include "MaxSubArray.h"

int main()
{
    LISTS Lists;
    Lists.length = 0;
    int op = 1;
    int list_num = 1;
    int count = 0;
    while (op)
    {
        char name_temp[30];
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        if (count > 1)
        {
            printf("需要查看有什么表吗？,需要请输入1,不需要输入其他数字\n");
            scanf("%d", &op);
            if (op == 1)
            {
                printf("创建的线性表有：\n");
                for (int temp_2 = 0; temp_2 < Lists.length; temp_2++)
                {
                    printf("%s\n", Lists.elem[temp_2].name);
                }
            }
            bool flag = 1;
            printf("请问你想对哪个线性表进行操作？\n");
            do
            {
                scanf("%s", name_temp);
                if (!(list_num = LocateList(Lists, name_temp)))
                {
                    flag = 0;
                    printf("找不到对应的线性表,请重新输入\n");
                }
                else
                    flag = 1;
            } while (flag != OK);
        }
        printf("    	  1. InitList       11. ListDelete\n");
        printf("    	  2. DestroyList    12. ListTrabverse\n");
        printf("    	  3. ClearList      13. file_using\n");
        printf("    	  4. ListEmpty      14. AddList\n");
        printf("    	  5. ListLength     15. RemoveList\n");
        printf("    	  6. GetElem        16. LocateList\n");
        printf("          7. LocateElem     17. SortList\n");
        printf("          8. PriorElem      18. SubArrayNum\n");
        printf("          9. NextElem       19. MaxSubArray\n");
        printf("          10. ListInsert    20. ShowAllList\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~16]:");
        scanf("%d", &op);
        switch (op)
        {
        case 1: // 线性表的创建
            if (Lists.length > 0)
            {
                printf("已初始化线性表\n");
                getchar();
                getchar();
                break;
            }
            printf("请输入你想创建的线性表名称\n");
            char firstname[30];
            scanf("%s", firstname);
            AddList(Lists, firstname);
            printf("请输入元素,以0结束\n");
            int i;
            scanf("%d", &i);
            while (i)
            {
                ListInsert(Lists.elem[Lists.length - 1].L, Lists.elem[Lists.length - 1].L.length + 1, i);
                scanf("%d", &i);
            }
            if (!ListTraverse(Lists.elem[Lists.length - 1].L))
                printf("线性表是空表！\n");
            else
                count++;
            getchar();
            getchar();
            break;
        case 2: // 销毁线性表
            if (DestroyList(Lists.elem[list_num - 1].L) == OK)
                printf("销毁线性表成功\n");
            else
                printf("线性表已空\n");
            getchar();
            getchar();
            break;
        case 3: // 清空线性表
            if (ClearList(Lists.elem[list_num - 1].L) == OK)
                printf("清空线性表成功\n");
            else
                printf("线性表已空\n");
            getchar();
            getchar();
            break;
        case 4: // 线性表判空
            if (ListEmpty(Lists.elem[list_num - 1].L) == OK)
                printf("线性表为空\n");
            else if (ListEmpty(Lists.elem[list_num - 1].L) == 0)
                printf("线性表不为空\n");
            else
                printf("线性表不存在\n");
            getchar();
            getchar();
            break;
        case 5: // 线性表长度
            if (ListLength(Lists.elem[list_num - 1].L) > 0)
                printf("线性表长度为%d\n", ListLength(Lists.elem[list_num - 1].L));
            else
                printf("线性表为空\n");
            getchar();
            getchar();
            break;
        case 6: // 获取元素
            int temp, m;
            printf("您想获取第几个元素？\n");
            scanf("%d", &i);
            if (GetElem(Lists.elem[list_num - 1].L, m, temp) == OK)
                printf("第%d个元素是:%d\n", m, temp);
            else
                printf("i的范围不正确\n");
            getchar();
            getchar();
            break;
        case 7: // 查找元素
            printf("您想查找哪个元素？\n");
            scanf("%d", &i);
            if ((temp = LocateElem(Lists.elem[list_num - 1].L, i)) > 0)
            {
                printf("元素%d在第%d位\n", i, temp);
            }
            else
                printf("不存在该元素\n");
            getchar();
            getchar();
            break;
        case 8: // 获取前驱元素
            int pre;
            printf("您想查找哪个元素的前驱？\n");
            scanf("%d", &i);
            if (PriorElem(Lists.elem[list_num - 1].L, i, pre) == OK)
                printf("该元素的前驱是%d\n", pre);
            else
                printf("不存在该元素\n");
            getchar();
            getchar();
            break;
        case 9: // 获取后继元素
            int next;
            printf("您想查找哪个元素的后驱？\n");
            scanf("%d", &i);
            if (NextElem(Lists.elem[list_num - 1].L, i, next) == OK)
                printf("该元素的后驱是%d\n", next);
            else
                printf("不存在该元素\n");
            getchar();
            getchar();
            break;
        case 10: // 插入元素
            printf("请输入要插入的元素\n");
            scanf("%d", &temp);
            printf("请输入要插入的位置\n");
            scanf("%d", &m);
            if (ListInsert(Lists.elem[list_num - 1].L, m, temp) == OK)
            {
                printf("插入成功\n");
                printf("插入后的线性表为:\n");
                if (!ListTraverse(Lists.elem[list_num - 1].L))
                    printf("线性表是空表！\n");
            }
            else
                printf("插入失败\n");
            getchar();
            getchar();
            break;
        case 11: // 删除元素
            printf("请输入删除的位置\n");
            scanf("%d", &temp);
            if (ListDelete(Lists.elem[list_num - 1].L, temp, m) == OK)
            {
                printf("删除成功\n");
                printf("删除后的线性表为:");
                if (!ListTraverse(Lists.elem[list_num - 1].L))
                    printf("空表！\n");
            }
            else
                printf("删除失败\n");
            getchar();
            getchar();
            break;
        case 12: // 遍历线性表
            if (!ListTraverse(Lists.elem[list_num - 1].L))
                printf("线性表是空表！\n");
            getchar();
            getchar();
            break;
        case 13: // 线性表读写文件
            char filename[30];
            printf("请输入指令\n");
            printf("1.文件读取\n");
            printf("2.文件写入\n");
            scanf("%d", &i);
            if (i == 1)
            {

                printf("请输入需要读取的文件地址,请用.dat作为后缀\n");
                scanf("%s", filename);
                printf("请输入你想创建的线性表名称\n");
                scanf("%s", firstname);
                AddList(Lists, firstname);
                if (LoadList(Lists.elem[Lists.length - 1].L, filename) == OK)
                {
                    printf("读取成功\n");
                    count++;
                }
                else
                    printf("读取失败\n");
            }
            else if (i == 2)
            {
                printf("请输入需要写入的文件地址,请用.dat作为后缀\n");
                scanf("%s", filename);
                if (SaveList(Lists.elem[list_num - 1].L, filename) == OK)
                    printf("写入成功\n");

                else
                    printf("写入失败\n");
            }
            getchar();
            getchar();
            break;
        case 14: // 多线性表管理：增加一个新线性表
            printf("请输入新线性表名字\n");
            scanf("%s", firstname);
            if ((temp = LocateList(Lists, firstname)) > 0)
            {
                printf("有重复名称,无法创建\n");
                getchar();
                getchar();
                break;
            }
            AddList(Lists, firstname);
            printf("请输入元素,以0结束\n");
            scanf("%d", &i);
            while (i)
            {
                ListInsert(Lists.elem[Lists.length - 1].L, Lists.elem[Lists.length - 1].L.length + 1, i);
                scanf("%d", &i);
            }
            if (!ListTraverse(Lists.elem[Lists.length - 1].L))
                printf("线性表是空表！\n");
            else
                count++;
            getchar();
            getchar();
            break;
        case 15: // 多线性表管理：移除一个线性表
            printf("请输入需要移除的线性表名字\n");
            scanf("%s", firstname);
            if (RemoveList(Lists, firstname) == OK)
                printf("移除成功\n");
            else
                printf("移除失败\n");
            getchar();
            getchar();
            break;
        case 16: // 多线性表管理：查找线性表
            printf("请输入需要查找的线性表名字\n");
            scanf("%s", firstname);
            if ((temp = LocateList(Lists, firstname)) == 0)
                printf("查找失败\n");
            else
                printf("查找成功,位置为%d\n", temp);
            getchar();
            getchar();
            break;
        case 17:
            temp = sortList(Lists.elem[list_num - 1].L);
            if (temp)
            {
                printf("排序成功,排序后的线性表为:");
                for (int i = 0; i < Lists.elem[list_num - 1].L.length; i++)
                {
                    printf("%d ", Lists.elem[list_num - 1].L.elem[i]);
                }
            }
            getchar();
            getchar();
            break;
        case 18:
            SubArrayNum(Lists.elem[list_num - 1].L);
            getchar();
            getchar();
            break;
        case 19:
            MaxSubArray(Lists.elem[list_num - 1].L);
            getchar();
            getchar();
            break;
        case 20:
            printf("创建的线性表有：\n");
            for (int temp_2 = 0; temp_2 < Lists.length; temp_2++)
            {
                printf("%s\n", Lists.elem[temp_2].name);
            }
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
} // end of main()
