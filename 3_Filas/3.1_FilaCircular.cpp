#include <stdio.h>
#define MAX_SIZE 5

// Estrutura de uma fila
struct Queue
{
    int items[MAX_SIZE];    // Elementos da fila
    int front;              // Início da fila
    int rear;               // Final da fila
    int fcounter;           // Contador de voltas do início da fila
    int rcounter;           // Contador de voltas do final da fila
};

// Inicializa uma fila
void initialize(struct Queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
    queue->fcounter = 0;
    queue->rcounter = 0;
}

// Verifica se a fila está vazia
int isEmpty(struct Queue* queue)
{
    return (queue->front > queue->rear && queue->fcounter == queue->rcounter) || queue->front == -1;
}

// Verifica se a fila está cheia
int isFull(struct Queue* queue)
{
    return
    (
        (queue->front > queue->rear && queue->fcounter == queue->rcounter)
        ||
        (queue->front - queue->rear == 1 && queue->fcounter != queue->rcounter)
    );
}

// Adiciona um item à fila
void enqueue(struct Queue* queue, int value)
{
    if (isFull(queue))
    {
        printf("A fila está cheia.");
    }
    else
    {
        queue->rear++;

        if (queue->rear == MAX_SIZE)
        {
            queue->rear = 0;
            queue->rcounter++;
        }

        queue->items[queue->rear] = value;
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
    }
}

// Retira um item da fila
int dequeue(struct Queue* queue)
{
    int item;

    if (isEmpty(queue))
    {
        printf("A fila está vazia.");
        initialize(queue);
        return -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;

        if (queue->front == MAX_SIZE)
        {
            queue->front = 0;
            queue->fcounter++;
        }

        return item;
    }
}

int main()
{
    struct Queue queue;

    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("%d \n", dequeue(&queue));
    printf("%d \n", dequeue(&queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    enqueue(&queue, 70);

    printf("%d \n", dequeue(&queue));
    printf("%d \n", dequeue(&queue));

    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", queue.items[i]);
    }

    printf("\n%d %d \n", queue.front, queue.rear);

    return 0;
}