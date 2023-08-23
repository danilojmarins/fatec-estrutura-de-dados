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
 
int main() {
    int discos = 3;

    struct Stack A;
    struct Stack B;
    struct Stack C;

    initialize(&A);
    initialize(&B);
    initialize(&C);

    push(&A, 3);
    push(&A, 2);
    push(&A, 1);

    return 0;
}


// 1 - A B C

// 1 - A C B
// 2 - A B C
// 1 - B A C

// 1 - A B C
// 2 - A C B
// 1 - C A B
// 3 - A B C
// 1 - B C A
// 2 - B A C
// 1 - A B C