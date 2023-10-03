#include <stdio.h>

int main(void){
  char nome[50];
  float n1, n2, media;
  FILE *arquivoalunos;

  arquivoalunos = fopen("alunos.txt", "w");
  
  for (int i = 0; i < 10; i++){
    printf("digite o nome:");
    scanf(" %[^\n]s", nome);
    printf("digite a nota 1:");
    scanf("%f", &n1);
    printf("digite a nota 2:");
    scanf("%f", &n2);
    media = 0;
    media = (n1+n2)/2;
    fprintf(arquivoalunos, "%s\t %.2f\t %.2f\t %.2f\n", nome, n1, n2, media);
  }
  return 0;
}