#include "def.h"
#include "insert_type.h"
int main()
{
    SqList L;
    L.elem = new ElemType;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    int count = 0;
    int i;
    scanf("%d", &i);
    while (i)
    {
        L.elem[count++] = i;
        scanf("%d", &i);
    }
    L.length = count;
    scanf("%d", &i);
    while (i)
    {
        switch (i)
        {
        case 1:
            insertsort(L);
            visit(L);
            getchar();
            getchar();
            break;
        case 2:
            Binsersort(L);
            visit(L);
            getchar();
            getchar();
        default:
            return 0;
        }
        scanf("%d", &i);
    }
    return 0;
}