#include "def.h"
#include "file_using.h"
#include "BFSTraverse.h"
#include "CreateGraph.h"
#include "DeleteArc.h"
#include "DeleteVex.h"
#include "DestroyGraph.h"
#include "DFSTraverse.h"
#include "InsertArc.h"
#include "InsertVex.h"
#include "LocateVex.h"
#include "PutVex.h"
#include "VerticesSetLessThanK.h"
#include "AddList.h"
#include "LocateList.h"
#include "RemoveList.h"
#include "ShortestPathLength.h"
#include "ConnectedComponentsNums.h"

int main()
{
    LISTS Lists;
    Lists.length = 0;
    int op = 1;
    int i;
    int temp;
    int temp_2;
    int list_num = 1;
    int count = 0;
    char firstname[30];
    while (op)
    {
        char name_temp[30];
        printf("\n\n");
        printf("      Menu for non-Linear Table On Graph Structure \n");
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
        printf("    	  1. CreateGraph   11. file_using\n");
        printf("    	  2. DestroyGraph  12. DFSTraverse\n");
        printf("    	  3. LocateVex     13. BFSTraverse\n");
        printf("    	  4. PutVex        14. VerticesSetLessThanK\n");
        printf("    	  5. FirstAdjVex   15. AddList\n");
        printf("    	  6. NextAdjVex    16. RemoveList\n");
        printf("          7. InsertVex     17. LocateList\n");
        printf("          8. DeleteVex     18. ShortestPathLength\n");
        printf("          9. InsertArc     19. ConnectedComponentsNums\n");
        printf("          10. DeleteArc    20. ShowAllList\n\n");
        printf("          0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~20]:");
        scanf("%d", &op);
        switch (op)
        {
        case 1: // 图的创建
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
            VertexType V[30];
            KeyType VR[100][2];
            i = 0;
            int j;
            printf("请输入节点信息\n");
            do
            {
                scanf("%d%s", &V[i].key, V[i].others);
            } while (V[i++].key != -1);
            printf("请输入边\n");
            i = 0;
            do
            {
                scanf("%d%d", &VR[i][0], &VR[i][1]);
            } while (VR[i++][0] != -1);
            if (CreateGraph(Lists.elem[Lists.length - 1].T, V, VR))
            {
                printf("创建成功\n");
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
                count++;
            }
            else
                printf("创建失败，有重复关键字\n");
            getchar();
            getchar();
            break;
        case 2: // 销毁图
            if (DestroyGraph(Lists.elem[list_num - 1].T) == OK)
                printf("销毁图成功\n");
            getchar();
            getchar();
            break;
        case 3: // 查找顶点
            printf("请输入想要查找的顶点\n");
            scanf("%d", &i);
            if (!LocateVex(Lists.elem[list_num - 1].T, i))
                printf("查找失败\n");
            getchar();
            getchar();
            break;
        case 4: // 顶点赋值
            printf("请输入你想赋值的顶点\n");
            scanf("%d", &i);
            printf("请输入新值\n");
            VertexType value;
            scanf("%d%s", &value.key, value.others);
            if (PutVex(Lists.elem[list_num - 1].T, i, value))
            {
                printf("赋值成功\n");
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
            }
            getchar();
            getchar();
            break;
        case 5: // 获得第一邻接点
            printf("请输入你想求的节点\n");
            scanf("%d", &i);
            if (FirstAdjVex(Lists.elem[Lists.length - 1].T, i) == -1)
                printf("查找失败");
            getchar();
            getchar();
            break;
        case 6: // 获得下一邻接点
            printf("请输入你想求的节点\n");
            scanf("%d", &i);
            printf("请输入该节点的邻接节点\n");
            scanf("%d", &temp_2);
            if (NextAdjVex(Lists.elem[Lists.length - 1].T, i, temp_2) == -1)
                printf("查找失败");
            getchar();
            getchar();
            break;
        case 7: // 插入顶点
            printf("请输入插入顶点信息\n");
            scanf("%d%s", &value.key, value.others);
            if (InsertVex(Lists.elem[Lists.length - 1].T, value))
            {
                printf("插入成功\n");
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
            }
            else
                printf("操作失败\n");
            getchar();
            getchar();
            break;
        case 8: // 删除顶点
            printf("请输入你想删除的节点\n");
            scanf("%d", &i);
            if (DeleteVex(Lists.elem[Lists.length - 1].T, i))
            {
                printf("删除成功\n");
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
            }
            else
                printf("操作失败\n");
            getchar();
            getchar();
            break;
        case 9: // 插入弧
            printf("请输入想插入的弧\n");
            scanf("%d %d", &i, &temp_2);
            if (InsertArc(Lists.elem[Lists.length - 1].T, i, temp_2))
            {
                printf("插入成功\n");
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
            }
            else
                printf("操作失败\n");
            getchar();
            getchar();
            break;
        case 10: // 删除弧
            printf("请输入想删除的弧\n");
            scanf("%d %d", &i, &temp_2);
            if (DeleteArc(Lists.elem[Lists.length - 1].T, i, temp_2))
            {
                printf("删除成功\n");
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
            }
            else
                printf("操作失败\n");
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
                printf("请输入你想创建的图名称\n");
                scanf("%s", firstname);
                if ((temp = LocateList(Lists, firstname)) > 0)
                {
                    printf("有重复名称,无法创建\n");
                    break;
                }
                AddList(Lists, firstname);
                if (LoadGraph(Lists.elem[Lists.length - 1].T, filename) == OK)
                {
                    printf("读取成功\n");
                    for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                    {
                        ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                        printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                        while (p)
                        {
                            printf(" %d", p->adjvex);
                            p = p->nextarc;
                        }
                        printf("\n");
                    }
                    count++;
                }
                else
                    printf("读取失败\n");
            }
            else if (i == 2)
            {
                printf("请输入需要写入的文件地址,请用.dat作为后缀\n");
                scanf("%s", filename);
                if (SaveGraph(Lists.elem[list_num - 1].T, filename) == OK)
                    printf("写入成功\n");
                else
                    printf("写入失败\n");
            }
            getchar();
            getchar();
            break;
        case 12: // 深度优先搜索遍历
            DFSTraverse(Lists.elem[list_num - 1].T);
            printf("\n");
            getchar();
            getchar();
            break;
        case 13: // 广度优先搜索遍历
            BFSTraverse(Lists.elem[list_num - 1].T);
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
            printf("请输入节点信息\n");
            do
            {
                scanf("%d%s", &V[i].key, V[i].others);
            } while (V[i++].key != -1);
            printf("请输入边\n");
            i = 0;
            do
            {
                scanf("%d%d", &VR[i][0], &VR[i][1]);
            } while (VR[i++][0] != -1);
            if (CreateGraph(Lists.elem[Lists.length - 1].T, V, VR))
            {
                for (j = 0; j < Lists.elem[Lists.length - 1].T.vexnum; j++)
                {
                    ArcNode *p = Lists.elem[Lists.length - 1].T.vertices[j].firstarc;
                    printf("%d %s", Lists.elem[Lists.length - 1].T.vertices[j].data.key, Lists.elem[Lists.length - 1].T.vertices[j].data.others);
                    while (p)
                    {
                        printf(" %d", p->adjvex);
                        p = p->nextarc;
                    }
                    printf("\n");
                }
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
        case 14: // 距离小于k的顶点集合
            printf("请输入顶点\n");
            scanf("%d", &i);
            printf("请输入距离k\n");
            scanf("%d", &temp_2);
            VerticesSetLessThanK(Lists.elem[Lists.length - 1].T, i, temp_2);
            getchar();
            getchar();
            break;
        case 18: // 顶点间最短路径和长度
            printf("请输入两个顶点的信息\n");
            scanf("%d %d", &i, &temp_2);
            i = ShortestPathLength(Lists.elem[Lists.length - 1].T, i, temp_2);
            if (i != 1000 && i != -2)
                printf("最短路径为:%d", i);
            else if (i == -2)
                printf("无效节点\n");
            else
                printf("两点之间没有通路\n");
            getchar();
            getchar();
            break;
        case 19: // 图的连通分量
            i = ConnectedComponentsNums(Lists.elem[Lists.length - 1].T);
            printf("连通分量个数为:%d", i);
            getchar();
            getchar();
            break;
        case 20: // show all lists
            printf("创建的线性表有：\n");
            for (int temp_2 = 0; temp_2 < Lists.length; temp_2++)
            {
                if (strcmp(Lists.elem[temp_2].name, "0") != 0)
                    printf("%s\n", Lists.elem[temp_2].name);
            }
            getchar();
            getchar();
            break;
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("欢迎下次再使用本系统！\n");
    return 0; //
} // end of main()