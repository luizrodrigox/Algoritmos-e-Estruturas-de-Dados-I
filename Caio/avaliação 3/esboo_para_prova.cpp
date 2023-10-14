#include <stdlib.h>
#include <stdio.h>

typedef struct fila_no {

} fila_no;

typedef struct {

} fila;


fila *filaCreate() {
  
}

void filaInsert(fila *f, int x) {
  
}

int filaRemove(fila *f) {
 
}

int filaIsEmpty(fila *f) {

}

void MostrarFila(fila *f){
   
}


void Menu()
{
    printf( "Digite a sua escolha: \n"
        "    1 enfileirar elemento \n"
        "    2 retirar da fila \n"
        "    3 para finalizar \n"
        "? ");
}


int main() {
    int i, opcao, x;
  fila *f = filaCreate();
  
     Menu();
    scanf("%i", &opcao);

    while (opcao != 3)
    {

        switch (opcao)
        {
            case 1:
                printf( "Digite um valor: ");
                scanf("\n%d", &x);

                filaInsert(f, x);
                MostrarFila(f);

                break;
            case 2:
                filaRemove(f);
			    MostrarFila(f);

                break;

            default:
                printf( "Escolha invalida.\n\n");
                Menu();
                break;
        }

        scanf("%i", &opcao);   
    }

    
return 0;

system("pause");
}
