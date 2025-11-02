#include "1basic.h"
#include "1basic.c"
#include "queue.c"
#include <stdio.h>
#include <stdlib.h>

void DFSMRutil(graphM *graph, int src, int *vis, int *out, int *in)
{
    vis[src] = 1;
    // printf("---> %d", src);
    out[*in] = src;
    (*in)++;

    for (int i = 1; i <= graph->vertices; i++)
    {
        if (graph->mat[src][i] != 0 && vis[i] == 0)
        {
            printf("\nEntering %d", i);
            DFSMRutil(graph, i, vis, out, in);
            printf("\nExiting %d", i);
        }
    }
}

void DFSMRecursive(graphM *graph, int src)
{
    int in = 0;
    int *vis = (int *)malloc((graph->vertices + 1) * sizeof(int));
    int *out = (int *)malloc((graph->vertices) * sizeof(int));
    if (graph->vertices < src || src < 1)
    {
        return;
    }
    else
    {
        for (int i = 0; i <= graph->vertices; i++)
        {
            vis[i] = 0;
        }
        printf("\nSource: %d", src);
        DFSMRutil(graph, src, vis, out, &in);
    }
    printf("\n\nDFS:");
    for (int i = 0; i < in; i++)
    {
        printf(" %d", out[i]);
    }
}

void BFSM(graphM *graph, int src)
{
    Queue *qu = createEmptyQ();
    int *vis = (int *)malloc((graph->vertices + 1) * sizeof(int));
    for (int i = 0; i <= graph->vertices; i++)
    {
        vis[i] = 0;
    }

    enqueue(qu, src);
    vis[src] = 1;
    while (!isQEmpty(qu))
    {
        int crr = dequeue(qu);
        printf(" %d", crr);
        for (int i = 1; i <= graph->vertices; i++)
        {
            if (graph->mat[crr][i] != 0 && vis[i] == 0)
            {
                vis[i] = 1;
                enqueue(qu, i);
            }
        }
    }
}
int main()
{
    graphM *graph = constructMatrixDemo1();
    DFSMRecursive(graph, 1);
    printf("\nBFS:");
    BFSM(graph, 4);
}