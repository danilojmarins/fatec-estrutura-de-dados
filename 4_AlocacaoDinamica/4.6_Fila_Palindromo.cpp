#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um nó da fila
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para a fila
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Função para criar uma nova fila vazia
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        perror("Erro na alocação de memória para a fila");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para enfileirar um elemento
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Função para desenfileirar um elemento
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Fila vazia\n");
        return -1; // Valor sentinela para indicar fila vazia
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Função para liberar a memória da fila
void freeQueue(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int isPalindrome(char word[])
{
    struct Queue* wordQueue = createQueue();
    struct Queue* wordReverseQueue = createQueue();

    int result = 1;

    for (int i = 0; i < strlen(word); i++)
    {
        enqueue(wordQueue, word[i]);
    }

    for (int j = strlen(word) - 1; j >= 0; j--)
    {
        enqueue(wordReverseQueue, word[j]);
    }

    while (wordQueue->front != NULL)
    {
        if(dequeue(wordQueue) != dequeue(wordReverseQueue))
        {
            result = 0;
        }
    }

    freeQueue(wordQueue);
    freeQueue(wordReverseQueue);
    
    return result;
}

int main() {
    char word[10] = "ovo";

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
