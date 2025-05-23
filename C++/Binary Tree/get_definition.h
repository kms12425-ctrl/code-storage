void get_definition(TElemType definition[])
{
    int i = 0;
    do
    {
        scanf("%d%s", &definition[i].key, definition[i].others);
    } while (definition[i++].key != -1);
    return;
}