#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
    char endereco[100];
};

int main() {
    struct pessoa pessoas;

    printf("Digite o nome: ");
    gets(pessoas.nome);

    printf("Digite a idade: ");
    scanf("%d", &pessoas.idade);

    while (getchar() != '\n');

    printf("Digite o endereco: ");
    gets(pessoas.endereco);

    printf("\nDados da pessoa:\n");
    printf("Nome: %s\n", pessoas.nome);
    printf("Idade: %d\n", pessoas.idade);
    printf("Endereco: %s", pessoas.endereco);

    return 0;
}