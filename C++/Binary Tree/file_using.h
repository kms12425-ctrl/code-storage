#include "string.h"
BiTree create_tree(TElemType definition[]);
int count = 0, j = 0;
status SaveBiTree(BiTree T, char FileName[])
// 将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    int i = 0;
    if (!T)
        return -1;
    FILE *fp = fopen(FileName, "wb");
    BiTree stack[100];
    TElemType definition[100];
    BiTree p = T;
    int top = 0;
    if (T)
        stack[top++] = p;
    while (top)
    {
        p = stack[--top];
        if (p)
        {
            definition[i].key = p->data.key;
            strcpy(definition[i++].others, p->data.others);
        }
        else
        {
            definition[i].key = 0;
            strcpy(definition[i++].others, "null");
        }
        if (p)
        {
            stack[top++] = p->rchild;
        }
        if (p)
            stack[top++] = p->lchild;
    }
    fwrite(&i, sizeof(int), 1, fp);
    fwrite(&definition, sizeof(TElemType), i, fp);
    fclose(fp);
    return 1;
    /********** End 1 **********/
}

status LoadBiTree(BiTree &T, char FileName[])
// 读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    j = 0;
    FILE *fp = fopen(FileName, "rb");
    fread(&count, sizeof(int), 1, fp);
    TElemType definition[count];
    fread(&definition, sizeof(TElemType), count, fp);
    T = create_tree(definition);
    return 1;
    /********** End 2 **********/
}
BiTree create_tree(TElemType definition[])
{
    if (definition[j].key == 0)
    {
        j++;
        return NULL;
    }
    BiTree root = create_Node(definition[j]);
    if (j == count)
        return root;
    j++;
    root->lchild = create_tree(definition);
    root->rchild = create_tree(definition);
    return root;
}
