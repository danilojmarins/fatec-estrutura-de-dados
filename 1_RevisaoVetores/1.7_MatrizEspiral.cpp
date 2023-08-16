#include <stdio.h>

int main()
{
    int tamanho = 5;
    int matriz[tamanho][tamanho];
    int inicio = 1;

    int tamanhoVetor = tamanho * tamanho;
    int vetorEspiral[tamanhoVetor];

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            matriz[i][j] = inicio;
            inicio++;
        }
    }

    printf("%d \n", matriz[4][4]);

    int linha = 0;
    int coluna = 0;

    int total = tamanhoVetor;

    while (total > 0)
    {
        if (total > tamanhoVetor - tamanho)
        {
            for (int j = 0; j < tamanho; j++)
            {
                vetorEspiral[tamanhoVetor - total] = matriz[0][j];
                total--;
            }
        }
    }

//    [0][0]
//    [0][1]
//    [0][2]
//    [0][3]
//    [0][4]
//
//    [1][4]
//    [2][4]
//    [3][4]
//    [4][4]
//
//    [4][3]
//    [4][2]
//    [4][1]
//    [4][0]
//
//    [3][0]
//    [2][0]
//    [1][0]
//
//    [1][1]
//    [1][2]
//    [1][3]
//
//    [2][3]
//    [3][3]
//
//    [3][2]
//    [3][1]
//
//    [2][1]
//    [2][3]
    
    return 0;
}