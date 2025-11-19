// #include "queue.h"
#include "queue.c"
#include <stdio.h>

int main()
{
    Queue *q = createEmptyQ();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Front element: %d\n", peek(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    enqueue(q, 50);

    printf("\nQueue elements left (%d):\n", Qsize(q));
    while (!isQEmpty(q))
    {
        printf("%d ", dequeue(q));
    }

    freeQueue(q);
    return 0;
}
