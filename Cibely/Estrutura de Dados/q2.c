#include <stdio.h>
#include <stdlib.h>
//criando uma struct Pessoa.
typedef struct pessoa{
    char nome[50];
    int idade;
    int CPF;
}Pessoa;
//função para preencher a matriz do tipo Pessoa.
void preenche(Pessoa ** pessoa, int n) {
    for(int i = 0; i < n; i++) {
        printf("\n\tDados pessoais: N - %d\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]s", pessoa[i]->nome);

        printf("Idade: ");
        scanf("%d", &pessoa[i]->idade);
        
        printf("Documento: ");
        scanf("%d", &pessoa[i]->CPF);
    }
}
//função para exibir a matriz.
void imprime(Pessoa ** pessoa, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("\nnome da pessoa: %s\n", pessoa[i]->nome);

        printf("numero do documento da pessoa: %d\n", pessoa[i]->CPF);

        printf("idade da pessoa: %d\n", pessoa[i]->idade);
    }

}
//função para alterar a idade.
void altera_idade(Pessoa ** pessoa, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Infome a nova idade: ");
        scanf("%d", &pessoa[i]->idade);
    }
}
//função para determinar a pessoa com a maior e a menor idade.
void maior_menor(Pessoa ** pessoa, int n) {
    int i, maior = 0, menor = 0;
    for (i = 0; i < n; i++) {
        if (pessoa[i]->idade > pessoa[maior]->idade) {
            maior = i;
        }
        if (pessoa[i]->idade < pessoa[menor]->idade) {
            menor = i;
        }
    }
    printf("\nMaior idade: %d", pessoa[maior]->idade);
    printf("\nMenor idade: %d", pessoa[menor]->idade);
} 

int main(void){
    int n;
    printf("Quantidade de pessoas: ");
    scanf("%d", &n);
    Pessoa ** pessoa = (Pessoa**) malloc(n * sizeof(Pessoa*));//alocando a memoria dinamicamente.
//verificando se alocação dinamica foi bem sucedida.
    if(pessoa == NULL) {
        exit(1);
    }

    for(int i = 0; i< n; i++){
        pessoa[i] = (Pessoa*) malloc(n * sizeof(Pessoa));
    }
//chamada das funções.
    preenche(pessoa, n);
    imprime(pessoa, n);
    altera_idade(pessoa, n);
    maior_menor(pessoa, n);
// liberando a memoria.
    for(int i = 0; i< n; i++){

        free(pessoa[i]);
        
    }

    free(pessoa);
    return 0;
}