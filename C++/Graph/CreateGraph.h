#include <string.h>
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    {
        int temp[100] = {0};
        for (int i = 0; V[i].key != -1; i++)
        {
            temp[V[i].key]++;
            if (temp[V[i].key] > 1)
                return 0;
        }
        for (int i = 0; VR[i][0] != -1; i++)
        {
            if (temp[VR[i][0]] == 0 || temp[VR[i][1]] == 0)
                return 0;
        }
    }
    G.vexnum = 0, G.arcnum = 0;
    G.kind = UDG;
    for (int i = 0; V[i].key != -1; i++)
    {
        G.vertices[i].data.key = V[i].key;
        strcpy(G.vertices[i].data.others, V[i].others);
        G.vertices[i].firstarc = NULL;
        G.vexnum++;
        if (i >= MAX_VERTEX_NUM)
            return 0;
    }
    if (VR[0][0] != -1)
        G.arcnum = 0;
    for (int i = 0; VR[i][0] != -1; i++)
    {
        for (int j = i + 1; VR[j][0] != -1; j++)
        {
            if ((VR[i][0] == VR[j][0] && VR[i][1] == VR[j][1]) || (VR[i][0] == VR[j][1] && VR[i][1] == VR[j][0]))
            {
                for (int k = i; VR[k - 1][0] != -1; k++)
                {
                    VR[k][0] = VR[k + 1][0];
                    VR[k][1] = VR[k + 1][1];
                }
            }
        }
    }
    for (int i = 0, j = 0; VR[i][0] != -1; i++)
    {
        int k;
        if (VR[i][0] == VR[i][1])
        {
            continue;
        }
        for (j = 0; j < G.vexnum; j++)
            if (VR[i][0] == G.vertices[j].data.key)
                break;
        for (k = 0; k < G.vexnum; k++)
            if (VR[i][1] == G.vertices[k].data.key)
                break;
        ArcNode *p = new ArcNode;
        p->adjvex = k;
        p->nextarc = G.vertices[j].firstarc;
        G.arcnum++;
        G.vertices[j].firstarc = p;

        ArcNode *q = new ArcNode;
        q->adjvex = j;
        q->nextarc = G.vertices[k].firstarc;
        G.vertices[k].firstarc = q;
    }
    return 1;
    /********** End **********/
}

// status check1(VertexType V[])
// {
//     // 判断结点集里是否有重复结点
//     int i = 0;
//     if (V[i].key == -1)
//         return 1;
//     while (V[i].key != -1)
//     {
//         for (int j = 0; j < i; j++)
//             if (V[j].key == V[i].key)
//                 return 1;
//         i++;
//     }
//     if (i > 20)
//         return 1;
//     return 0;
// }

// void deleteVR(KeyType VR[][2], int i, int &num)
// {
//     for (int k = i; k <= num; k++)
//     {
//         VR[k][0] = VR[k + 1][0];
//         VR[k][1] = VR[k + 1][1];
//     }
//     num--;
//     return;
// }

// status check2(VertexType V[], KeyType VR[][2])
// {
//     // 判断是否有重复，错乱，多余的边
//     int flag = 0;
//     for (int i = 0; VR[i][0] != -1; i++)
//     {
//         for (int j = 0; V[j].key != -1; j++)
//         {
//             if (VR[i][0] == V[j].key)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (!flag)
//             return 1;
//         flag = 0;
//     }
//     for (int i = 0; VR[i][1] != -1; i++)
//     {
//         for (int j = 0; V[j].key != -1; j++)
//         {
//             if (VR[i][1] == V[j].key)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (!flag)
//             return 1;
//         flag = 0;
//     }
//     int i = 0, num = 0;
//     while (VR[num++][0] != -1)
//         ;
//     while (VR[i][0] != -1)
//     {
//         if (VR[i][0] == VR[i][1])
//         {
//             deleteVR(VR, i, num);
//             continue;
//         }
//         for (int j = 0; j < i; j++)
//         {
//             if (VR[j][0] == VR[i][0] && VR[j][1] == VR[i][1])
//             {
//                 deleteVR(VR, i, num);
//                 i--;
//                 break;
//             }
//             if (VR[j][0] == VR[i][1] && VR[j][1] == VR[i][0])
//             {
//                 deleteVR(VR, i, num);
//                 i--;
//                 break;
//             }
//         }
//         i++;
//     }
//     return 0;
// }
// status CreateCraph(ALGraph &G, VertexType V[], KeyType VR[][2])
// /*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
// 如果有相同的关键字，返回ERROR。*/
// {
//     if (check1(V))
//         return ERROR;
//     if (check2(V, VR))
//         return ERROR;
//     G.kind = UDG;
//     G.vexnum = 0, G.arcnum = 0;
//     int m;
//     while (V[G.vexnum].key != -1)
//     {
//         G.vertices[G.vexnum].data.key = V[G.vexnum].key;
//         strcpy(G.vertices[G.vexnum].data.others, V[G.vexnum].others);
//         G.vexnum++;
//     }
//     for (int i = 0; i < G.vexnum; i++)
//     {
//         G.vertices[i].firstarc = NULL;
//     }
//     while (VR[G.arcnum][0] != -1)
//     {
//         for (int i = 0; i < G.vexnum; i++)
//         {

//             if (G.vertices[i].data.key == VR[G.arcnum][0])
//             {
//                 for (m = 0; m < G.vexnum; m++)
//                 {
//                     if (G.vertices[m].data.key == VR[G.arcnum][1])
//                         break;
//                 }
//                 ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode));
//                 t->adjvex = m;
//                 t->nextarc = G.vertices[i].firstarc;
//                 G.vertices[i].firstarc = t;
//             }

//             if (G.vertices[i].data.key == VR[G.arcnum][1])
//             {
//                 for (m = 0; m < G.vexnum; m++)
//                 {
//                     if (G.vertices[m].data.key == VR[G.arcnum][0])
//                         break;
//                 }
//                 ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode));
//                 t->adjvex = m;
//                 t->nextarc = G.vertices[i].firstarc;
//                 G.vertices[i].firstarc = t;
//             }
//         }
//         G.arcnum++;
//     }
//     return OK;
// }