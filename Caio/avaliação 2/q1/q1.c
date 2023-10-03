#include <stdio.h>

int main(){
    FILE *arquivoa, *arquivob, *arquivoc;
    int m, na, nb, p;

    arquivoa = fopen("a.txt", "r");
    arquivob = fopen("b.txt", "r");

    fscanf(arquivoa, "%d %d", &m, &na);
    fscanf(arquivob, "%d %d", &nb, &p);

    if (na != nb){
        printf("As dimensões das matrizes são inválidas.\n");
        return 1;
    }

    arquivoc = fopen("c.txt", "w");

    int A[m][na], B[nb][p], C[m][p];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < na; j++) {
            fscanf(arquivoa, "%d", &A[i][j]);
        }
    }

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < p; j++) {
            fscanf(arquivob, "%d", &B[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < na; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    fprintf(arquivoc, "%d %d\n", m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            fprintf(arquivoc, "%d ", C[i][j]);
        }
        fprintf(arquivoc, "\n");
    }

    fclose(arquivoa);
    fclose(arquivob);
    fclose(arquivoc);

    return 0;
}