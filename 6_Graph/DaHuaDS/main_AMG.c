#include "AMGraph.h"
#include <stdlib.h>

int main(void)
{
    /*ALGraph *G;
    G = (ALGraph*)malloc(sizeof(ALGraph));
    CreatALGraph(G);*/
    AMGraph *G;
    G = (AMGraph*)malloc(sizeof(AMGraph));
    CreatAMGraph(G);

    BFS(G);


    return 0;
}