#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Adjnode
{
	int index;
	struct Adjnode *next;
};

struct Vexnode
{
	char node;
	struct Adjnode *first;
};

struct ALG_graph
{
	int vex_num, edge_num;
	struct Vexnode Vex[MAX];
};

struct ALG_graph *Create_ALG_graph(void);
int search_vex(struct ALG_graph *graph, char c);
void create_adj_node_list(struct ALG_graph *graph, int i, int j);
void Show_ALG_graph(struct ALG_graph *graph);

int main(void)
{
	struct ALG_graph *d_graph;
	d_graph = Create_ALG_graph();
	Show_ALG_graph(d_graph);

	return 0;
}

struct ALG_graph *Create_ALG_graph(void)
{
	int i, j;
	char u, v;

	struct ALG_graph *graph;

	graph = (struct ALG_graph *)malloc(sizeof(struct ALG_graph));

	printf("Please enter the number of vex: ");
	scanf("%d", &graph->vex_num);
	printf("Please enter the number of edge: ");
	scanf("%d", &graph->edge_num);
	while(getchar() != '\n');

	printf("Please enter vertex:\n");
	for(i = 0; i < graph->vex_num; i++)
	{
		graph->Vex[i].node = getchar();
		while(getchar() != '\n');
	}

	for(i = 0; i < graph->vex_num; i++)
	{
		graph->Vex[i].first = NULL;
	}

	while(graph->edge_num--)
	{
		printf("Please enter the vex that connect each other by edge:\n");
		u = getchar();
		while(getchar() != '\n');
		v = getchar();
		while(getchar() != '\n');

		i = search_vex(graph, u);
		j = search_vex(graph, v);

		if(i != -1 && j != -1)
			create_adj_node_list(graph, i, j);
		else
		{
			printf("You have entered wrong vex, please enter again.\n");
			graph->edge_num++;
		}
	}
	return graph;
}

int search_vex(struct ALG_graph *graph, char c)
{
	int i;

	for(i = 0; i < graph->vex_num; i++)
	{
		if(c == graph->Vex[i].node)
			return i;
	}
	return -1;
}

void create_adj_node_list(struct ALG_graph *graph, int i, int j)
{
	struct Adjnode *s = (struct Adjnode *)malloc(sizeof(struct Adjnode));
	s->index = j;
	s->next = graph->Vex[i].first;
	graph->Vex[i].first = s;
}

void Show_ALG_graph(struct ALG_graph *graph)
{
	int i;
	struct Adjnode *t;

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












