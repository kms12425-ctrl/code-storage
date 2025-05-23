#include "string.h"
int count_1 = 0;
BiTree create_tree_pre(TElemType definition[])
{
    if (definition[count_1].key == 0)
    {
        count_1++;
        return NULL;
    }

    BiTree root = create_Node(definition[count_1]);
    if (definition[count_1].key == -1)
        return root;
    count_1++;
    root->lchild = create_tree_pre(definition);
    root->rchild = create_tree_pre(definition);
    return root;
}
status CreateBiTree_pre(BiTree &T, TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    count_1 = 0;
    int temp[200000] = {0};
    for (int i = 0; definition[i].key != -1; i++)
    {
        temp[definition[i].key]++;
        if (temp[definition[i].key] > 1 && definition[i].key != 0)
        {
            return 0;
        }
    }
    T = create_tree_pre(definition);
    return 1;
    /********** End **********/
}