#include <stdio.h>
#include <stdlib.h> // For free()
#include "disjointset.h"

// Helper function to print the DSU array for visualization
void printArr(int *arr, int n)
{
    printf("\n\n-------DS-------\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n-------DS-------\n\n");
}

int main()
{
    int n = 5;
    int *arr = makeSet(n);
    printArr(arr, n);
    printf("Parent of %d:%d\n", 5, findSet(5, arr));
    printf("Parent of %d:%d\n", 2, findSet(2, arr));
    printf("Parent of %d:%d\n", 3, findSet(3, arr));
    printf("Parent of %d:%d\n", 1, findSet(1, arr));
    unionSet(2, 3, arr);
    printArr(arr, n);
    printf("Parent of %d:%d\n", 3, findSet(3, arr));
    unionSet(3, 2, arr);
    printArr(arr, n);
    unionSet(2, 3, arr);
    printArr(arr, n);
    unionSet(1, 5, arr);
    printArr(arr, n);
    printf("Parent of %d:%d\n", 1, findSet(1, arr));
    printf("Parent of %d:%d\n", 5, findSet(5, arr));
    unionSet(1, 4, arr);
    printArr(arr, n);
    printf("Parent of %d:%d\n", 1, findSet(1, arr));
    printf("Parent of %d:%d\n", 4, findSet(4, arr));
    unionSet(2, 4, arr);
    printf("\nUnion by size\n");
    printArr(arr, n);
    printf("Parent of %d:%d\n", 1, findSet(1, arr));
    printArr(arr, n);
    printf("Parent of %d:%d\n", 2, findSet(2, arr));
    printArr(arr, n);
    printf("Parent of %d:%d\n", 3, findSet(3, arr));
    printf("\nPath Compression Find\n");
    printArr(arr, n);
    printf("Parent of %d:%d\n", 4, findSet(4, arr));
    printArr(arr, n);

    // Free the allocated memory
    freeSet(arr);

    return 0;
}
