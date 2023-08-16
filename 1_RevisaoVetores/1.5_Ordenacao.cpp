#include <stdio.h>

int main()
{
    int vetor[5] = {7,3,9,1,5};
    int valorTemporario;

    printf("Valor Ordenado: ");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((vetor[j] < vetor[i]) && (j > i))
            {
                valorTemporario = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = valorTemporario;
            }
        }

        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}