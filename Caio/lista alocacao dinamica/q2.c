#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, *vet;
  printf("digite o tamanho do vetor: ");
  scanf("%d", &n);
  vet = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++){
    vet[i] = i;
  }
  printf("primeiro valor: %d\n", vet[0]);
  printf("segundo valor: %d\n", vet[1]);
  printf("penultimo valor: %d\n", vet[n-2]);
  printf("ultimo valor: %d\n", vet[n-1]);
  free(vet);
  return 0;
}