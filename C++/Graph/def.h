#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType;
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;
typedef struct
{
    KeyType key;
    char others[20];
} VertexType; // 顶点类型定义

typedef struct ArcNode
{                            // 表结点类型定义
    int adjvex;              // 顶点位置编号
    struct ArcNode *nextarc; // 下一个表结点指针
} ArcNode;
typedef struct VNode
{                      // 头结点及其数组类型定义
    VertexType data;   // 顶点信息
    ArcNode *firstarc; // 指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{                       // 邻接表的类型定义
    AdjList vertices;   // 头结点数组
    int vexnum, arcnum; // 顶点数、弧数
    GraphKind kind;     // 图的类型
} ALGraph;

typedef struct
{ // 线性表的管理表定义
    struct
    {
        char name[30];
        ALGraph T;
    } elem[10];
    int length;
    int listsize;
} LISTS;
int FirstAdjVex(ALGraph G, KeyType u)
// 根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            int p;
            if (G.vertices[i].firstarc)
            {
                p = G.vertices[i].firstarc->adjvex;
                printf("第一邻接顶点位序为:%d", p);
                return p;
            }
            else
                return -1;
        }
    }
    return -1;
    /********** End **********/
}
int NextAdjVex(ALGraph G, KeyType v, KeyType w)
// v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag = 0;
    bool flag_2 = 0;
    for (flag = 0; flag < G.vexnum; flag++)
    {
        if (G.vertices[flag].data.key == w)
        {
            flag_2 = 1;
            break;
        }
    }
    if (!flag_2)
        return -1;
    for (int j = 0; j < G.vexnum; j++)
    {
        if (G.vertices[j].data.key == v)
        {
            ArcNode *p = G.vertices[j].firstarc;
            while (p)
            {
                if (p->adjvex == flag && p->nextarc)
                {
                    printf("下一个邻接顶点的位序为:%d", p->nextarc->adjvex);
                    return p->nextarc->adjvex;
                }
                p = p->nextarc;
            }
        }
    }
    return -1;
    /********** End **********/
}
