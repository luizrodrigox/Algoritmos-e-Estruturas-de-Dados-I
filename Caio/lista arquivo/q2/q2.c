#include <stdio.h>

int main(void){
  char titulo[30];
  char texto[300];
  FILE *arquivo;

  printf("digite o titulo do texto:");
  gets(titulo);

  printf("digite o texto:");
  gets(texto);

  arquivo = fopen(titulo, "w");

  fprintf(arquivo, "%s", texto);

  fclose(arquivo);
  return 0;
}