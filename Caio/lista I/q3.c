#include <stdio.h>
#include <string.h>

#define NUM_PESSOAS 5

struct Pessoa {
    char nome[50];
    char endereco[100];
    char telefone[15];
};

void ordenarPessoas(struct Pessoa pessoas) {
    int i, j;
    struct Pessoa temp;
    for (i = 0; i < NUM_PESSOAS - 1; i++) {
        for (j = i + 1; j < NUM_PESSOAS; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
}

void imprimirPessoas(struct Pessoa pessoas) {
    int i;
    printf("Pessoas em ordem alfabetica:\n");
    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Endereco: %s\n", pessoas[i].endereco);
        printf("Telefone: %s\n\n", pessoas[i].telefone);
    }
}

int main() {
    struct Pessoa pessoas[NUM_PESSOAS];
    int i;
    printf("Entre com os dados de 5 pessoas:\n");

    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Digite o nome: ");
        fgets(pessoas[i].nome, 50, stdin);
        printf("Digite o endereco: ");
        fgets(pessoas[i].endereco, 100, stdin);
        printf("Digite o telefone: ");
        fgets(pessoas[i].telefone, 15, stdin);
        printf("\n");
    }
    ordenarPessoas(pessoas);
    imprimirPessoas(pessoas);
    return 0;
}