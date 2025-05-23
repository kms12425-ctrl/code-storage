int ShortestPathLength(ALGraph &G, int v, int w)
{
    int one, two;
    bool flag_1 = 0, flag_2 = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            one = i;
            flag_1 = 1;
        }
        if (G.vertices[i].data.key == w)
        {
            two = i;
            flag_2 = 1;
        }
    }
    if (!flag_1 || !flag_2)
        return -2;

    int G_2[G.vexnum][G.vexnum];
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
            G_2[i][j] = 1000;
    for (int i = 0; i < G.vexnum; i++)
    {
        int j = 0;
        ArcNode *p = G.vertices[i].firstarc;
        G_2[i][i] = 0;
        while (p)
        {
            G_2[i][p->adjvex] = 1;
            p = p->nextarc;
        }
    }

    int D[G.vexnum];           // 最短路径长度集合
    int P[G.vexnum];           // 他的前驱节点
    int final[G.vexnum] = {0}; // 检查有没有探索完
    for (int i = 0; i < G.vexnum; i++)
    {
        P[i] = one;
        D[i] = G_2[one][i];
    }
    D[one] = 0, final[one] = 1;
    for (int i = 1; i < G.vexnum; i++)
    {
        int j, min = 1000;
        for (int k = 0; k < G.vexnum; k++)
        {
            if (final[k] == 0 && D[k] != 1000 && D[k] < min)
            {
                j = k;
                min = D[k];
            }
        }
        final[j] = 1;
        for (int k = 0; k < G.vexnum; k++)
        {
            if (final[k] != 1 && k != j && (D[k] > D[j] + G_2[j][k]))
            {
                D[k] = D[j] + G_2[j][k];
                P[k] = j;
            }
        }
    }
    return D[two];
}