#include <stdio.h>

void somaarray(int *vetora, int *vetorb, int *vetorc){
  for(int i = 0; i < 5; i++){
    *vetorc = *vetora + *vetorb;
    vetora++;
    vetorc++;
    vetorb++;
  }
}

int main(void){
  int veta[5] = {1, 2, 3, 4, 5};
  int vetb[5] = {1, 2, 3, 4, 5};
  int vetc[5] = {0};
  somaarray(veta, vetb, vetc);
  printf("soma dos dois vetores: \n");
  for(int i = 0; i < 5; i++){
    printf("%d\t", vetc[i]);
  }
  return 0;
}