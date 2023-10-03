#include <stdio.h>
#include <stdlib.h>

void uniao(int *v1, int n1, int *v2, int n2){
  int *v3;
  v3 = (int*)malloc((n1 + n2) * sizeof(int));
  for (int i = 0; i < n1; i++)
    {
      v3[i] = v1[i];
    }

   for (int i = 0; i < n2; i++)
   {
    v3[n1+i] = v2[i];
   }
   
  printf("vetor 3: ");
  for(int i = 0; i < n1+n2; i++){
    printf("%d\t", v3[i]);
  }
  free(v3);
}

int main(void){
  int *v1, n1, *v2, n2;
  printf("digite o tamanho do vetor 1: ");
  scanf("%d", &n1);
  printf("digite o tamanho do vetor 2: ");
  scanf("%d", &n2);
  v1 = (int*)malloc(n1 * sizeof(int));
  v2 = (int*)malloc(n2 * sizeof(int));
  printf("digite os valores do vetor 1: ");
  for(int i = 0; i < n1; i++){
    scanf("%d", &v1[i]);
  }
  printf("digite os valores do vetor 2: ");
  for(int i = 0; i < n2; i++){
    scanf("%d", &v2[i]);
  }
  uniao(v1, n1, v2, n2);
  free(v1);
  free(v2);
  return 0;
}