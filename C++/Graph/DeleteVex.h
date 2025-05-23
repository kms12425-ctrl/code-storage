status DeleteVex(ALGraph &G, KeyType v)
// 在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            if (G.vertices[i].firstarc == NULL)
                return 0;
            ArcNode *p = G.vertices[i].firstarc;
            ArcNode *q;
            while (p)
            {
                q = p->nextarc;
                free(p);
                G.arcnum--;
                p = q;
            }
            G.vertices[i].firstarc = NULL;
            for (int j = i; j < G.vexnum; j++)
            {
                G.vertices[j] = G.vertices[j + 1];
            }
            G.vexnum--;
            for (int j = 0; j < G.vexnum; j++)
            {
                p = G.vertices[j].firstarc;
                if (p && p->adjvex == i)
                {
                    if (p->nextarc)
                    {
                        G.vertices[j].firstarc = p->nextarc;
                        free(p);
                        continue;
                    }
                    else
                    {
                        free(p);
                        G.vertices[j].firstarc = NULL;
                        continue;
                    }
                }
                while (p)
                {
                    if (p->nextarc && p->nextarc->adjvex == i)
                    {
                        q = p->nextarc;
                        p->nextarc = q->nextarc;
                        free(q);
                        break;
                    }
                    p = p->nextarc;
                }
            }
            for (int k = 0; k < G.vexnum; k++)
            {
                ArcNode *f = G.vertices[k].firstarc;
                while (f)
                {
                    if (f->adjvex > i)
                        f->adjvex--;
                    f = f->nextarc;
                }
            }
            return 1;
        }
    }
    return 0;
    /********** End **********/
}