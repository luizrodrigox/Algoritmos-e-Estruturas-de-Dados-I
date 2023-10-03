#include <stdio.h>
#include <stdlib.h>

struct aluno{
  char nome[100];
  float media;
  int faltas;
};

int main(void){
  int n;
  struct aluno *alunos;
  
  printf("QUANTIDADE DE ALUNOS:\n ");
  scanf("%d", &n);
  alunos = (struct aluno*)malloc(n * sizeof(struct aluno));
  for (int i = 0; i < n; i++){
    printf("\nALUNO %d:\n", i + 1);
    printf("NOME:");
    scanf(" %[^\n]s", alunos[i].nome);
    printf("MEDIA:");
    scanf("%f", &alunos[i].media);
    printf("FALTAS:");
    scanf("%d", &alunos[i].faltas);
  }
  for (int i = 0; i < n - 1; i++) {
    int maxIndex = i;
      for (int j = i + 1; j < n; j++) {
        if (alunos[j].media < alunos[maxIndex].media) {
          i = j;
        }
      }
        struct aluno temp = alunos[i];
        alunos[i] = alunos[maxIndex];
        alunos[maxIndex] = temp;
  }
  for (int i = 0; i < n; i++){
    printf("\nALUNO %d:", i + 1);
    printf("\nNOME:");
    printf("%s", alunos[i].nome);
    printf("\nMEDIA: ");
    printf("%f", alunos[i].media);
    printf("\nFALTAS: ");
    printf("%d", alunos[i].faltas);
  }
  free(alunos);
  return 0;
}