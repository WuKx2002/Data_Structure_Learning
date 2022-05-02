typedef struct BiTree
{
    char elem;
    struct BiTree *ltree, *rtree;
    int lflag, rflag;
}Node, *Tree;

void in_threading(Tree p);

Tree pre = NULL;
void in_threading(Tree p)
{
    if (p)
    {
        in_threading(p->ltree);
        if (!p->ltree)
        {
            p->lflag = 1;
            p->ltree = pre;
        }
        else
        {
            p->lflag = 0;
        }
        if (pre)
        {
            if (!pre->rtree)
            {
                pre->rflag = 1;
                pre->rtree = p;
            }
            else
            {
                pre->rflag = 0;
            }
        }
        pre = p;
        in_threading(p->rtree);
    }
    
}
