#include <stdio.h>

void minmax(int vetor[5], int *minimo, int *maximo){
  for(int i = 0; i < 5; i++){  
    if(*minimo > vetor[i]){
      *minimo = vetor[i];
    }
    if(*maximo < vetor[i]){
      *maximo = vetor[i];
    }
  }
}

int main(void){
  int vet[5] = {1, 15, 11, 5, 20};
  int min = 999, max = 0;
  minmax(vet, &min, &max);
  printf("\nvalor minimo: %d\n valor maximo: %d\n", min, max);
  return 0;
}