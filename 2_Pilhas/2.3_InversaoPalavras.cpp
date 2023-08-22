#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 30
 

struct Stack {
    char items[MAX_SIZE];
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
void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}
 

// Desempilha um elemento da pilha
char pop(struct Stack *s) {
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
    char expression[MAX_SIZE] = "FATEC";

    //printf("Digite a expressão: ");
    //scanf("%s", expression);

    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(expression); i++)
    {
        push(&stack, expression[i]);
    }

    while (!isEmpty(&stack))
    {
        printf("%c", pop(&stack));
    }

    printf("\n");

    return 0;
}