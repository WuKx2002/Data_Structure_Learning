#include "AMGraph.h"
#include "Queue.h"

void CreatAMGraph(AMGraph *G)
{
    int i, j, k;
    int w;  //weight

    printf("Please enter the number of vertexs and edges : ");
    scanf("%d %d", &G->numNodes, &G->numEdges);
    printf("Please enter the vertexs : ");
    for (i = 0; i < G->numNodes; i++)
    {
        scanf("%d", &G->vexs[i]);
        //while(getchar() != '\n');
    }     
    for (i = 0; i < G->numNodes; i++)
        for (j = 0; j < G->numNodes; j++)
            G->arc[i][j] = INFINITY;
    printf("Please enter the superscript(i), subscript(j), and weight(w) of the edge :");
    for (k = 0; k < G->numEdges; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        G->arc[i][j] = w;
        //If the graph is directed graph, Comment out next line. 
        G->arc[j][i] = G->arc[i][j]; 
    }
}

void BFS(AMGraph *G)
{
    int i, j;
    int visited[MAXVEX];
    
    front = rear = 0;
    for (i = 0; i < G->numNodes; i++)
        visited[i] = 0;
    for (i = 0; i < G->numNodes; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            enQueue(G->vexs[i]);
            while (!isEmptyQueue())
            {
                printf("%d", deQueue());
                for (j = 0; j < G->numNodes; j++)
                {
                    if (G->arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = 1;
                        enQueue(G->vexs[j]);
                    }
                }
            }
        }
    }
}