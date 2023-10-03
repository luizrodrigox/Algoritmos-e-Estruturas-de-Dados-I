#include <stdio.h>

void organiza(int a, int b, int c){
  int aux = 0;
  if(a == b || b == c || a == c){
    printf("\n--NUMEROS IGUAIS FORAM DIGITADOS--\n");
  }
  if(a > b){
    aux = a;
    a = b;
    b = aux;
  }
  if(b > c){
    aux = b;
    b = c;
    c = aux;
  }
  printf("valores organizados:\nx=%d\ny=%d\nz=%d\n", a, b, c);
}

int main(void){
  int x = 0, y = 0, z = 0;
  printf("digite tres valores:\n");
  scanf("%d %d %d", &x, &y, &z);
  printf("antes de organizar:\nx=%d\ny=%d\nz=%d\n", x, y, z);
  organiza(x, y, z);
  return 0;
}