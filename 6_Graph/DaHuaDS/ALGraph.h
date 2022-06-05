#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

typedef int VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int index;
    EdgeType w;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *first;
}VexList[MAXVEX];

typedef struct
{
    VexList vexs;
    int numNodes, numEdges;
}ALGraph;

int visited[MAXVEX];

void CreatALGraph(ALGraph *G);
void BFS(ALGraph *G);
void DFS(ALGraph *G, int i);
void DFSTraverse(ALGraph *G);


#endif