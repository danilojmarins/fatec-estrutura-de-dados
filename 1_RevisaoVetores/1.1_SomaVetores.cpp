#include <stdio.h>

int main()
{
    int A[3] = {1,2,3};
    int B[3] = {4,5,6};

    int soma[3];

    printf("Vetor Soma: ");

    for (int i = 0; i < 3; i++)
    {
        soma[i] = A[i] + B[i];

        printf("%d ", soma[i]);
    }

    printf("\n");

    return 0;
}