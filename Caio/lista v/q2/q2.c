#include <stdio.h>
#include <stdlib.h>

#define n 100

int main(){
  int fila[n];
  int seletor, inicio = 0, fim = 0, cpf;

  while(seletor != 0){
    printf("\nMENU\n");
    printf("1 - inserir\n2 - listar\n3 - remover\n0 - sair\n");
    printf("digite o numero correspodente a sua operacao: ");
    scanf("%d", &seletor);
    switch(seletor){
    case 0:
      exit(1);
    break;
    case 1:
      if(inicio > n){
        exit(0);
      }
      printf("\ndigite o CPF a ser inserido:");
      scanf("%d", &cpf);
      fila[fim] = cpf;
      fim++;
      ;
    break;
    case 2:
      printf("\nCPFs cadastrados:\n");
      if(inicio == fim){
        printf("fila vazia !\n");
      }
      for(int i = inicio; i < fim; i++){
        printf("%d\n", fila[i]);
      }
    break;
    case 3:
      if(inicio > fim - 1){
        exit(1);
      }
      inicio++;
      printf("\nCPF removido\n");
      ;
    break;
    default:
      printf("\ninvalido\n");
    break;
  }
  }

  return 0;
}