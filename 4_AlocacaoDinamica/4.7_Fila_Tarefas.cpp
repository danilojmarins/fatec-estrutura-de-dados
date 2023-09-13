#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int exit = 0;

    struct Queue* tarefas = createQueue();

    int tempo = 0;

    while (!exit)
    {
        int comando;
        int tarefa;

        printf("Digite: \n1: Adicionar Tarefa. \n2: Executar Tarefa. \n3: Sair. \n");
        scanf("%d", &comando);

        switch (comando)
        {
            case 1:
                printf("Digite o tempo em minutos da tarefa: \n");
                scanf("%d", &tarefa);
                if (tempo + tarefa <= 300)
                {
                    enqueue(tarefas, tarefa);
                    tempo = tempo + tarefa;
                }
                else
                {
                    printf("Tarefa ultrapassa o limite de tempo. \n");
                }
                break;
            case 2:
                tarefa = dequeue(tarefas);
                printf("Tarefa de %d minutos executada! \n", tarefa);
                tempo = tempo - tarefa;
                break;
            case 3:
                exit = 1;
            default:
                printf("Comando inválido. \n");
        }

        printf("\nDigite 1 para continuar ou 0 para sair. \n");
        scanf("%d", &comando);

        if (comando == 1)
        {
            exit = 0;
        }
        else if (comando == 0)
        {
            exit = 1;
        }
        else
        {
            printf("Comando inválido. \n");
        }

    }

    freeQueue(tarefas);

    return 0;
}
