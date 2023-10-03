#include <stdio.h>

#define NUM_ALUNOS 5

struct Aluno {
    int matricula;
    char nome[50];
    float nota1, nota2, nota3, media;
};

void lerAluno(struct Aluno *aluno) {
    printf("Digite a matricula do aluno: ");
    scanf("%d", &(aluno->matricula));

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);

    printf("Digite a nota da primeira prova do aluno: ");
    scanf("%f", &(aluno->nota1));

    printf("Digite a nota da segunda prova do aluno: ");
    scanf("%f", &(aluno->nota2));

    printf("Digite a nota da terceira prova do aluno: ");
    scanf("%f", &(aluno->nota3));

    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3) / 3;
}

void exibirAluno(struct Aluno aluno) {
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Nota 3: %.2f\n", aluno.nota3);
    printf("Media: %.2f\n", aluno.media);
    printf("Aprovacao: %s\n\n", aluno.media >= 6 ? "Aprovado" : "Reprovado");
}

int main() {
    struct Aluno alunos[NUM_ALUNOS];
    int i;

    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("Entre com os dados do aluno %d:\n", i + 1);
        lerAluno(&alunos[i]);
    }

    struct Aluno alunoMaiorNota1 = alunos[0];
    struct Aluno alunoMaiorMedia = alunos[0];
    struct Aluno alunoMenorMedia = alunos[0];

    for (i = 1; i < NUM_ALUNOS; i++) {
        if (alunos[i].nota1 > alunoMaiorNota1.nota1) {
            alunoMaiorNota1 = alunos[i];
        }

        if (alunos[i].media > alunoMaiorMedia.media) {
            alunoMaiorMedia = alunos[i];
        }

        if (alunos[i].media < alunoMenorMedia.media) {
            alunoMenorMedia = alunos[i];
        }
    }

    printf("\nAluno com maior nota na primeira prova:\n");
    exibirAluno(alunoMaiorNota1);

    printf("Aluno com maior media geral:\n");
    exibirAluno(alunoMaiorMedia);

    printf("Aluno com menor media geral:\n");
    exibirAluno(alunoMenorMedia);

    printf("Situação dos alunos:\n");
    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %d:\n", i + 1);
        exibirAluno(alunos[i]);
    }

    return 0;
}