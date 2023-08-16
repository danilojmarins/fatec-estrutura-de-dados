#include <stdio.h>

int main()
{
    int vetor[5] = {1,2,3,4,5};
    int rotacao = 3;

    for (int i = 0; i < rotacao; i++)
    {
        int temp = vetor[i];
        vetor[i] = vetor[5 - rotacao + i];
        vetor[5 - i -1] = temp;
    }

    for (int j = 0; j < 5; j++)
    {
        printf("%d ", vetor[j]);
    }

    return 0;
}