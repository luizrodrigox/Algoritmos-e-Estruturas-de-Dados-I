#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info;
  struct no *prox;
}no;

typedef struct fila{
  no *inicio;
  no *fim;
}fila;

void inserir(fila *f){
  int cpf;
  printf("digite o CPF a ser inserido:");
  scanf("%d", &cpf);
  no *novono;
  novono = (no*)malloc(sizeof(no));
  novono->info = cpf;
  novono->prox = NULL;
  if(f->inicio == NULL){
  f->fim = novono;
  f->inicio = novono;
  } else{
    f->fim->prox = novono;
    f->fim = novono;
  }
}

void listar(fila *f){
  no *aux;
  aux = (no*)malloc(sizeof(no));
  aux = f->inicio;
  printf("\nCPFs cadastrados:\n");
  if(f){
    while(aux){
      printf("%d\n", aux->info);
      aux = aux->prox;
    }
  if(f->inicio == NULL){
    printf("fila vazia !\n");
  }
  }
}

void remover(fila *f){
  no *aux;
  aux = (no*)malloc(sizeof(no));
  aux = f->inicio;
  f->inicio = f->inicio->prox;
  free(aux);
  printf("\nCPF removido\n");
}

int main(){
  fila f;
  f.inicio = NULL;
  f.fim = NULL;
  int seletor;
  
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
      inserir(&f);
    break;
    case 2:
      listar(&f);
    break;
    case 3:
      remover(&f);
    break;
    default:
      printf("invalido");
    break;
  }
  }

  return 0;
}