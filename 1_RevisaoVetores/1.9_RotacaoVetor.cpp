#include <stdio.h>

int main()
{
    int tamanho = 5;
    int vetor[tamanho] = {1,2,3,4,5};
    int rotacao = 2;
    int vetorRotacionado[tamanho];

    int index;

    for (int i = 0; i < tamanho; i++)
    {
        int index = i + rotacao;

        if (index > tamanho - 1)
        {
            index = index - tamanho;
        }

        vetorRotacionado[index] = vetor[i];
    }

    printf("Vetor Rotacionado: ");

    for (int j = 0; j < tamanho; j++)
    {
        printf("%d ", vetorRotacionado[j]);
    }

    printf("\n");

    return 0;
}