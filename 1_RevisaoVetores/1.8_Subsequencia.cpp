#include <stdio.h>

int main()
{
    int tamanho = 5;
    int vetor[tamanho] = {3,10,2,1,20};

    int counter = 0;
    int agregado = 0;

    int counterVetor[tamanho];
    int agregadoVetor[tamanho];

    printf("Maior Subsequência Crescente: ");

    for (int i = 0; i < tamanho; i++)
    {
        counterVetor[counter] = vetor[i];
        counter++;

        for (int j = 0; j < tamanho; j++)
        {
            if (vetor[j] > vetor[i] && j >= i)
            {
                counterVetor[counter] = vetor[j];
                counter++;
            }
        }

        if (counter > agregado)
        {
            agregado = counter;
            
            for (int l = 0; l < tamanho; l++)
            {
                agregadoVetor[l] = counterVetor[l]; 
                counterVetor[l] = 0;
            }
        }

        counter = 0;
    }

    for (int k = 0; k < agregado; k++)
    {
        printf("%d ", agregadoVetor[k]);
    }

    printf("\n");

    return 0;
}