#include <stdio.h>

void maioreqtd (int vetor[9]){
  int max = 0, qtd = 0;
  for(int i = 0; i < 9; i++){
    if(vetor[i] > max){
      max = vetor[i];  
    }
  }
  for(int i = 0; i < 9; i++){
    if(vetor[i] == max){
      qtd++;
    }
  }
  printf("maior numero do vetor: %d\n", max);
  printf("quantidade de vezes encontrado: %d\n", qtd);
}

int main(void){
  int vet[9] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
  maioreqtd(vet);
  return 0;
}