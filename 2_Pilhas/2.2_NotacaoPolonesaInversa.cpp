#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
 

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
void push(struct Stack *s, int value) {
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
        return 'e';
    } else {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}


int result(char expression[])
{
    struct Stack expStack;
    initialize(&expStack);

    int result;

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i]  == '+')
        {
            push(&expStack, pop(&expStack) + pop(&expStack));
        }
        else if (expression[i]  == '-')
        {
            push(&expStack, pop(&expStack) - pop(&expStack));
        }
        else if (expression[i]  == '*')
        {
            push(&expStack, pop(&expStack) * pop(&expStack));
        }
        else if (expression[i]  == '/')
        {
            push(&expStack, pop(&expStack) / pop(&expStack));
        }
    }

    result = atoi(expression);

    return result;
}

 
int main() {
    char expression[MAX_SIZE];

    printf("Digite a expressão: ");
    scanf("%s", expression);

    printf("%d \n", result(expression));

    return 0;
}