#include <stdio.h>
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
        return "";
    } else {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

 

int expressionIsBalanced(char expression[])
{
    struct Stack expStack;
    initialize(&expStack);

    int balanced;

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == "(" || expression[i] == "[" || expression[i] == "{")
        {
            push(&expStack, expression[i]);
        }
        else if (expression[i] == ")")
        {
            if (pop(&expStack) == "(")
                balanced = 1;
            else balanced = 0;
        }
        else if (expression[i] == "]")
        {
            if (pop(&expStack) == "(")
                balanced = 1;
            else balanced = 0;
        }
        else if (expression[i] == "}")
        {
            if (pop(&expStack) == "(")
                balanced = 1;
            else balanced = 0;
        }

        if (balanced == 0) return balanced;
    }

    return balanced;
}

 

int main() {
    char expression[30];

    printf("Digite a expressão: ");
    scanf("%s", expression);

 

    if (expressionIsBalanced(expression))
    {
        printf("balanceado");
    }
    else
    {
        printf("desbalanceado");
    }

 

    return 0;
}