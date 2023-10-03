#include <stdio.h>

int main(){
  char nome[50];
  int anoatual, anonascimento, idade;
  FILE *arquivoentrada, *arquivosaida;

  printf("digite o ano atual: ");
  scanf("%d", &anoatual);

  arquivoentrada = fopen("data.txt", "r");
  arquivosaida = fopen("saida.txt", "w");

  while (fscanf(arquivoentrada, "%s %d", nome, &anonascimento) != EOF){
    idade = anoatual - anonascimento;
    if (idade < 18){
      fprintf(arquivosaida, "%s, menor de idade\n", nome);
    }
    if (idade >= 18){
      fprintf(arquivosaida, "%s, maior de idade\n", nome);
    }
  }

  fclose(arquivoentrada);
  fclose(arquivosaida);
  
  return 0;
}