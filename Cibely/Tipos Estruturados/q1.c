#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definindo variáveis com valores constantes.
#define MAX_VAGAS 10
#define MAX_TURMAS 3
#define NUM_NOTAS 3
#define MAX_NOME 81
//criando a struct aluno.
typedef struct aluno
{
  int mat;
  char nome[MAX_NOME];
  float notas[NUM_NOTAS];
  float media;
} Aluno;
//criando a struct turma.
typedef struct turma
{
  char id;   // caractere que identifica a turma, por exemplo, A ou B.
  int vagas; // números de vagas disponíveis para fechar a turma.
  Aluno *alunos[MAX_VAGAS];
} Turma;

Turma *cria_turma(char id)
{
  Turma *t = malloc(sizeof(Turma)); // alocando memoria para a turma.
  t->id = id;
  t->vagas = MAX_VAGAS;
  for (int i = 0; i < MAX_VAGAS; i++)
  {
    t->alunos[i] = NULL; // definindo o vetor de alunos como nulo.
  }
  return t;
}

void imprime_turmas(Turma **turmas, int n)
{
  for (int i = 0; i < n; i++)
  {
    Turma *turma = turmas[i];
    printf("\nTurma %c - Vagas disponiveis: %d\n", turma->id, turma->vagas);
    if (turma->vagas == MAX_VAGAS)
    { // verificando se há alunos na turma.
      printf("Nao ha alunos matriculados.\n");
    }
    else
    {
      // exibindo todos os dados da turma.
      for (int j = 0; j < MAX_VAGAS - turma->vagas; j++)
      {
        Aluno *aluno = turma->alunos[j];
        printf("Matricula: %d | Nome: %s | Notas: %.1f ; %.1f ; %.1f | Media: %.1f\n", aluno->mat, aluno->nome, aluno->notas[0], aluno->notas[1], aluno->notas[2], aluno->media);
      }
    }
    printf("\n");
  }
}

void matricula_aluno(Turma **turma, int mat, char *nome, int t)
{
  // Verifica se ainda há vagas disponíveis na turma.
  if (turma[t]->vagas == 0)
  {
    printf("Nao ha vagas disponiveis na turma %c.\n", turma[t]->id);
    return;
  }
  // Cria um novo aluno e preenche seus dados.
  Aluno *novo_aluno = malloc(sizeof(Aluno));
  novo_aluno->mat = mat;
  strcpy(novo_aluno->nome, nome);
  novo_aluno->notas[0] = 0;
  novo_aluno->notas[1] = 0;
  novo_aluno->notas[2] = 0;
  novo_aluno->media = 0;
  // Adiciona o novo aluno à turma.
  int i;
  for (i = 0; i < MAX_VAGAS; i++)
  {
    if (turma[t]->alunos[i] == NULL)
    {
      turma[t]->alunos[i] = novo_aluno;
      turma[t]->vagas--;
      printf("Aluno matriculado na turma %c.\n", turma[t]->id);
      return;
    }
  }
}
void lanca_notas(Turma *turma)
{
  printf("Lancamento de notas para a turma %c:\n", turma->id);
  // percorre o vetor de alunos e solicita o lançamento das notas.
  for (int j = 0; j < MAX_VAGAS; j++)
  {
    if (turma->alunos[j] != NULL)
    {
      printf("Digite as notas do aluno %d - %s:\n", turma->alunos[j]->mat, turma->alunos[j]->nome);
      for (int s = 0; s < 3; s++)
      {
        printf("Nota %d: ", s + 1);
        scanf("%f", &turma->alunos[j]->notas[s]);
      }
      // calcula a média do aluno.
      float soma = 0.0;
      for (int s = 0; s < 3; s++)
      {
        soma += turma->alunos[j]->notas[s];
      }
      turma->alunos[j]->media = soma / 3.0;
    }
  }
  printf("Notas lancadas com sucesso!\n");
}

void imprime_alunos(Turma *turma)
{
  printf("Alunos da turma %c:\n\n", turma->id);
  for (int i = 0; i < MAX_VAGAS; i++)
  {
    Aluno *aluno = turma->alunos[i];
    if (aluno != NULL) // verificando se existe o aluno nesse espaço.
    {
      printf("Matricula: %d\n", aluno->mat);
      printf("Nome: %s\n", aluno->nome);
      printf("Notas: %.1f, %.1f, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
      printf("Media: %.1f\n\n", aluno->media);
    }
  }
}

int main(void)
{
  // declarando variaveis.
  char id, nome[MAX_NOME];
  Turma **turma = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
  // verificando se alocação dinamica foi bem sucedida.
  if (turma == NULL)
  {
    printf("ERRO");
    exit(1);
  }
  int controle = 0, n = 0, t = 0, matricula = 0;
  // exibindo painel inicial.
  printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as\nfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n\nAutor: Luiz Rodrigo\tVersao:1.0\n");
  while (controle != 6) // vai repetir ate o usuario digitar 6.
  {
    printf("\nMenu:\n1-Criar turma\n2-Listar turmas\n3-Matricular aluno\n4-Lancar notas\n5-Listar alunos\n6-Sair\n");
    scanf("%d", &controle);
    system("cls");
    switch (controle)
    {
    case 1:
      printf("\nInsira o id da turma que deseja criar: A,B ou C\n");
      scanf(" %c", &id);
      if (n > 3)
      {
        printf("numero maximo atingido");
      }
      else
      {
        turma[n] = (Turma *)malloc(sizeof(Turma));
        turma[n] = cria_turma(id);
        n++; // quantidade de turmas ate agora.
      }
      break;
    case 2:
      imprime_turmas(turma, n);
      break;
    case 3:
      printf("insira o qual turma deseja cadastrar seu aluno: A-0 B-1 C-2\n");
      scanf("%d", &t);
      printf("insira a matricula do aluno: ");
      scanf("%d", &matricula);
      printf("insira o nome do aluno: ");
      scanf(" %[^\n]s", &nome);
      matricula_aluno(turma, matricula, nome, t);
      break;
    case 4:
      printf("Qual turma deseja lancar as notas? A-0 B-1 C-2\n");
      scanf("%d", &t);
      lanca_notas(turma[t]);
      break;
    case 5:
      printf("Listar alunos de qual turma? A-0 B-1 C-2\n");
      scanf("%d", &t);
      imprime_alunos(turma[t]);
      break;
    default:
      printf("opção invalida");
      break;
    }
  }
  printf("Volte sempre que precisar!");
  for (int i = 0; i < n; i++)
  {
    free(turma[i]);
  }
  free(turma);
  return 0;
}