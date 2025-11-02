#include "1basic.h"
#include "1basic.c"
#include <stdio.h>
#include <stdlib.h>
void DFSutil(graphM *graph, int src, int *vis, int *out, int *in)
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
            DFSutil(graph, i, vis, out, in);
            printf("\nExiting %d", i);
        }
    }
}

void DFS(graphM *graph, int src)
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
        DFSutil(graph, src, vis, out, &in);
    }
    printf("\n\nDFS:");
    for (int i = 0; i < in; i++)
    {
        printf(" %d", out[i]);
    }
}

int main()
{
    graphM *graph = constructMatrixDemo1();
    DFS(graph, 1);
}