int h = 0;

void DFS_2(ALGraph &G, int v, bool visited[])
{
    visited[v] = 1;
    for (int i = FirstAdjVex_1(G, G.vertices[v].data.key); i != -1; i = NextAdjVex_1(G, G.vertices[v].data.key, G.vertices[i].data.key))
    {
        if (!visited[i])
            DFS_2(G, i, visited);
    }
    return;
}

status DFSTraverse_2(ALGraph &G)
// 对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    bool visited[G.vexnum] = {0};
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            h++;
            DFS_2(G, i, visited);
        }
    }
    return 1;
    /********** End **********/
}

int ConnectedComponentsNums(ALGraph G)
{
    DFSTraverse_2(G);
    return h;
}