#include "1basic.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void DFSLRutil(graphL *graph, int src, int *vis, int *out, int *in)
{
    vis[src] = 1;
    out[*in] = src;
    (*in)++;
    Node *HEAD = graph->adj[src];
    while (HEAD != NULL)
    {
        if (vis[HEAD->name] == 0)
        {
            // printf("\nEntering %d", HEAD->name);
            DFSLRutil(graph, HEAD->name, vis, out, in);
            // printf("\nExiting %d", HEAD->name);
        }
        HEAD = HEAD->next;
    }
}

void DFSLRecursive(graphL *graph, int src)
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
        printf("\n\nSource(L): %d", src);
        DFSLRutil(graph, src, vis, out, &in);
    }
    for (int i = 0; i < in; i++)
    {
        printf(" %d", out[i]);
    }
    free(vis);
    free(out);
}

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
            // printf("\nEntering %d", i);
            DFSMRutil(graph, i, vis, out, in);
            // printf("\nExiting %d", i);
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
        printf("\nSource(M): %d", src);
        DFSMRutil(graph, src, vis, out, &in);
    }
    printf("\nDFS(M):");
    for (int i = 0; i < in; i++)
    {
        printf(" %d", out[i]);
    }
    free(vis);
    free(out);
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
    free(vis);
    freeQueue(qu);
}

void BFSL(graphL *graph, int src)
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
        Node *HEAD = graph->adj[crr];
        while (HEAD != NULL)
        {
            if (vis[HEAD->name] == 0)
            {
                enqueue(qu, HEAD->name);
                vis[HEAD->name] = 1;
            }
            HEAD = HEAD->next;
        }
    }
    free(vis);
    freeQueue(qu);
}
int main()
{
    graphM *graph = constructMatrixDemo1();
    graphL *graph2 = constructListDemo1();

    printf("--- DFS Traversal ---");
    DFSMRecursive(graph, 1);
    DFSLRecursive(graph2, 1);

    printf("\n\n--- BFS Traversal ---");
    printf("\nSource: 4\nBFS (Matrix):");
    BFSM(graph, 4);
    printf("\nBFS (List):  ");
    BFSL(graph2, 4);

    // Free the graphs after use
    // Note: You would need to implement freeGraphM and freeGraphL functions
    // freeGraphM(graph);
    // freeGraphL(graph2);

    printf("\n");
    return 0;
}