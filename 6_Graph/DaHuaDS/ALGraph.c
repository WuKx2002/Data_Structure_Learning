#include "ALGraph.h"
#include "Queue.h"

void CreatALGraph(ALGraph *G)
{
    int i, j, k, w;
    EdgeNode *e;
    e = (EdgeNode*)malloc(sizeof(EdgeNode));

    printf("Please enter the number of vertexs and edges : ");
    scanf("%d %d", &G->numNodes, &G->numEdges);
    printf("Please enter the vertexs : ");
    for (i = 0; i < G->numNodes; i++)
    {
        scanf("%d", &G->vexs[i].data);
        //while(getchar() != '\n');
        G->vexs[i].first = NULL;
    }
    printf("Please enter the superscript(i), subscript(j), and weight(w) of the edge :");
    for (k = 0; k < G->numEdges; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        e->index = j;
        e->w =w;
        e->next = G->vexs[i].first;
        G->vexs[i].first = e;
        //If the graph is directed graph, Comment out next three line. 
        e->index = i;
        e->w =w;
        e->next = G->vexs[j].first;
        G->vexs[j].first = e;
    }
}

void BFS(ALGraph *G)
{
    int i;
    EdgeNode *p;

    front = rear = 0;
    for (i = 0; i < G->numNodes; i++)
        visited[i] = 0;
    for (i = 0; i < G->numNodes; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            enQueue(G->vexs[i].data);
            while (!isEmptyQueue())
            {
                printf("%d", deQueue());
                p = G->vexs[i].first;
                while (p)
                {
                    if (!visited[p->index])
                    {
                        visited[p->index] = 1;
                        printf("%d", G->vexs[p->index].data);
                        enQueue(p->index);
                    }
                    p = p->next;
                }
            }
        }
    }
    
}

void DFS(ALGraph *G, int i)
{
    EdgeNode *p;
    visited[i] = 1;
    printf("%c", G->vexs[i].data);
    p = G->vexs[i].first;
    while (p)
    {
        if (!visited[p->index])
            DFS(G, p->index);
        p = p->next;
    }
}

void DFSTraverse(ALGraph *G)
{
    int i;
    for (i = 0; i < G->numNodes; i++)
        visited[i] = 0;
    for (i = 0; i < G->numNodes; i++)
    {
        if (!visited[i])
            DFS(G, i);
    }
}
