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

    int iterations = tamanho + (tamanho - 1);
    int total = 0;
    int increment = 0;

    int alternateRowH = 0;
    int alternateRowL = tamanho - 1;

    int alternateColumnH = 0;
    int alternateColumnL = tamanho - 1;

    while (total < tamanhoVetor)
    {
        for (int i = 0; i < iterations; i++)
        {
            if (i % 2 == 0)
            {
                if ((i / 2) % 2 == 0)
                {
                    for (int j = 0 + increment; j < tamanho; j++)
                    {
                        vetorEspiral[total] = matriz[alternateRowH][j];
                        total++;
                    }

                    alternateRowH++;
                }

                if ((i / 2) % 2 == 1)
                {
                    for (int j = (tamanho - 1) - increment; j >= tamanho - (tamanho - increment); j--)
                    {
                        vetorEspiral[total] = matriz[alternateRowL][j];
                        total++;
                    }

                    alternateRowL--;
                }

                increment++;
            }

            if (i % 2 == 1)
            {
                if ((i / 2) % 2 == 0)
                {
                    for (int j = 0 + increment; j < tamanho; j++)
                    {
                        vetorEspiral[total] = matriz[j][alternateColumnL];
                        total++;
                    }

                    alternateColumnL--;
                }

                if ((i / 2) % 2 == 1)
                {
                    for (int j = (tamanho - 1) - increment; j >= tamanho - (tamanho - increment); j--)
                    {
                        vetorEspiral[total] = matriz[j][alternateColumnH];
                        total++;
                    }

                    alternateColumnH++;
                }
            }

        }
    }
    

    for (int a = 0; a < tamanhoVetor; a++)
    {
        printf("%d ", vetorEspiral[a]);
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