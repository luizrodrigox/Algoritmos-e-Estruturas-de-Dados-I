#include <stdio.h>

int main(void){
  int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(int i = 0; i < 10; i++){
    printf("\nendereco do valor %d: %x\n", i+1, &vet[i]);
  }
  return 0;
}