#include <stdio.h>

int main(void){
  char palavra[50];
  FILE *arquivo1, *arquivo2, *arquivo3;

  arquivo1 = fopen("arquivo1.txt", "r");
  arquivo2 = fopen("arquivo2.txt", "r");
  arquivo3 = fopen("arquivo3.txt", "w");
  
  while(fscanf(arquivo1, "%s", palavra)!=EOF){
    fprintf(arquivo3, "%s\n", palavra);
  }
  
  while(fscanf(arquivo2, "%s", palavra)!=EOF){
    fprintf(arquivo3, "%s\n", palavra);
  }
  fclose(arquivo1);
  fclose(arquivo2);
  fclose(arquivo3);

  return 0;
}