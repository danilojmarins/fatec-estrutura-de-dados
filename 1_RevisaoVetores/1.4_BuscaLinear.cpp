#include <stdio.h>

int main()
{
    int vetor[5] = {25,12,8,36,42};
    int alvo = 8;

    for (int i = 0; i < 5; i++)
    {
        if (vetor[i] == alvo)
        {
            return printf("Valor %d encontrado na posição %d. \n", alvo, i);
        }
    }

    printf("Valor não encontrado. \n");

    return 0;
}