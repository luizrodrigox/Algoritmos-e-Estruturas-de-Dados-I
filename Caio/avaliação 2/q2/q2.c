#include <stdio.h>
#include <string.h>

struct atleta{
  char nome[50];
  char esporte[50];
  int idade;
  float altura;
};

int main(){
  struct atleta atletas[5];
  struct atleta atletamaisvelho, atletamaisalto;
  FILE *arquivo;

  arquivo = fopen("atletas.txt", "w");

  for(int i = 0; i < 5; i++){
    printf("dados do atleta %d:\n", i + 1);
    printf("nome: ");
    scanf(" %s", atletas[i].nome);
    printf("esporte: ");
    scanf(" %s", atletas[i].esporte);
    printf("idade: ");
    scanf("%d", &atletas[i].idade);
    printf("altura :");
    scanf("%f", &atletas[i].altura);
    fprintf(arquivo, "%s %s %d %.2f\n", atletas[i].nome , atletas[i].esporte, atletas[i].idade, atletas[i].altura);
  }

  fclose(arquivo);

  arquivo = fopen("atletas.txt", "r");

  atletamaisvelho.idade = 0;
  atletamaisalto.altura = 0;
  int i = 0;

    while (fscanf(arquivo, "%s %s %d %f", atletas[i].nome, atletas[i].esporte, &atletas[i].idade, &atletas[i].altura) != EOF){
      if (atletas[i].idade > atletamaisvelho.idade){
        atletamaisvelho = atletas[i];
      }
      if (atletas[i].altura > atletamaisalto.altura){
        atletamaisalto = atletas[i];
      }
      i++;
    }
  fclose(arquivo);

  printf("\nAtleta mais velho:\n");
  printf("Nome: %s\n", atletamaisvelho.nome);
  printf("Esporte praticado: %s\n", atletamaisvelho.esporte);
  printf("Idade: %d\n", atletamaisvelho.idade);

  printf("\nAtleta mais alto:\n");
  printf("Nome: %s\n", atletamaisalto.nome);
  printf("Esporte praticado: %s\n", atletamaisalto.esporte);
  printf("Altura: %.2f metros\n", atletamaisalto.altura);

  return 0;
}