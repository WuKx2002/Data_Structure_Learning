#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct AMG_graph
{
    int vex_num, edge_num;
    char Vex[MAX];
    int Edge[MAX][MAX];
};

int search_vex(struct AMG_graph *p, char c);
struct AMG_graph *create_AMG_graph(void);
void show_AMG_graph(struct AMG_graph *p);

int main(void)
{
    struct AMG_graph *ud_graph;
    ud_graph = create_AMG_graph();
    show_AMG_graph(ud_graph);

    return 0;
}

int search_vex(struct AMG_graph *p, char c)
{
    int i;
    int ret;
    for (i = 0; i < p->vex_num; i++)
    {
        if (c == p->Vex[i])
            return i;
    }
    return -1;
}

struct AMG_graph *create_AMG_graph(void)
{
    struct AMG_graph *p;
    p = (struct AMG_graph*)malloc(sizeof(struct AMG_graph));

    printf("Please enter the number of vexs : ");
    scanf("%d", &p->vex_num);
    printf("Please enter the number of edges : ");
    scanf("%d", &p->edge_num);

    while (getchar() != '\n');

    int i,j;
    printf("Please enter the vertex : \n");
    for (i = 0; i < p->vex_num; i++)
    {
        p->Vex[i] = getchar();
        while (getchar() != '\n');
    }

    for (i = 0; i < p->vex_num; i++)
    {
        for (j = 0; j < p->vex_num; j++)
            p->Edge[i][j] = 0;
    }

    char u, v;
    while (p->edge_num--)
    {
        printf("Please enter the connection between vexs : \n");
        u = getchar();
        while (getchar() != '\n');
        v = getchar();
        while (getchar() != '\n');
        
        i = search_vex(p, u);
        j = search_vex(p, v);
        
        if (i != -1 && j != -1)
            p->Edge[i][j] = p->Edge[j][i] = 1;
        else
        {
            printf("Enter Wrong !\nPlease try again !");
            p->edge_num++;
        }
    }

    return p;
}

void show_AMG_graph(struct AMG_graph *p)
{
    int i, j;
    printf("Show the vex : ");
    for (i = 0; i < p->vex_num; i++)
        printf("%c", p->Vex[i]);
    printf("\n");

    printf("Show the adjacency matrices :\n");
    for (i = 0; i < p->vex_num; i++)
    {
        for (j = 0; j < p->vex_num; j++)
            printf("%d\t", p->Edge[i][j]);
        printf("\n");
    }
}