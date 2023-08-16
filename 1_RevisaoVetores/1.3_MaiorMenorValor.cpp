#include <stdio.h>

int main()
{
    int vetor[5] = {15,8,42,19,30};
    int maior = vetor[0];
    int menor = vetor[0];

    for (int i = 0; i < 5; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }

        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }

    printf("Maior Valor: %d \nMenor Valor: %d \n", maior, menor);

    return 0;
}