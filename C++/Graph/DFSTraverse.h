void DFS(ALGraph &G, int v, bool visited[]);
int FirstAdjVex_1(ALGraph G, KeyType u)
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
                return p;
            }
            else
                return -1;
        }
    }
    return -1;
    /********** End **********/
}
int NextAdjVex_1(ALGraph G, KeyType v, KeyType w)
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
                    return p->nextarc->adjvex;
                }
                p = p->nextarc;
            }
        }
    }
    return -1;
    /********** End **********/
}
status DFSTraverse(ALGraph &G)
// 对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    bool visited[G.vexnum] = {0};
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS(G, i, visited);
    }
    return 1;
    /********** End **********/
}

void DFS(ALGraph &G, int v, bool visited[])
{
    visited[v] = 1;
    visit(G.vertices[v].data);
    for (int i = FirstAdjVex_1(G, G.vertices[v].data.key); i != -1; i = NextAdjVex_1(G, G.vertices[v].data.key, G.vertices[i].data.key))
    {
        if (!visited[i])
            DFS(G, i, visited);
    }
    return;
}
