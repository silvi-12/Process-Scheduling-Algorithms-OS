#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(Queue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->data[queue->rear] = item;
}

// Function to display the elements of the queue
void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nGantt Chart:\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("   P%d   |", queue->data[i]);
    printf("\n");
}

void tdisplayTime(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("0        ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d       ", queue->data[i]);
    printf("\n");
}

void displayTime(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    // printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf(" %d   ", queue->data[i]);
    printf("\n");
}
