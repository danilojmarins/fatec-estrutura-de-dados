#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 30
 

struct Stack {
    int items[MAX_SIZE];
    int top;
};
 

// Inicializa a pilha
void initialize(struct Stack *s) {
    s->top = -1;
}
 

// Verifica se a pilha está vazia
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
 

// Verifica se a pilha está cheia
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
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

    initialize(&A);
    initialize(&B);
    initialize(&C);

    for (int i = discos; i > 0; i--)
    {
        push(&A, i);
    }

    hanoi('A', 'C', 'B', discos);

    for (int i = 0; i < discos; i++)
    {
        //printf("%d ", pop(&C));
    }

    return 0;
}