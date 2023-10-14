#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *prox;
} no;

typedef struct Fila {
  no *inicio;
  no *fim;
} Fila;

Fila *filaCriar() {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->inicio = f->fim = NULL;
  return f;
}

int filaEstaVazia(Fila *f) {
  return f->inicio == NULL;
}

void filaInserir(Fila *f, int valor) {
  no *novono = (no *)malloc(sizeof(no));
  if (novono == NULL) {
    printf("Erro: Não foi possível alocar memória para o novo nó.\n");
    exit(1);
  }
  novono->info = valor;
  novono->prox = NULL;
    
  if (filaEstaVazia(f)) {
    f->inicio = f->fim = novono;
  } else {
      f->fim->prox = novono;
      f->fim = novono;
    }
}

int filaRemover(Fila *f) {
  if (filaEstaVazia(f)) {
    printf("Erro: A fila está vazia.\n");
    exit(1);
  }

  no *temp = f->inicio;
  int valor = temp->info;
  f->inicio = f->inicio->prox;
    
  if (f->inicio == NULL) {
    f->fim = NULL;
  }
    
  free(temp);
  return valor;
}

void MostrarFila(Fila *f) {
  if (filaEstaVazia(f)) {
    printf("Fila vazia.\n");
    return;
  }
    
  no *atual = f->inicio;
  printf("Fila: ");
  while (atual != NULL) {
    printf("%d ", atual->info);
    atual = atual->prox;
  }
  printf("\n");
}

int main() {
  Fila *fila = filaCriar();
  char escolha;
  int valor;
    
  do {
    printf("\nOpcoes:\n");
    printf("a) Inserir elemento na fila\n");
    printf("b) Remover elemento\n");
    printf("c) Sair\n");
    printf("Escolha: ");
    scanf(" %c", &escolha);
        
    switch (escolha) {
      case 'a':
        printf("Digite o valor a ser inserido na fila: ");
        scanf("%d", &valor);
        filaInserir(fila, valor);
        MostrarFila(fila);
        break;
      case 'b':
        if (!filaEstaVazia(fila)) {
          int valorRemovido = filaRemover(fila);
          printf("Elemento removido: %d\n", valorRemovido);
        } else{
          printf("Erro: A fila está vazia.\n");
          }
        MostrarFila(fila);
        break;
      case 'c':
        exit(1);
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  } while (escolha != 'c');

  while (!filaEstaVazia(fila)) {
    filaRemover(fila);
  }
  free(fila);

  return 0;

  system("pause");
}