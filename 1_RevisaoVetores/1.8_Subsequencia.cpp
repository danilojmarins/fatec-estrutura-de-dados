#include <stdio.h>

int main()
{
    int vetor[5] = {3,10,2,1,20};

    int counter = 0;

    int agreagado = 0;

    printf("Maior subsequência crescente: \n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vetor[j] >= vetor[i] && j >= i)
            {
                printf("%d ", vetor[j]);
            }
        }
        
        if (counter > agreagado)
        {
            agreagado = counter;
        }

        counter = 0;
    }

    printf("%d \n", agreagado);

    return 0;
}