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
    int exit = 0;

    Queue tarefas;
    initialize(&tarefas);

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
                    enqueue(&tarefas, tarefa);
                    tempo = tempo + tarefa;
                }
                else
                {
                    printf("Tarefa ultrapassa o limite de tempo. \n");
                }
                break;
            case 2:
                tarefa = dequeue(&tarefas);
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

    return 0;
}