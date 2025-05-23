status DeleteArc(ALGraph &G, KeyType v, KeyType w)
// 在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
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
    flag = 0;
    while (p)
    {
        if (p->adjvex == two)
        {
            flag = 1;
            break;
        }
        p = p->nextarc;
    }
    if (!flag)
        return 0;
    flag = 0;
    p = G.vertices[two].firstarc;
    while (p)
    {
        if (p->adjvex == one)
        {
            flag = 1;
            break;
        }
        p = p->nextarc;
    }
    if (!flag)
        return 0;
    p = G.vertices[one].firstarc;
    ArcNode *q;
    if (p->adjvex == two)
    {
        ArcNode *temp = p;
        p = p->nextarc;
        G.vertices[one].firstarc = p;
        free(temp);
    }
    else
    {
        while (p->nextarc)
        {
            q = p;
            if (p->nextarc->adjvex == two)
            {
                ArcNode *temp = p->nextarc;
                p = temp->nextarc;
                q->nextarc = p;
                free(temp);
                break;
            }
            p = p->nextarc;
        }
    }

    p = G.vertices[two].firstarc;
    if (p->adjvex == one)
    {
        ArcNode *temp = p;
        p = p->nextarc;
        G.vertices[two].firstarc = p;
        free(temp);
    }
    else
    {
        while (p->nextarc)
        {
            q = p;
            if (p->nextarc->adjvex == one)
            {
                ArcNode *temp = p->nextarc;
                p = temp->nextarc;
                q->nextarc = p;
                free(temp);
                break;
            }
            p = p->nextarc;
        }
    }
    G.arcnum--;
    return 1;
    /********** End **********/
}