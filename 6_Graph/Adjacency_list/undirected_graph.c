#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Adj_node
{
    int index;
    struct Adj_node *next;
};

struct Vex_node
{
    char node;
    struct Adj_node *first;
};

struct ALG_graph
{
    int vex_num, edge_num;
    struct Vex_node Vex[MAX];
};

struct ALG_graph *Create_ALG_graph(void);
int search_vex(char ch, struct ALG_graph* graph);
void create_adj_node_list(int i, int j, struct ALG_graph *graph);
void Show_ALG_graph(struct ALG_graph *graph);


int main(void)
{
    struct ALG_graph *ud_graph;
	ud_graph = Create_ALG_graph();
	Show_ALG_graph(ud_graph);
    
    return 0;
}

struct ALG_graph *Create_ALG_graph(void)
{
    int i, j;
    int ch1, ch2;

    struct ALG_graph *graph;
    graph = (struct ALG_graph *)malloc(sizeof(struct ALG_graph));

    /*get the number of vex and edge*/
    printf("Please enter the number of vex : ");
    scanf("%d", &graph->vex_num);
    printf("Please enter the number of edge : ");
    scanf("%d", &graph->edge_num);
    while(getchar() != '\n');

    /*configure the val of vertexs*/
    printf("Please enter the vertex : \n");
    for (i = 0; i < graph->vex_num; i++)
    {
        graph->Vex[i].node = getchar();
        while(getchar() != '\n');
    }
    /*configure the pointer of vertexs*/
    for (i = 0; i < graph->vex_num; i++)
    {
        graph->Vex[i].first = NULL;
    }

    /*Configure the adjacency list and create the graph*/
    while(graph->edge_num--)
    {
        printf("Please enter the vertex that connect each other by edge:\n");
        ch1 = getchar();
        while(getchar() != '\n');
        ch2 = getchar();
        while(getchar() != '\n');

        i = search_vex(ch1, graph);
        j = search_vex(ch2, graph);

        if (i != -1 && j != -1)
            create_adj_node_list(i, j, graph);
            create_adj_node_list(j, i, graph);
        else
        {
            printf("Error! Please enter again !");
            graph->edge_num++;
        }
    }
    return graph;
}

int search_vex(char ch, struct ALG_graph* graph)
{
    int i;
    for (i = 0; i < graph->vex_num; i++)
    {
        if (ch == graph->Vex[i].node)
            return i;
    }
    return -1;
}

void create_adj_node_list(int i, int j, struct ALG_graph *graph)
{
    struct Adj_node *s;
    s= (struct Adj_node*)malloc(sizeof(struct Adj_node));

    s->index = j;
    s->next = graph->Vex[i].first;
    graph->Vex[i].first = s;
}

void Show_ALG_graph(struct ALG_graph *graph)
{
    int i;
	struct Adj_node *t;

    printf("Show the ALG graph:\n");
    for(i = 0; i < graph->vex_num; i++)
	{
		printf("%c: ", graph->Vex[i].node);
		t = graph->Vex[i].first;
		while(t != NULL)
		{
			printf("%d ", t->index);
			t = t->next;
		}
		printf("\n");
	}
}