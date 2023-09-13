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

int expressionIsBalanced(char expression[], int size)
{
    struct Stack expStack;
    initialize(&expStack, size);

    int balanced = 1;

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&expStack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (pop(&expStack) == '(')
            {
                balanced = 1;
            }
            else
            {
                balanced = 0;
            }
        }
        else if (expression[i] == ']')
        {
            if (pop(&expStack) == '[')
            {
                balanced = 1;
            }
            else
            {
                balanced = 0;
            }
        }
        else if (expression[i] == '}')
        {
            if (pop(&expStack) == '{')
            {
                balanced = 1;
            }
            else
            {
                balanced = 0;
            }
        }

        if (balanced == 0) return balanced;
    }

    destroy(&expStack);

    return balanced;
}

int main() {
    int expressionSize = 10;

    char expression[expressionSize] = "({[]})";

    if (expressionIsBalanced(expression, expressionSize))
    {
        printf("balanceado \n");
    }
    else
    {
        printf("desbalanceado \n");
    }

    return 0;
}