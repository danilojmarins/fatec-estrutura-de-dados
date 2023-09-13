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

int result(char expression[], int size)
{
    struct Stack expStack;
    initialize(&expStack, size);

	char str[30] = "";
    int result;

    int primeiro;
    int segundo;

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i]  == '+')
        {
            segundo = pop(&expStack);
            primeiro = pop(&expStack);

            push(&expStack, primeiro + segundo);
        }
        else if (expression[i]  == '-')
        {
            segundo = pop(&expStack);
            primeiro = pop(&expStack);

            push(&expStack, primeiro - segundo);
        }
        else if (expression[i]  == '*')
        {
            segundo = pop(&expStack);
            primeiro = pop(&expStack);

            push(&expStack, primeiro * segundo);
        }
        else if (expression[i]  == '/')
        {
            segundo = pop(&expStack);
            primeiro = pop(&expStack);

            push(&expStack, primeiro / segundo);
        }
        else if (expression[i] == ' ')
        {
        	str[0] = '\0';
		}
		else
		{
			strncat(str, &expression[i], 1);
			
			if (expression[i + 1] == ' ')
			{
				push(&expStack, atoi(str));
			}
		}
    }
    
    result = pop(&expStack);

    destroy(&expStack);

    return result;
}

int main() {
    int expressionSize = 20;

    char expression[expressionSize] = "4 2 5 * + 1 3 2 * + /";

    printf("%d \n", result(expression, expressionSize));

    return 0;
}
