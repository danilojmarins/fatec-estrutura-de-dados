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


int validar(char expression[])
{
    struct Stack stack;
    initialize(&stack);

    char str[30] = "";
    int result;

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            result = pop(&stack);
        }
        else if (expression[i] == ' ')
        {
            str[0] = '\0';
        }
        else
        {
            strncat(str, &expression[i], 1);
			
			if (expression[i + 1] == ' ' || i + 1 == strlen(expression))
			{
				push(&stack, atoi(str));
			}
        }

        if (result == -1 || stack.top == 1)
        {
            return 0;
        }
    }

    return 1;
}

 
int main() {
    char expression[MAX_SIZE] = "+ 1 + 2 + 5";

    if (validar(expression))
    {
        printf("Expressão Válida \n");
    }
    else
    {
        printf("Expressão Inválida \n");
    }

    return 0;
}