#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 10

typedef struct
{
    int items[QUEUE_CAPACITY];
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue *q)
{
    if (q->rear == QUEUE_CAPACITY - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }

        return item;
    }
}
int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        return q->items[q->front];
    }
}

int main()
{
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 40);

    printf("Front item: %d\n", peek(queue));

    return 0;
}