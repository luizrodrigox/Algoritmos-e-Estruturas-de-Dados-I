#include <stdio.h>
#include <stdlib.h>

typedef enum mes
{
  invalido,
  janeiro,
  fevereiro,
  marco,
  abril,
  maio,
  junho,
  julho,
  agosto,
  setembro,
  outubro,
  novembro,
  dezembro
} Mes;

typedef struct data
{
  int dia;
  Mes mes;
  int ano;
} Data;

int main(void)
{
  Data data;
  printf("Digite o dia: ");
  scanf("%d", &data.dia);
  if (data.dia < 0 || data.dia == 0 || data.dia > 31)
    {
      printf("Erro");
      exit(1);
    }
  printf("Digite um numero referente ao mes: ");
  scanf("%d", &data.mes);
  if (data.mes < 0 || data.mes == 0 || data.mes > 12)
    {
      printf("Erro");
      exit(1);
    }
  printf("Digite o ano: ");
  scanf("%d", &data.ano);
  printf("\n");
  printf("-----DATA-----\n");
  switch (data.mes)
  {
  case 1:
    printf("%.2d/JANEIRO/%.4d", data.dia, data.ano);
    break;
  case 2:
    printf("%.2d/FEVEREIRO/%.4d", data.dia, data.ano);
    break;
  case 3:
    printf("%.2d/MARCO/%.4d", data.dia, data.ano);
    break;
  case 4:
    printf("%.2d/ABRIL/%.4d", data.dia, data.ano);
    break;
  case 5:
    printf("%.2d/MAIO/%.4d", data.dia, data.ano);
    break;
  case 6:
    printf("%.2d/JUNHO/%.4d", data.dia, data.ano);
    break;
  case 7:
    printf("%.2d/JULHO/%.4d", data.dia, data.ano);
    break;
  case 8:
    printf("%.2d/AGOSTO/%.4d", data.dia, data.ano);
    break;
  case 9:
    printf("%.2d/SETEMBRO/%.4d", data.dia, data.ano);
    break;
  case 10:
    printf("%.2d/OUTUBRO/%.4d", data.dia, data.ano);
    break;
  case 11:
    printf("%.2d/NOVEMBRO/%.4d", data.dia, data.ano);
    break;
  case 12:
    printf("%.2d/DEZEMBRO/%.4d", data.dia, data.ano);
    break;
  default:
    printf("Erro");
    exit(1);
    break;
  }
  return 0;
}
