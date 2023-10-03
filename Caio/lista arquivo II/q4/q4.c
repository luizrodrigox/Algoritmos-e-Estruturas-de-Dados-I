#include <stdio.h>

int main (){
  char letra, x;
  int cont = 0;
  FILE *arquivotexto;

  arquivotexto = fopen("texto.txt", "r");

  printf("digite a letra: ");
  scanf("%c", &x);

  while (fscanf(arquivotexto, "%c", &letra) != EOF){
    if (letra == x){
      cont = cont + 1;
    }
  }

  printf("quantidade de vezes que a letra '%c' aparece: %d", x, cont);

  return 0;
}