#include <stdio.h>

int main()
{
    int vetorA[3] = {2,3,4};
    int vetorB[3] = {5,6,7};
    
    int produtoEscalar = 0;

    for (int i = 0; i < 3; i++)
    {
        produtoEscalar = produtoEscalar + (vetorA[i] * vetorB[i]);
    }

    printf("Produto Escalar: %d \n", produtoEscalar);

    return 0;
}