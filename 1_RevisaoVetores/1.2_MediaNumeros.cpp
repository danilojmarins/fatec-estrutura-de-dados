#include <stdio.h>

int main()
{
    int vetor[5] = {10,20,30,40,50};
    int soma = 0;

    for (int i = 0; i < 5; i++)
    {
        soma = soma + vetor[i];
    }

    int media = soma / 5;

    printf("Média: %d \n", media);

    return 0;
}