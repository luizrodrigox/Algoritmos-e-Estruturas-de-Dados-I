#include <stdio.h>

int main(void){
  int vet[5];
  int *p;
  p = vet;
  printf("digite 5 valores: ");
  for(int i = 0; i < 5; i++){
    scanf("%d", &vet[i]);
  }
  for(int i = 0; i < 5; i++){
    if(vet[i] % 2 == 0){
      printf("\nendereco do conteudo par de vetor: ");
      printf("%x", p);
    }
    p++;
  }
}