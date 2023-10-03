#include <stdio.h>

int main(void){
  int vet[5];
  int *p;
  p = vet;
  printf("digite cinco valores: ");
  for(int i = 0; i < 5; i++){
    scanf("%d", &vet[i]);
    vet[i] = *p * 2;
    p++;
  }
  printf("\ndobro dos valores digitados: \n");
  for(int i = 0; i < 5; i++){
    printf("%d\t", vet[i]);
  }
  return 0;
}