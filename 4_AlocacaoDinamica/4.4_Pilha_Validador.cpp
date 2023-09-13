#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int validar(char expression[], int size)
{
    struct Stack stack;
    initialize(&stack, size);

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

    destroy(&stack);

    return 1;
}

int main() {
    int size = 20;

    char expression[size] = "1 + 1 + 2 + 5";

    if (validar(expression, size))
    {
        printf("Expressão Válida \n");
    }
    else
    {
        printf("Expressão Inválida \n");
    }

    return 0;
}
