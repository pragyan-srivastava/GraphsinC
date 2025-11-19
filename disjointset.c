#include <stdio.h>
#include <stdlib.h>
#include "disjointset.h"

int *makeSet(int V)
{
    int *arr = malloc((V + 1) * sizeof(int));
    for (int i = 1; i <= V; i++)
    {
        arr[i] = -1;
    }
    return arr;
}
int findSet(int v, int *arr)
{
    if (arr[v] < 0)
    {
        return v;
    }
    // Path Comression find OR collapsing find
    return arr[v] = findSet(arr[v], arr);
}
void unionSet(int v1, int v2, int *arr)
{
    int p1 = findSet(v1, arr);
    int p2 = findSet(v2, arr);
    if (p1 == p2)
    {
        printf("\nDidn't Union to avoid cycle...\n");
    }
    else
    {
        if (abs(arr[p1]) < abs(arr[p2]))
        {
            // Union by size
            int t = p1;
            p1 = p2;
            p2 = t;
        }

        arr[p1] += arr[p2];
        arr[p2] = p1;
        printf("\nUnion Done(%d,%d)\n", v1, v2);
    }
}

void freeSet(int *arr) {
    free(arr);
}