#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// =============================
// Queue Structure
// =============================
typedef struct Queue
{
    int *q;    // dynamic array to store elements
    int front; // index of front element
    int rear;  // index of last element
} Queue;

// =============================
// Create an empty queue
// =============================
Queue *createEmptyQ()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->q = NULL;   // No memory yet for elements
    q->front = -1; // empty indicators
    q->rear = -1;
    return q;
}

// =============================
// Check if queue is empty
// =============================
bool isQEmpty(Queue *q)
{
    if (q == NULL)
    {
        printf("Queue not initialized\n");
        exit(1);
    }

    // Empty if never used or front crossed rear
    return (q->front == -1 || q->front > q->rear);
}

// =============================
// View element at front
// =============================
int peek(Queue *q)
{
    if (!isQEmpty(q))
    {
        return q->q[q->front];
    }
    else
    {
        printf("Queue Underflow — nothing to peek\n");
        return -1;
    }
}

// =============================
// Enqueue (add element to end)
// =============================
void enqueue(Queue *q, int ele)
{
    if (isQEmpty(q))
    {
        // first element: allocate array
        q->q = (int *)malloc(sizeof(int));
        q->front = 0;
        q->rear = 0;
        q->q[q->rear] = ele;
    }
    else
    {
        // next element: increase size and append
        q->rear++;
        q->q = (int *)realloc(q->q, (q->rear + 1) * sizeof(int));
        if (!q->q)
        {
            printf("Memory reallocation failed\n");
            exit(1);
        }
        q->q[q->rear] = ele;
    }
}

// =============================
// Dequeue (remove element from front)
// =============================
int dequeue(Queue *q)
{
    if (isQEmpty(q))
    {
        printf("Queue Underflow — cannot dequeue\n");
        return -1;
    }
    else if (q->front == q->rear)
    {
        // only one element left
        int e = q->q[q->front];
        free(q->q);    // free memory
        q->q = NULL;   // set pointer to NULL to avoid dangling
        q->front = -1; // reset indices
        q->rear = -1;
        return e;
    }
    else
    {
        // more than one element
        return q->q[q->front++];
    }
}

// =============================
// Return current queue size
// =============================
int Qsize(Queue *q)
{
    if (isQEmpty(q))
        return 0;
    return q->rear - q->front + 1;
}

// =============================
// Destroy queue (free memory safely)
// =============================
void freeQueue(Queue *q)
{
    if (q)
    {
        free(q->q);
        free(q);
    }
}
