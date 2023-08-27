#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

struct Queue
{
    char items[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == -1 || queue->front > queue->rear;
}

int isFull(struct Queue* queue)
{
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(struct Queue* queue, char value)
{
    if (isEmpty(queue))
    {
        queue->front = 0;
    }

    if (isFull(queue))
    {
        printf("A fila está cheia. \n");
    }
    else
    {
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

char dequeue(struct Queue* queue)
{
    int item;

    if (isEmpty(queue))
    {
        printf("A fila está vazia. \n");
        return -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        return item;
    }
}

int isPalindrome(char word[])
{
    struct Queue wordQueue;
    struct Queue wordReverseQueue;
    initialize(&wordQueue);
    initialize(&wordReverseQueue);

    int result = 1;

    for (int i = 0; i < strlen(word); i++)
    {
        enqueue(&wordQueue, word[i]);
    }

    for (int j = strlen(word) - 1; j >= 0; j--)
    {
        enqueue(&wordReverseQueue, word[j]);
    }

    while (!isEmpty(&wordQueue))
    {
        if(dequeue(&wordQueue) != dequeue(&wordReverseQueue))
        {
            result = 0;
        }
    }
    
    return result;
}

int main()
{
    char word[MAX_SIZE] = "ovo";

    if (isPalindrome(word))
    {
        printf("A palavra %s é palíndromo. \n", word);
    }
    else
    {
        printf("A palavra %s não é palíndromo. \n", word);
    }

    return 0;
}