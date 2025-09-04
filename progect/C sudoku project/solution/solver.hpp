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
int choose_literal_2(CNF cnf) // 优化的选择
{
}
bool save_file()
{
}