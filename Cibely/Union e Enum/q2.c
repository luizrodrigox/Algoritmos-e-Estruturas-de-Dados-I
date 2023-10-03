#include <stdio.h>
#include <stdlib.h>

typedef union tipo
{
  char Alimento[15];
  char Bebida[15];
  char Eletronico[15];
} Tipo;

typedef struct produto
{
  char nome[50];
  float preco;
  Tipo tipo;
} Produto;

int main(void)
{
  Produto produto;
  printf("Digite o nome do produto: ");
  scanf(" %[^\n]s", produto.nome);
  printf("Digite o preco: ");
  scanf("%f", &produto.preco);
  printf("Digite o tipo do produto(alimento, bebida, eletronico): ");
  scanf(" %[^\n]s", produto.tipo.Alimento);
  printf("\n");
  printf("Nome do produto: %s\n", produto.nome);
  printf("Preco do produto: %.2f\n", produto.preco);
  printf("Tipo do produto: %s\n", produto.tipo.Alimento);
  return 0;
}