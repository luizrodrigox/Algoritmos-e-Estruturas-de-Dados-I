#include <stdio.h>

void troca(int *a,int *b){
  int aux = 0;
  aux = *a;
  *a = *b;
  *b = aux;
}

int main(void){
  int x = 0, y = 0;
  printf("digite dois numeros:\n ");
  scanf("%d %d", &x, &y);
  printf("antes da troca:\n x = %d\n y = %d\n", x, y);
  troca(&x,&y);
  printf("depois da troca:\n x = %d\n y = %d\n", x, y);
  return 0; 
}