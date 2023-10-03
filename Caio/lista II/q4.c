#include <stdio.h>

int soma(int *a, int *b){
  *a = *a * 2;
  *b = *b * 2;
  return *a + *b;
}

int main(void){
  int A = 2, B = 3;
  soma(&A, &B);
  printf("a soma do dobro: %d", A + B);
}