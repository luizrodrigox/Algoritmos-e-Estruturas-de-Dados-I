#include <stdio.h>
#include <string.h>

void trocavogal(char *str){
  int i = 0, tam = 0;
  tam = strlen(str);
  for(i = 0; i < tam; i++){
    switch (*str){
    case 'a':
      *str = 'e';
      break;
    case 'e':
      *str = 'i';
      break;
    case 'i':
      *str = 'o';
      break;
    case 'o':
      *str = 'u';
      break;
    case 'u':
      *str = 'a';
    default:
      break;
    }
    str++;
  }
}

void imprime(char *str){
  int tam = strlen(str);
  for(int i = 0; i < tam; i++){
    printf("%c", *str);
    str++;
  }
}

int main(void){
  char frase[100];
  printf("digite a frase: ");
  gets(frase);
  trocavogal(frase);
  imprime(frase);
  return 0;
}