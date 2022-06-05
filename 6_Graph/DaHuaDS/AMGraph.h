#ifndef __AMGRAPH_H__
#define __AMGRAPH_H__

#include <stdio.h>

#define MAXVEX 100
#define INFINITY 65535

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numNodes, numEdges;
}AMGraph;

int visited[MAXVEX];

void CreatAMGraph(AMGraph *G);
void BFS(AMGraph *G);
void DFS(AMGraph *G, int i);
void DFSTraverse(AMGraph *G);

#endif