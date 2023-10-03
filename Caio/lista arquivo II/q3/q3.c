#include <stdio.h>

int main(){
  char letra;
  FILE *arquivousuario, *arquivonovo;

  arquivousuario = fopen("nome.txt", "r");
  arquivonovo = fopen("nomealterado.txt", "w");

  while (fscanf(arquivousuario, "%c", &letra) != EOF){
    if (letra == 'A' || letra == 'a'){
      letra = '*';
    }
    fprintf(arquivonovo,"%c",letra);    
  }
  
  return 0;
}