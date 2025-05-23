#include "def.h"
#include <vector>
#include "file_using.h"
#include "PreOrderTraverse.h"
#include "PostOrderTraverse.h"
#include "LocateNode.h"
#include "LevelOrderTraverse.h"
#include "InsertNode.h"
#include "InOrderTraverse.h"
#include "GetSibling.h"
#include "DestroyBiTree.h"
#include "DeleteNode.h"
#include "ClearBiTree.h"
#include "CreateBiTree_pre.h"
#include "BiTreeDepth.h"
#include "Assign.h"
#include "AddList.h"
#include "LocateList.h"
#include "RemoveList.h"
#include "reverseTree.h"
#include "get_definition.h"
#include "MaxPathSum.h"
#include "LowestCommonAncestor.h"

int main()
{
    LISTS Lists;
    Lists.length = 0;
    TElemType definition[100];
    int op = 1;
    int i;
    int temp, m;
    int result = 0;
    TElemType temp_2;
    int list_num = 1;
    int count = 0;
    char firstname[30];
    while (op)
    {
        char name_temp[30];
        printf("\n\n");
        printf("      Menu for non-Linear Table On non-Sequence Structure \n");
        printf("-------------------------------------------------\n");
        if (count > 1)
        {
            printf("创建的线性表有：\n");
            for (int temp_2 = 0; temp_2 < Lists.length; temp_2++)
            {
                if (strcmp(Lists.elem[temp_2].name, "0") != 0)
                    printf("%s\n", Lists.elem[temp_2].name);
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
        printf("    	  1. CreateBiTree   12. PreOrderTraverse\n");
        printf("    	  2. DestroyBiTree  13. InOrderTraverse\n");
        printf("    	  3. ClearBiTree    14. PostOrderTraverse\n");
        printf("    	  4. BiTreeEmpty    15. AddList\n");
        printf("    	  5. BiTreeDepth    16. RemoveList\n");
        printf("    	  6. Assign         17. LocateList\n");
        printf("          7. LocateNode     18. LevelOrderTraverse\n");
        printf("          8. GetSibling     19. InvertTree\n");
        printf("          9. DeleteNode     20. MaxPathSum\n");
        printf("          10. InsertNode    21. ShowAllList\n");
        printf("    	  11. file_using    22. LowestCommonAncestor\n");
        printf("          0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~21]:");
        scanf("%d", &op);
        switch (op)
        {
        case 1: // 二叉树的创建
            if (Lists.length > 0)
            {
                printf("已初始化线性表\n");
                getchar();
                getchar();
                break;
            }
            printf("请输入你想创建的线性表名称\n");
            scanf("%s", firstname);
            if (strcmp(firstname, "0") == 0)
            {
                printf("名字非法\n");
                getchar();
                getchar();
                break;
            }
            AddList(Lists, firstname);
            // printf("1. 前序输入 \n2. 中序输入\n3. 后序输入\n");
            // scanf("%d", &i);
            printf("请问你想如何创建二叉树?\n关键字为0时,表示空子树\n-1表示输入结束\n");
            get_definition(definition);
            // if (i == 1)
            // {
            if (CreateBiTree_pre(Lists.elem[Lists.length - 1].T, definition))
            {
                PreOrderTraverse(Lists.elem[Lists.length - 1].T);
                count++;
                printf("\n创建成功\n");
            }
            else
                printf("创建失败，有重复关键字\n");
            getchar();
            getchar();
            break;
        case 2: // 销毁二叉树
            if (DestroyBiTree(Lists.elem[list_num - 1].T) == OK)
                printf("销毁二叉树成功\n");
            else
                printf("二叉树已空\n");
            getchar();
            getchar();
            break;
        case 3: // 清空二叉树
            if (ClearBiTree(Lists.elem[list_num - 1].T->lchild) == OK && ClearBiTree(Lists.elem[list_num - 1].T->rchild) == OK)
            {
                printf("清空二叉树成功\n");
            }
            else
                printf("二叉树已空\n");
            getchar();
            getchar();
            break;
        case 4: // 二叉树判空
            if (Lists.elem[list_num - 1].T == NULL)
                printf("二叉树为空\n");
            else if (Lists.elem[list_num - 1].T->lchild || Lists.elem[list_num - 1].T->rchild || (Lists.elem[list_num - 1].T->lchild == NULL && Lists.elem[list_num - 1].T->rchild == NULL && Lists.elem[list_num - 1].T))
                printf("二叉树不为空\n");
            else
                printf("二叉树不存在\n");
            getchar();
            getchar();
            break;
        case 5: // 二叉树深度
            if ((i = BiTreeDepth(Lists.elem[list_num - 1].T)) > 0)
                printf("线性表深度为%d\n", i);
            else
                printf("线性表为空\n");
            getchar();
            getchar();
            break;
        case 6: // 节点赋值
            printf("您想更改哪个位置的值？\n");
            scanf("%d", &i);
            printf("您想将其更改为什么值？\n");
            scanf("%d %s", &temp_2.key, &temp_2.others);
            if (Assign(Lists.elem[list_num - 1].T, i, temp_2))
            {
                printf("赋值成功");
                PreOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
                InOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
            }
            else
                printf("赋值失败\n");
            getchar();
            getchar();
            break;
        case 7: // 查找结点
            printf("您想查找哪个元素？\n");
            scanf("%d", &i);
            BiTree p;
            if ((p = LocateNode(Lists.elem[list_num - 1].T, i)) != NULL)
            {
                printf("该节点为%d %s\n", p->data.key, p->data.others);
            }
            else
                printf("不存在该元素\n");
            getchar();
            getchar();
            break;
        case 8: // 获得兄弟结点
            printf("您想查找哪个元素的兄弟？\n");
            scanf("%d", &i);
            if ((p = GetSibling(Lists.elem[list_num - 1].T, i)) != NULL)
                printf("该元素的兄弟结点是%d %s\n", p->data.key, p->data.others);
            else
                printf("该元素无兄弟结点\n");
            getchar();
            getchar();
            break;
        case 9: // 删除结点
            printf("您想删除哪个位置的元素？\n");
            scanf("%d", &i);
            if (DeleteNode(Lists.elem[list_num - 1].T, i) == OK)
            {
                printf("该删除成功\n");
                PreOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
                InOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
            }
            else
                printf("删除操作失败\n");
            getchar();
            getchar();
            break;
        case 10: // 插入元素
            printf("请输入要插入的元素\n");
            scanf("%d %s", &temp_2.key, &temp_2.others);
            printf("请输入要插入的位置\n");
            scanf("%d", &i);
            printf("0:左孩子\n1:右孩子\n-1:根节点\n");
            scanf("%d", &temp);
            if (InsertNode(Lists.elem[list_num - 1].T, i, temp, temp_2) == OK)
            {
                printf("插入成功\n");
                PreOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
                InOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
            }
            else
                printf("插入失败\n");
            getchar();
            getchar();
            break;
        case 11: // 文件读写
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
                if ((temp = LocateList(Lists, firstname)) > 0)
                {
                    printf("有重复名称,无法创建\n");
                    break;
                }
                AddList(Lists, firstname);
                if (LoadBiTree(Lists.elem[Lists.length - 1].T, filename) == OK)
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
                if (SaveBiTree(Lists.elem[list_num - 1].T, filename) == OK)
                    printf("写入成功\n");
                else
                    printf("写入失败\n");
            }
            getchar();
            getchar();
            break;
        case 12: // 前序遍历
            PreOrderTraverse(Lists.elem[list_num - 1].T);
            printf("\n");
            getchar();
            getchar();
            break;
        case 13: // 中序遍历
            InOrderTraverse(Lists.elem[list_num - 1].T);
            printf("\n");
            getchar();
            getchar();
            break;
        case 15: // 多线性表管理：增加一个线性表
            printf("请输入新线性表名字\n");
            scanf("%s", firstname);
            if ((temp = LocateList(Lists, firstname)) > 0)
            {
                printf("有重复名称,无法创建\n");
                break;
            }
            AddList(Lists, firstname);
            printf("请问你想如何创建二叉树?\n关键字为0时,表示空子树,-1表示输入结束\n");
            get_definition(definition);
            if (CreateBiTree_pre(Lists.elem[Lists.length - 1].T, definition))
            {
                PreOrderTraverse(Lists.elem[Lists.length - 1].T);
                count++;
                printf("\n创建成功\n");
            }
            else
                printf("创建失败，有重复关键字\n");
            getchar();
            getchar();
            break;
        case 16: // 多线性表管理：移除线性表
            printf("请输入需要移除的线性表名字\n");
            scanf("%s", firstname);
            if (RemoveList(Lists, firstname) == OK)
                printf("移除成功\n");
            else
                printf("移除失败\n");
            getchar();
            getchar();
            break;
        case 17: // 多线性表管理：查找线性表
            printf("请输入需要查找的线性表名字\n");
            scanf("%s", firstname);
            if ((temp = LocateList(Lists, firstname)) == 0)
                printf("查找失败\n");
            else
                printf("查找成功,位置为%d\n", temp);
            getchar();
            getchar();
            break;
        case 14: // 后序遍历
            PostOrderTraverse(Lists.elem[list_num - 1].T);
            printf("\n");
            getchar();
            getchar();
            break;
        case 19: // 二叉树翻转
            if (InvertTree(Lists.elem[list_num - 1].T))
            {
                printf("反转成功,反转后的线性表为：\n");
                PreOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
                InOrderTraverse(Lists.elem[list_num - 1].T);
                printf("\n");
            }
            else
                printf("翻转失败");
            getchar();
            getchar();
            break;
        case 18: // 层序遍历
            LevelOrderTraverse(Lists.elem[list_num - 1].T);
            printf("\n");
            getchar();
            getchar();
            break;
        case 20: // 最大路径和
            result = 0;
            MaxPathSum(Lists.elem[list_num - 1].T, result);
            printf("最大路径和为%d\n", result);
            getchar();
            getchar();
            break;
        case 21: // show all lists
            printf("创建的线性表有：\n");
            for (int temp_2 = 0; temp_2 < Lists.length; temp_2++)
            {
                if (strcmp(Lists.elem[temp_2].name, "0") != 0)
                    printf("%s\n", Lists.elem[temp_2].name);
            }
            getchar();
            getchar();
            break;
        case 22: // 最近公共祖先
            printf("请输入要求的两个节点数据\n");
            scanf("%d %d", &temp, &i);
            BiTree t;
            t = LowestCommonAncestor(Lists.elem[list_num - 1].T, temp, i);
            if (t)
                printf("最近共同祖先是:%d", t->data.key);
            else
                printf("无法找到");
            getchar();
            getchar();
            break;
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
} // end of main()