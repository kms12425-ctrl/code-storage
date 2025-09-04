#include "SAT.hpp"

int find_unit_clause(clause_list cl) // 找到单子句
{
    while (cl)
    {
        if (cl->head != NULL && cl->head->next == NULL)
            return cl->head->literal;
        cl = cl->next;
    }
    return 0;
}
void remove_clause(clause_list &cl) // 删除子句
{
    literal_list temp = cl->head;
    while (temp)
    {
        literal_list p = temp;
        temp = temp->next;
        delete (p);
    }
    delete (cl);
    cl = NULL;
    return;
}
void simplify(clause_list &cl, int lit) // 化简子句
{
    clause_list pre = NULL, p = cl;
    while (p)
    {
        bool is_deleted = 0;
        literal_list lpre = NULL, q = p->head;
        while (q)
        {
            if (q->literal == lit) // 文字等于 literal
            {
                if (!pre)
                {
                    cl = cl->next;
                    remove_clause(p);
                    p = cl;
                }
                else
                {
                    pre->next = p->next;
                    remove_clause(p);
                    p = pre->next;
                }
                is_deleted = 1;
                break;
            }
            else if (q->literal == -lit) // 文字等于 -literal
            {
                if (lpre)
                {
                    lpre->next = q->next;
                    delete (q);
                    q = lpre->next;
                }
                else
                {
                    p->head = q->next;
                    delete (q);
                    q = p->head;
                }
            }
            else // 啥都没有
            {
                lpre = q;
                q = q->next;
            }
        }
        if (!is_deleted)
        {
            pre = p;
            p = p->next;
        }
    }
}

clause_list copy_cnf(clause_list cl)
{
    clause_list new_cnf = new clause_node;
    clause_list cl_new = new_cnf, cl_old = cl;
    while (cl_old)
    {
        literal_list lit_new;
        literal_list lit_old = cl_old->head;
        if (lit_old)
        {
            lit_new = new literal_node;
            lit_new->literal = lit_old->literal;
            lit_new->next = NULL;
            cl_new->head = lit_new;
            lit_old = lit_old->next;
        }
        while (lit_old)
        {
            lit_new->next = new literal_node;
            lit_new = lit_new->next;
            lit_new->literal = lit_old->literal;
            lit_new->next = NULL;
            lit_old = lit_old->next;
        }
        if (cl_old->next)
        {
            cl_new->next = new clause_node;
            cl_new = cl_new->next;
            cl_new->next = NULL;
            cl_new->head = NULL;
        }
        cl_old = cl_old->next;
    }
    return new_cnf;
}
bool is_satisfy(clause_list cl) // 判断cnf是否可以满足
{
    if (!cl)
        return 1;
    return 0;
}
bool is_empty_clause(clause_list cl)
{
    while (cl)
    {
        if (!cl->head)
            return 1;
        cl = cl->next;
    }
    return 0;
}
int choose_literal_1(CNF cnf) // 没有优化的选择
{
    return cnf->root->head->literal;
}
int choose_literal_2(CNF cnf) // 找出现最多的字
{

    int *value = new int[cnf->bool_count * 2 + 1];
    for (int i = 0; i < cnf->bool_count * 2 + 1; i++)
        value[i] = 0;
    for (clause_list cl = cnf->root; cl != NULL; cl = cl->next)
    {
        for (literal_list lit = cl->head; lit != NULL; lit = lit->next)
        {
            if (lit->literal > 0)
                value[lit->literal]++;
            else
                value[cnf->bool_count - lit->literal]++;
        }
    }
    int max = 0, max_lit;
    for (int i = 0; i < cnf->bool_count; i++)
    {
        if (value[i] > max)
        {
            max = value[i];
            max_lit = i;
        }
    }
    if (max == 0)
    {
        for (int i = cnf->bool_count; i < cnf->bool_count * 2; i++)
        {
            if (value[i] > max)
            {
                max = value[i];
                max_lit = cnf->bool_count - i;
            }
        }
    }
    delete[] value;
    return max_lit;
}

int choose_literal_3(CNF cnf) // 在最小子句找出现次数最多的字
{

    clause_list max_cl;
    int *value = new int[cnf->bool_count * 2 + 1];
    for (int i = 0; i <= cnf->bool_count * 2; i++)
        value[i] = 0;
    int max = INT_MAX;
    for (clause_list cl = cnf->root; cl; cl = cl->next)
    {
        int count = 0;
        literal_list lit = cl->head;
        while (lit)
        {
            count++;
            lit = lit->next;
        }
        if (count < max)
        {
            max = count;
            max_cl = cl;
        }
    }
    for (literal_list lit = max_cl->head; lit != NULL; lit = lit->next)
    {
        value[lit->literal + cnf->bool_count]++;
    }
    max = 0;
    int max_lit;
    for (int i = 0; i < cnf->bool_count * 2 + 1; i++)
    {
        if (value[i] > max)
        {
            max = value[i];
            max_lit = i - cnf->bool_count;
        }
    }
    delete[] value;
    return max_lit;
}

bool save_file()
{
}
int DPLL(CNF cnf, bool value[], int flag)
{
}