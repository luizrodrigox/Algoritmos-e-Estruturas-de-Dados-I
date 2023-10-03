#include <stdio.h>
#include <stdlib.h>

typedef enum genero
{
    neutro,
    masculino,
    feminino
} Genero;

typedef struct pessoa
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

int main(void)
{
    Pessoa pessoa;
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]s", pessoa.nome);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);
    printf("Opcoes de genero:\n1-masculino\n2-feminino\nDigite o numero correspondente: ");
    scanf("%d", &pessoa.genero);
    printf("\n");
    printf("-----DADOS INFORMADOS-----\n");
    printf("NOME: %s\n", pessoa.nome);
    printf("IDADE: %d\n", pessoa.idade);
    pessoa.genero == masculino ? printf("GENERO: masculino\n") : printf("GENERO: feminino");
    return 0;
}