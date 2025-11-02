#ifndef BASIC1_H
#define BASIC1_H

typedef struct graphM
{
    int **mat;
    int vertices;
} graphM;

typedef struct Node
{
    int name;
    int weight;
    struct Node *next;
} Node;

typedef struct graphL
{
    int vertices;
    struct Node **adj;

} graphL;

// Function prototypes
graphM *createGraphM(int);
graphL *createGraphL(int);
void addUndirectedEdgeM(graphM *, int, int, int, int);
void adddirectedEdgeM(graphM *, int, int, int, int);
void addUndirectedEdgeL(graphL *, int, int, int, int);
void adddirectedEdgeL(graphL *, int, int, int, int);
void removeEdgeM(graphM *, int, int);
void removeEdgeL(graphL *, int, int);
void printMatrixGraph(graphM *);
void printListGraph(graphL *);

graphL *constructListDemo1();
graphM *constructMatrixDemo1();
#endif
