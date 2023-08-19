#include <stdio.h>

int main()
{
    int tamanho = 5;
    int matriz[tamanho][tamanho];
    int valor = 1;

    int tamanhoVetor = tamanho * tamanho;
    int vetorEspiral[tamanhoVetor];

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            matriz[i][j] = valor;
            valor++;
        }
    }

    int iterations = tamanho + (tamanho - 1);
    int index = 0;

    int incrementCB = 0;
    int incrementCA = 0;
    int incrementLA = 0;
    int incrementLB = 0;

    int alternateRowH = 0;
    int alternateRowL = tamanho - 1;

    int alternateColumnH = 0;
    int alternateColumnL = tamanho - 1;

    while (index < tamanhoVetor)
    {
        for (int it = 0; it < iterations; it++)
        {
            if (it % 2 == 0)
            {
                if ((it / 2) % 2 == 0)
                {
                    for (int la = incrementCA; la < tamanho - incrementCB; la++) // Linha Crescente
                    {
                        vetorEspiral[index] = matriz[alternateRowH][la];
                        index++;
                    }

                    alternateRowH++;
                    incrementLA++;
                }

                if ((it / 2) % 2 == 1)
                {
                    for (int lb = tamanho - 1 - incrementCA; lb >= incrementCB; lb--) // Linha Decrescente
                    {
                        vetorEspiral[index] = matriz[alternateRowL][lb];
                        index++;
                    }

                    alternateRowL--;
                    incrementLB++;
                }
            }

            if (it % 2 == 1)
            {
                if ((it / 2) % 2 == 0)
                {
                    for (int ca = incrementLA; ca < tamanho - incrementLB; ca++) // Coluna Crescente
                    {
                        vetorEspiral[index] = matriz[ca][alternateColumnL];
                        index++;
                    }

                    alternateColumnL--;
                    incrementCA++;
                }

                if ((it / 2) % 2 == 1)
                {

                    for (int cb = tamanho - 1 - incrementLB; cb >= incrementLA; cb--) // Coluna Decrescente
                    {
                        vetorEspiral[index] = matriz[cb][alternateColumnH];
                        index++;
                    }

                    alternateColumnH++;
                    incrementCB++;
                }
            }
        }
    }

    for (int k = 0; k < tamanhoVetor; k++)
    {
        printf("%d ", vetorEspiral[k]);   
    }

    printf("\n");
    
    return 0;
}