#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *items;
    int top;
    int max_size;
};

// Inicializa a pilha
void initialize(struct Stack *s, int size) {
    s->max_size = size;
    s->items = (int *)malloc(size * sizeof(int));
    s->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *s) {
    return s->top == s->max_size - 1;
}

// Empilha um elemento na pilha
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

// Desempilha um elemento da pilha
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    } else {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

// Libera a memória alocada pela pilha
void destroy(struct Stack *s) {
    free(s->items);
}

void hanoi(char inicio, char alvo,  char auxiliar, int valor)
{
    if (valor >= 1)
    {
        hanoi(inicio, auxiliar, alvo, valor - 1);
        
        //push(alvo, pop(inicio));
        printf("de %c para %c \n", inicio, alvo);

        hanoi(auxiliar, alvo, inicio, valor - 1);
    }
    else
    {
        return;
    }
}

int main() {
    int discos = 3;

    struct Stack A;
    struct Stack B;
    struct Stack C;

    initialize(&A, discos);
    initialize(&B, discos);
    initialize(&C, discos);

    for (int i = discos; i > 0; i--)
    {
        push(&A, i);
    }

    hanoi('A', 'C', 'B', discos);

    for (int i = 0; i < discos; i++)
    {
        //printf("%d ", pop(&C));
    }

    destroy(&A);
    destroy(&B);
    destroy(&C);

    return 0;
}
