#include <string.h>
status PutVex(ALGraph &G, KeyType u, VertexType value)
// 根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
// 如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            for (int j = 0; j < G.vexnum; j++)
            {
                if (j == i)
                    continue;
                if (G.vertices[j].data.key == value.key)
                    return 0;
            }
            G.vertices[i].data.key = value.key;
            strcpy(G.vertices[i].data.others, value.others);
            return 1;
        }
    }
    return 0;
    /********** End **********/
}
