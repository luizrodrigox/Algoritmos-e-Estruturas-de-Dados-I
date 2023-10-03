#include <stdio.h>
#include <stdlib.h>

int main(void){
  int tam, *vet;
  int contp = 0, conti = 0;
  printf("digite o tamanho do vetor: ");
  scanf("%d", &tam);
  vet = (int*)malloc(tam * sizeof(int));
  printf("digite os valores: ");
  for(int i = 0; i < tam; i++){
    scanf("%d", &vet[i]);
    if(vet[i] % 2 == 0){
      contp++;
    }
    else{
      conti++;
    }
  }
  printf("\nvalores do vetor: ");
  for(int i = 0; i < tam; i++){
    printf("%d\t", vet[i]);
  }
  printf("\ntotal de valores pares: %d", contp);
  printf("\ntotal de valores impares: %d", conti);
  free(vet);
  return 0;
}