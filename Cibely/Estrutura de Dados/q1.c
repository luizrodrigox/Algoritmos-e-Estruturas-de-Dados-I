#include <stdio.h>
#include <stdlib.h>
//criando uma struct Funcionario.
typedef struct funcionarios {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;
//função para preencher o funcionario.
void preenche(Funcionario* funcionario, int n) {
    for(int i = 0; i < n; i++) {

        printf("\n\tFuncionario %d\n", i+1);
        
        printf("Nome: ");
        scanf(" %[^\n]s", funcionario[i].nome);

        printf("Salario: ");
        scanf("%f", &funcionario[i].salario);

        printf("Identificador: ");
        scanf("%d", &funcionario[i].identificador);

        printf("Cargo: ");
        scanf(" %[^\n]s", funcionario[i].cargo);
    }
}
//função para exibir as informações.
void imprime(Funcionario* funcionario, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("\n\tFuncionario %d\n", i+1);
        printf("Nome: %s\n", funcionario[i].nome);
        printf("Salario: %f\n", funcionario[i].salario);
        printf("Identificador: %d\n", funcionario[i].identificador);
        printf("Cargo: %s\n", funcionario[i].cargo);
    }

}
//função para alterar o salario.
void altera_salario(Funcionario* funcionario, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Novo valor do salario para o funcionario %d: ", i+1);
        scanf("%f", &funcionario[i].salario);
    }
}
//função para determinar o funcionário com o maior e o menor salario.
void maior_menor(Funcionario* funcionario, int n) {
    int i, maior = 0, menor = 0;
    for (i = 0; i < n; i++) {
        if (funcionario[i].salario > funcionario[maior].salario) {
            maior = i;
        }
        if (funcionario[i].salario < funcionario[menor].salario) {
            menor = i;
        }
    }
    printf("\nMaior salario: %f", funcionario[maior].salario);
    printf("\nMenor salario: %f", funcionario[menor].salario);
}   

int main() {
    int n;
    printf("Informe a quantidade de funcionarios: ");
    scanf("%d", &n);
    Funcionario* funcionario = (Funcionario*) malloc(n * sizeof(Funcionario));//alocando a memoria dinamicamente.
// verificando se a alocação dinamica foi bem sucedida.
    if(funcionario == NULL) {
        printf("Erro!");
        exit(1);
    }
//chamada das funções.
    preenche(funcionario, n);
    imprime(funcionario, n);
    altera_salario(funcionario, n);
    maior_menor(funcionario, n);
//liberando a memoria.
    free(funcionario);
    return 0;
}