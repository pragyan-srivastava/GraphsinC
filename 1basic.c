#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "1basic.h"

struct graphM *createMatrixGraph(int v)
{
    graphM *graphptr = (graphM *)malloc(sizeof(graphM));
    if (graphptr == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    graphptr->vertices = v;
    graphptr->mat = (int **)malloc((graphptr->vertices + 1) * sizeof(int *));
    if (graphptr->mat == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i <= graphptr->vertices; i++)
    {
        graphptr->mat[i] = (int *)malloc((graphptr->vertices + 1) * sizeof(int));
        if (graphptr->mat[i] == NULL)
        {
            printf("Memory Allocation Failed");
            exit(1);
        }
        for (int j = 0; j <= graphptr->vertices; j++)
        {
            if (i == 0 && j == 0)
                graphptr->mat[i][j] = 0;
            else if (i == 0)
                graphptr->mat[i][j] = j;
            else if (j == 0)
                graphptr->mat[i][j] = i;
            else
                graphptr->mat[i][j] = 0;
        }
    }

    return graphptr;
}
void printMatrixGraph(struct graphM *graph)
{

    for (int i = 0; i < graph->vertices + 1; i++)
    {
        if (i == 1)
        {
            printf("\n");
        }
        for (int j = 0; j < graph->vertices + 1; j++)
        {
            if (j == 1)
                printf("   ");
            printf("  %d ", graph->mat[i][j]);
        }
        printf("\n\n");
    }
}

void addUndirectedEdgesM(graphM *graph, int src, int destn, int weight)
{
    // if(graph.mat[src][destn]!=0 || graph.mat[destn][src]!=0){
    //     printf("Overridden");
    // }
    // else{
    //     printf("Added Edge");
    // }
    graph->mat[src][destn] = weight;
    graph->mat[destn][src] = weight;
}

void addDirectedEdgesM(graphM *graph, int src, int destn, int weight)
{
    // if(graph.mat[src][destn]!=0){
    //     printf("Overridden");
    // }
    // else{
    //     printf("Added Edge");
    // }
    graph->mat[src][destn] = weight;
}
void removeEdgeM(graphM *graph, int src, int destn)
{
    graph->mat[src][destn] = 0;
}

struct graphL *createListGraph(int v)
{
    graphL *graphptr = (graphL *)malloc(sizeof(graphL));
    if (graphptr == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    graphptr->vertices = v;
    graphptr->adj = (Node **)malloc((graphptr->vertices + 1) * sizeof(Node *));
    if (graphptr->adj == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < graphptr->vertices + 1; i++)
    {
        graphptr->adj[i] = NULL;
    }
    return graphptr;
}

void addUndirectedEdgesL(graphL *graph, int src, int destn, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->name = destn;
    newNode->weight = weight;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    Node *revNode = (Node *)malloc(sizeof(Node));
    revNode->name = src;
    revNode->weight = weight;
    revNode->next = graph->adj[destn];
    graph->adj[destn] = revNode;
}

void addDirectedEdgesL(graphL *graph, int src, int destn, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->name = destn;
    newNode->weight = weight;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

void removeEdgeL(graphL *graph, int src, int destn)
{
    Node *temp = graph->adj[src];
    if (temp->name == destn)
    {
        graph->adj[src] = temp->next;
        free(temp);
    }
    else
    {
        Node *slo = graph->adj[src];
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->name == destn)
            {
                slo->next = temp->next;
                free(temp);
            }
            temp = temp->next;
            slo = slo->next;
        }
    }
}
void printListGraph(graphL *graph)
{
    for (int i = 1; i <= graph->vertices; i++)
    {
        printf("\n%d:", i);
        Node *HEAD = graph->adj[i];
        while (HEAD != NULL)
        {
            printf(" (%d,%d)", HEAD->name, HEAD->weight);
            HEAD = HEAD->next;
        }
    }
}
graphM *constructMatrixDemo1()
{
    struct graphM *graph1 = createMatrixGraph(6);
    addUndirectedEdgesM(graph1, 1, 2, 5);
    addUndirectedEdgesM(graph1, 1, 3, 10);
    addUndirectedEdgesM(graph1, 2, 3, 8);
    addUndirectedEdgesM(graph1, 2, 4, 6);
    addUndirectedEdgesM(graph1, 3, 5, 7);
    addUndirectedEdgesM(graph1, 4, 5, 10);
    addUndirectedEdgesM(graph1, 4, 6, 2);
    addUndirectedEdgesM(graph1, 5, 6, 4);

    addDirectedEdgesM(graph1, 2, 5, 2);

    removeEdgeM(graph1, 2, 5);
    return graph1;
}

graphL *constructListDemo1()
{
    graphL *graph2 = createListGraph(6);
    addUndirectedEdgesL(graph2, 1, 2, 5);
    addUndirectedEdgesL(graph2, 1, 3, 10);
    addUndirectedEdgesL(graph2, 2, 3, 8);
    addUndirectedEdgesL(graph2, 2, 4, 6);
    addUndirectedEdgesL(graph2, 3, 5, 7);
    addUndirectedEdgesL(graph2, 4, 5, 10);
    addUndirectedEdgesL(graph2, 4, 6, 2);
    addUndirectedEdgesL(graph2, 5, 6, 4);

    addDirectedEdgesL(graph2, 2, 5, 2);

    removeEdgeL(graph2, 2, 5);
    return graph2;
}
