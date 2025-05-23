status InsertArc(ALGraph &G, KeyType v, KeyType w)
// 在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int one, two;
    bool flag = 0;
    for (one = 0; one < G.vexnum; one++)
    {
        if (G.vertices[one].data.key == v)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
        return 0;
    flag = 0;
    for (two = 0; two < G.vexnum; two++)
    {
        if (G.vertices[two].data.key == w)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
        return 0;
    ArcNode *p = G.vertices[one].firstarc;
    while (p)
    {
        if (p->adjvex == two)
            return 0;
        p = p->nextarc;
    }
    p = G.vertices[two].firstarc;
    while (p)
    {
        if (p->adjvex == one)
            return 0;
        p = p->nextarc;
    }
    ArcNode *q = new ArcNode;
    q->adjvex = two;
    q->nextarc = G.vertices[one].firstarc;
    G.vertices[one].firstarc = q;
    p = G.vertices[two].firstarc;
    ArcNode *r = new ArcNode;
    r->adjvex = one;
    r->nextarc = G.vertices[two].firstarc;
    G.vertices[two].firstarc = r;
    G.arcnum++;
    return 1;
    /********** End **********/
}