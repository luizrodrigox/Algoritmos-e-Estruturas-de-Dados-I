#include <stdio.h>
#include <stdlib.h>

int main (void){
    int i,j;
    // alocando a matriz dinamicamente.
    int **matriz = (int **) malloc(3 * sizeof(int *));
    for ( i = 0; i < 3; i++)
    {
        matriz[i] = (int *) malloc(3 * sizeof(int));
    }
    // verificando se a alocação dinâmica foi bem sucedida.
    if (matriz == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    //preenchendo a matriz.
    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            matriz[i][j] = i*3 + j;
        }
    }
    //exibindo a matriz.
    printf("Minha matriz: \n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ",matriz[i][j]);
        }
        printf("\n");
    }
    free(matriz); //liberando a memoria.
    return 0;
}