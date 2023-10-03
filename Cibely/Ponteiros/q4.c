#include<stdio.h>
#include<math.h>

//função que dado o valor de um lado do hexágono, calcula a área e o perímetro do hexágono.
void calcula_hexagono(float l, float *area, float *perimetro){
    *area = ((3 * pow(l, 2)) + sqrt(3))/ 2;//calculo da área.
    *perimetro = (6 * l);//calculo do perímetro.
}

//função principal onde contêm interação com o usuário e é feita a chamada da função "calcula_hexagono".
int main(void){
    float l = 0, a = 0, p = 0;//adicionando variaveis.
    printf("digite o valor de um lado do hexagono ? \n");
    scanf("%f", &l);//recebendo o valor de um lado e guardando na variável "l".
    calcula_hexagono(l, &a, &p);//passando as variáveis como argumento para função.
    printf("Area do hexagono: %.2f \nPerimetro do hexagono: %.2f", a, p);//exibindo a area e o perimetro do hexagono.
    return 0;
}