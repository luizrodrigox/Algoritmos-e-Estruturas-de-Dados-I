#include <stdio.h>

int main(void){
  float mat[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  float *p;
  p = &mat[0][0];
  for(int i = 0; i < 9; i++){
    printf("endereco %d: %x\n", i+1, p);
    p++;
  }
  return 0;
}