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


int result(char expression[])
{
    struct Stack expStack;
    initialize(&expStack);

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

    return result;
}

 
int main() {
    char expression[MAX_SIZE] = "4 2 5 * + 1 3 2 * + /";

    printf("%d \n", result(expression));

    return 0;
}