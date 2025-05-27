using namespace std;
int BFS_2(ALGraph &G, int v, vector<int> &dis);
void VerticesSetLessThanK(ALGraph &G, int v, int k)
{
    int one;
    bool flag_1 = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            one = i;
            flag_1 = 1;
            break;
        }
    }
    if (!flag_1)
    {
        printf("找不到节点\n");
        return;
    }
    vector<int> D(G.vexnum, 0);
    BFS_2(G, one, D);
    for (int i = 0; i < G.vexnum; i++)
        if (k > D[i])
            printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
    return;
}
int BFS_2(ALGraph &G, int v, vector<int> &dis)
{
    queue<int> q;
    dis[v] = 0;
    bool visited[G.vexnum] = {0};
    visited[v] = 1;
    q.push(v);
    while (!q.empty())
    {
        int j = q.front();
        q.pop();
        for (auto p = G.vertices[j].firstarc; p != NULL; p = p->nextarc)
        {
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                q.push(p->adjvex);
                dis[p->adjvex] = dis[j] + 1;
            }
        }
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        if (visited[i] == 0)
        {
            dis[i] = 1000;
        }
    }
    return 1;
}