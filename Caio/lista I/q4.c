#include <stdio.h>
#include <string.h>

struct Ingrediente {
    char nome[50];
    int quantidade;
};

struct Receita {
    char nome[25];
    int quantidadeIngredientes;
    struct Ingrediente ingredientes[10];
};

void lerReceita(struct Receita *receita) {
    printf("Digite o nome da receita: ");
    fgets(receita->nome, 25, stdin);
    receita->nome[strcspn(receita->nome, "\n")] = '\0';

    printf("Digite a quantidade de ingredientes da receita: ");
    scanf("%d", &(receita->quantidadeIngredientes));
    while (getchar() != '\n'); 

    printf("Digite os ingredientes da receita:\n");
    for (int i = 0; i < receita->quantidadeIngredientes; i++) {
        printf("Ingrediente %d:\n", i + 1);
        printf("Nome: ");
        fgets(receita->ingredientes[i].nome, 50, stdin);
        receita->ingredientes[i].nome[strcspn(receita->ingredientes[i].nome, "\n")] = '\0';

        printf("Quantidade: ");
        scanf("%d", &(receita->ingredientes[i].quantidade));
        while (getchar() != '\n');
    }
}

void exibirReceita(struct Receita receita) {
    printf("Receita: %s\n", receita.nome);
    printf("Quantidade de ingredientes: %d\n", receita.quantidadeIngredientes);
    printf("Ingredientes:\n");
    for (int i = 0; i < receita.quantidadeIngredientes; i++) {
        printf("- %s: %d\n", receita.ingredientes[i].nome, receita.ingredientes[i].quantidade);
    }
    printf("\n");
}

int main() {
    struct Receita receitas[5];

    printf("Cadastro de receitas:\n");

    for (int i = 0; i < 5; i++) {
        printf("Receita %d:\n", i + 1);
        lerReceita(&receitas[i]);
    }

    printf("\n--- Receitas Cadastradas ---\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Receita %d:\n", i + 1);
        exibirReceita(receitas[i]);
    }

    return 0;
}