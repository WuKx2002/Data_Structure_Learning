#include "ALGraph.h"
#include <stdlib.h>

int main(void)
{
    ALGraph *G;
    G = (ALGraph*)malloc(sizeof(ALGraph));
    CreatALGraph(G);

    BFS(G);


    return 0;
}