#ifndef DISJOINTSET_H
#define DISJOINTSET_H

// Creates and initializes a Disjoint Set structure for V vertices.
// Returns a pointer to the dynamically allocated integer array.
int *makeSet(int V);

// Finds the representative (root) of the set containing vertex v.
// Implements path compression.
int findSet(int v, int *arr);

// Merges the sets containing vertices v1 and v2.
// Implements union by size.
void unionSet(int v1, int v2, int *arr);

// Frees the memory allocated for the Disjoint Set array.
void freeSet(int *arr);

#endif // DISJOINTSET_H
