#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct No* prox;
}no;

no* InicializarLista() {
  return NULL;
}

no* CriarNo(int valor) {
  no* novono = (no*)malloc(sizeof(no));
  novono->valor = valor;
  novono->prox = NULL;
  return novono;
}

void InserirElemento(no** Lista, int elemento, int elementoAntesDe) {
  no* novono = CriarNo(elemento);
  if (*Lista == NULL) {
    *Lista = novono;
    return;
  }
  no* anterior = NULL;
  no* atual = *Lista;

  while (atual != NULL) {
    if (atual->valor == elementoAntesDe) {
      novono->prox = atual;
      if (anterior != NULL) {
        anterior->prox = novono;
      } else {
        *Lista = novono;
        }
      return;
    }
    anterior = atual;
    atual = atual->prox;
  }
  printf("Elemento %d nao encontrado na lista. Nenhum elemento inserido.\n", elementoAntesDe);
  free(novono);
}

void RemoverElemento(no** Lista, int elemento) {
  no* anterior = NULL;
  no* atual = *Lista;

  while (atual != NULL) {
    if (atual->valor == elemento) {
      if (anterior != NULL) {
        anterior->prox = atual->prox;
      } else{
          *Lista = atual->prox;
        }
      free(atual);
      return;
    }
    anterior = atual;
    atual = atual->prox;
  }
  printf("Elemento %d nao encontrado na lista. Nenhum elemento removido.\n", elemento);
}

no* BuscarElemento(no* Lista, int elemento) {
  no* atual = Lista;
  while (atual != NULL) {
    if (atual->valor == elemento) {
      return atual;
    }
    atual = atual->prox;
  }
  return NULL;
}

void ExibirLista(no* Lista) {
  no* atual = Lista;
  if (atual == NULL) {
    printf("A lista esta vazia.\n");
    return;
  }

  while (atual != NULL) {
    printf("%d -> ", atual->valor);
    atual = atual->prox;
  }
  printf("NULL\n");
}

int main() {
  no* lista = InicializarLista();

  char opcao;
  int elemento, elementoAntesDe, elementoBuscado;

  do {
    printf("\na) Sair\n");
    printf("b) Inserir Elemento antes de um elemento especifico\n");
    printf("c) Remover Elemento\n");
    printf("d) Buscar Elemento\n");
    printf("e) Exibir Lista\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &opcao);

    switch (opcao) {
      case 'b':
        printf("Digite o valor do elemento que deseja inserir: ");
        scanf("%d", &elemento);
        printf("Digite o valor do elemento antes do qual deseja inserir: ");
        scanf("%d", &elementoAntesDe);
        InserirElemento(&lista, elemento, elementoAntesDe);
        break;
      case 'c':
        printf("Digite o valor do elemento que deseja remover: ");
        scanf("%d", &elemento);
        RemoverElemento(&lista, elemento);
        break;
      case 'd':
        printf("Digite o valor do elemento que deseja buscar: ");
        scanf("%d", &elementoBuscado);
        no* resultado = BuscarElemento(lista, elementoBuscado);
        if (resultado != NULL) {
          printf("%d encontrado na lista.\n", elementoBuscado);
        } else{
            printf("%d nao encontrado na lista.\n", elementoBuscado);
          }
        break;
      case 'e':
        printf("Lista: ");
        ExibirLista(lista);
        break;
      case 'a':
        printf("Saindo do programa.\n");
        exit(1);
        break;
      default:
        printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 'a');

  no* atual = lista;
  while (atual != NULL) {
    no* temp = atual;
    atual = atual->prox;
    free(temp);
  }

  return 0;

  system("pause");
}