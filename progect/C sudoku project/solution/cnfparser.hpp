#include "SAT.hpp"
bool read_file(char file_name[], CNF &cnf)
{
    FILE *fp = fopen(file_name, "r");
    if (!fp)
    {
        printf("文件打开失败: %s\n", file_name);
        return 0;
    }
    cnf = new cnf_node;
    // 读取头部，跳过以 'c' 开头的注释行，找到 'p cnf' 行
    char ch;
    // 跳过注释
    while ((ch = getc(fp)) == 'c')
    {
        while ((ch = getc(fp)) != '\n')
            continue;
    }
    // 跳过p cnf
    getc(fp);
    getc(fp);
    getc(fp);
    getc(fp);
    fscanf(fp, "%d%d", &cnf->bool_count, &cnf->clause_count);
    if (cnf->bool_count <= 0 || cnf->clause_count <= 0)
    {
        printf("CNF header 未找到或无效\n");
        fclose(fp);
        free(cnf);
        return 0;
    }

    // 分配 CNF 结构

    cnf->root = NULL;

    clause_list last_clause = NULL;
    for (int ci = 0; ci < cnf->clause_count; ++ci)
    {
        // 创建新的 clause 节点
        clause_list cl = new clause_node;
        cl->head = NULL;
        cl->next = NULL;

        literal_list last_lit = NULL;

        // 读取一个子句：一系列整数，以 0 结束
        int lit;
        // 用fscanf 连续读取整数
        while (fscanf(fp, "%d", &lit) == 1)
        {
            if (lit == 0)
                break;

            literal_list ln = new literal_node;
            ln->literal = lit;
            ln->next = NULL;

            if (last_lit == NULL)
            {
                cl->head = ln;
            }
            else
            {
                last_lit->next = ln;
            }
            last_lit = ln;
        }

        // 即使子句为空（不应该），仍加入链表以保持个数一致
        if (cnf->root == NULL)
        {
            cnf->root = cl;
            last_clause = cl;
        }
        else
        {
            last_clause->next = cl;
            last_clause = cl;
        }
    }

    fclose(fp);
    printf("读取成功！\n");
    return 1;
}
bool destroy_cnf(CNF &cnf)
{
    for (int i = 0; i < cnf->clause_count; i++)
    {
        clause_list temp = cnf->root;
        clause_list delete_node = temp;
        while (temp)
        {
            free(delete_node);
            temp = temp->next;
        }
    }
}