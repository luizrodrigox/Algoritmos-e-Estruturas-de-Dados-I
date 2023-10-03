#include <stdio.h>

int main(){
  char texto;
  FILE *arquivoa, *arquivob, *arquivoaux;

  arquivoa = fopen("a.txt", "r");
  arquivoaux = fopen("aux.txt", "w");

  while (fscanf(arquivoa,"%c", &texto) != EOF){
    fprintf(arquivoaux,"%c", texto);
  }

  fclose(arquivoa);
  fclose(arquivoaux);

  arquivob = fopen ("b.txt", "r");
  arquivoa = fopen("a.txt", "w");

  while (fscanf(arquivob,"%c", &texto) != EOF){
    fprintf(arquivoa,"%c", texto);
  }

  fclose(arquivoa);
  fclose(arquivob);

  arquivoaux = fopen("aux.txt", "r");
  arquivob = fopen("b.txt", "w");

  while (fscanf(arquivoaux,"%c", &texto) != EOF){
    fprintf(arquivob,"%c", texto);
  }
  
  fclose(arquivob);
  remove("aux.txt");
  
  return 0;
}