status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        ArcNode *q;
        while (p)
        {
            q = p->nextarc;
            free(p);
            p = q;
        }
        G.vertices[i].firstarc = NULL;
    }
    G.arcnum = 0;
    G.vexnum = 0;
    return 1;
    /********** End **********/
}
