#include <stdio.h>

void preenche(int *vetor, int a){
  for(int i = 0; i < 5; i++){
    *vetor = a;
    vetor++;
  }
}

int main(void){
  int vet[5] = {3, 56, 21, 8, 77};
  int x = 8;
  printf("\nvetor antes de preencher: \n");
  for(int i = 0; i < 5; i++){
    printf("%d\t", vet[i]);
  }
  preenche(vet, x);
  printf("\nvetor depois de preencher: \n");
  for(int i = 0; i < 5; i++){
    printf("%d\t", vet[i]);
  }
  return 0;
}