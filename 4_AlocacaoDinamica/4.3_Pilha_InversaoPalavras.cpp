#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char *items;
    int top;
    int max_size;
};

// Inicializa a pilha
void initialize(struct Stack *s, int size) {
    s->max_size = size;
    s->items = (char *)malloc(size * sizeof(char));
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

int main() {
    int size = 10;
    char word[size] = "FATEC";

    Stack stack;

    initialize(&stack, size);

    for (int i = 0; i < strlen(word); i++)
    {
        push(&stack, word[i]);
    }

    while (!isEmpty(&stack))
    {
        printf("%c", pop(&stack));
    }

    printf("\n");

    destroy(&stack);

    return 0;
}
