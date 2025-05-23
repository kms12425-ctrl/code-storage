status SaveGraph(ALGraph G, char FileName[])
// 将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if (G.vertices == 0)
        return 0;
    FILE *fp = fopen(FileName, "wb");
    fwrite(&G.vexnum, sizeof(int), 1, fp);
    for (int i = 0; i < G.vexnum; i++)
    {
        fwrite(&G.vertices[i].data, sizeof(VertexType), 1, fp);
        ArcNode *p = G.vertices[i].firstarc;
        int j = 0;
        while (p)
        {
            j++;
            p = p->nextarc;
        }
        p = G.vertices[i].firstarc;
        fwrite(&j, sizeof(int), 1, fp);
        while (p)
        {
            fwrite(&p->adjvex, sizeof(int), 1, fp);
            p = p->nextarc;
        }
    }
    fclose(fp);
    return 1;
    /********** End 1 **********/
}
status LoadGraph(ALGraph &G, char FileName[])
// 读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName, "rb");
    fread(&G.vexnum, sizeof(int), 1, fp);
    G.kind = UDG;
    G.arcnum = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        fread(&G.vertices[i].data, sizeof(VertexType), 1, fp);
        G.vertices[i].firstarc = NULL;
        int count;
        fread(&count, sizeof(int), 1, fp);
        if (count)
        {
            ArcNode *r = new ArcNode;
            fread(&r->adjvex, sizeof(int), 1, fp);
            r->nextarc = NULL;
            G.arcnum++;
            G.vertices[i].firstarc = r;
        }
        ArcNode *tail = G.vertices[i].firstarc;
        for (int j = 0; j < count - 1; j++)
        {
            ArcNode *p = new ArcNode;
            fread(&p->adjvex, sizeof(int), 1, fp);
            p->nextarc = NULL;
            tail->nextarc = p;
            tail = tail->nextarc;
            G.arcnum++;
        }
    }
    fclose(fp);
    return 1;
    /********** End 2 **********/
}