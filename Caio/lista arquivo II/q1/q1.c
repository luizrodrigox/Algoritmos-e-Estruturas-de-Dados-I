#include <stdio.h>
#include <string.h>

int main(){
  char cidade[40], cidademaispopulosa[40];
  int populacao = 0, maiorpopulacao = 0;
  FILE *arquivoentrada, *arquivosaida;

  arquivoentrada = fopen("cidades.txt", "r");
  arquivosaida = fopen("cidademaispopulosa.txt", "w");

  while (fscanf(arquivoentrada, "%s %d", cidade, &populacao) != EOF){
    if (populacao > maiorpopulacao){
      maiorpopulacao = populacao;
      strcpy(cidademaispopulosa, cidade);
    }
  }

  fprintf(arquivosaida, "%s %d", cidademaispopulosa, maiorpopulacao);

  fclose(arquivoentrada);
  fclose(arquivosaida);

  return 0;
}