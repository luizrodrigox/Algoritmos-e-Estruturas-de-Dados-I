#include <stdio.h>

int main(void){
  char nome[50];
  int dia, mes, ano, anoatual, idade;
  FILE *arquivo;

  printf("digite o ano atual:");
  scanf("%d", &anoatual);

  arquivo = fopen("pessoas.txt", "r");

  while (fscanf(arquivo, "%s %d %d %d", nome, &dia, &mes, &ano) != EOF){
    idade = 0;
    idade = anoatual - ano;
    printf("%s tem ou tera: %d anos\n", nome, idade);
  }
  
  fclose(arquivo);
  return 0;
}
