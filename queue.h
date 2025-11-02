#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct Queue
{
    int *q;    // dynamic array to store elements
    int front; // index of front element
    int rear;  // index of last element
} Queue;

Queue *createEmptyQ();
int peek(Queue *q);
void enqueue(Queue *q, int ele);
int dequeue(Queue *q);
int Qsize(Queue *q);
bool isQEmpty(Queue *q);
void freeQueue(Queue *q);
#endif
