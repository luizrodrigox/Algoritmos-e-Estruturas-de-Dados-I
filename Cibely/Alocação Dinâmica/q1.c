#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *vetor = (int *) malloc(10 * sizeof(int)); //alocando vetor dinamicamente.
    int i;
    if (vetor == NULL) //verificando se a alocação dinamica foi bem sucedida.
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    for (i = 0; i < 10; i++) //preenchendo o vetor.
    {
        vetor[i] = i;
    }
    printf("vetor: ");
    for (i = 0; i < 10; i++) //exibindo o vetor.
    {
        printf("%d  ", vetor[i]);
    }
    free(vetor); //liberando a memoria.
    return 0;
}