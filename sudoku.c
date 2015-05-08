#include "pilha.h"
#include "sudoku.h"

int** aloca_matriz (int colunas, int linhas) {
    int i;
    int **matriz = (int **)malloc(linhas * sizeof(int *));

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    return matriz;
}


void n_imprime (int **mat, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void imprime_matriz (int mat[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}



int** submatriz (int li, int col, int sudoku[9][9]) {
    int **sub = aloca_matriz(3, 3);
    int i, j;

    if ((li >= 0) && (li <=2)){
        if ((col >= 0) && (col <= 2)) {

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    sub[i][j] = sudoku[i][j];
                }
            }

        } else if ((col >= 3) && (col <=5)) {

            for (i = 0; i < 3; i++) {
                for (j = 3; j < 6; j++) {
                    sub[i][j - 3] = sudoku[i][j];
                }
            }

        } else if ((col >= 6) && (col <=8)) {

            for (i = 0; i < 3; i++) {
                for (j = 6; j < 9; j++) {
                    sub[i][j - 6] = sudoku[i][j];
                }
            }

        }
    } else if ((li >= 3) && (li <=5)) {
        if ((col >= 0) && (col <= 2)) {

            for (i = 3; i < 6; i++) {
                for (j = 0; j < 3; j++) {
                    sub[i - 3][j] = sudoku[i][j];
                }
            }
        } else if ((col >= 3) && (col <=5)) {

            for (i = 3; i < 6; i++) {
                for (j = 3; j < 6; j++) {
                    sub[i - 3][j - 3] = sudoku[i][j];
                }
            }

        } else if ((col >= 6) && (col <=8)) {

            for (i = 3; i < 6; i++) {
                for (j = 6; j < 9; j++) {
                    sub[i - 3][j - 6] = sudoku[i][j];
                }
            }

        }
    } else if ((li >= 6) && (li <=8)) {
        if ((col >= 0) && (col <= 2)) {

            for (i = 6; i < 9; i++) {
                for (j = 0; j < 3; j++) {
                    sub[i - 6][j] = sudoku[i][j];
                }
            }

        } else if ((col >= 3) && (col <=5)) {

            for (i = 6; i < 9; i++) {
                for (j = 3; j < 6; j++) {
                    sub[i - 6][j - 3] = sudoku[i][j];
                }
            }

        } else if ((col >= 6) && (col <=8)) {

            for (i = 6; i < 9; i++) {
                for (j = 6; j < 9; j++) {
                    sub[i - 6][j - 6] = sudoku[i][j];
                }
            }
        }
    }

    return sub;
}



void numeros_possiveis (int li, int col, int **submat, int sudoku[9][9], int numeros[]) {
    int i, j, cont = 0;

    for(i = 0; i < 10; i++) {
        numeros[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        if(sudoku[li][i] != 0) {
            if(numeros[sudoku[li][i]] == 0) {
                numeros[sudoku[li][i]] = 1;
                cont++;
            }
        }
    }

    for (i = 0; i < 9; i++) {
        if(sudoku[i][col] != 0) {
            if(numeros[sudoku[i][col]] == 0) {
                numeros[sudoku[i][col]] = 1;
                cont++;
            }
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(submat[i][j] != 0) {
                if(numeros[submat[i][j]] == 0) {
                    numeros[submat[i][j]] = 1;
                    cont++;
                }
            }
        }
    }
}



void procura_faceis (int sudoku[9][9]) {
    int i, j, **sub, cont;
    int flag = 1;
    int numeros[10], solucoes[10];
    while (flag == 1) {
        flag = 0;
        for(i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (sudoku[i][j] == 0) {
                    cont = num_possibilidades(i, j, sudoku, solucoes);

                    if (cont == 1) {
                        sudoku[i][j] = solucoes[0];
                        flag = 1;
                    }
                }
            }
        }
    }
}



int** copia_mat (int sudoku[9][9]) {
    int **nova = aloca_matriz(9,9);
    int i, j;

    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            nova[i][j] = sudoku[i][j];
        }
    }

    return nova;
}



int resolvida (int sudoku[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}



int num_possibilidades (int li, int col, int sudoku[9][9], int solucoes[]) {
    int numeros[10], **sub, cont = 0, k;

    sub = submatriz(li, col, sudoku);
    numeros_possiveis(li, col, sub, sudoku, numeros);

    for (k = 1; k < 10; k++) {
        if (numeros[k] == 0) {
            solucoes[cont] = k;
            cont++;
        }
    }

    return cont;
}

int minimo (int li, int col, int sudoku[9][9]) {
    int solucoes[10], cont, min = 9, imin, jmin, i, j;

    for(i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                cont = num_possibilidades(i, j, sudoku, solucoes);

                if (cont < min) {
                    min = cont;
                    imin = i;
                    jmin = j;
                }
            }
        }
    }



    if((li == imin) && (col == jmin)) {
            return 1;
    }

    return 0;
}


int resolve (int sudoku[9][9]) {
    Pilha *p = create_stack(); //empilha ponteiros da matriz
    int i, j, numeros[10], solucoes[10], x, cont;

    p = push(p, sudoku);
    procura_faceis(sudoku);

    if (resolvida(sudoku)) {
        printf("Resolvida.\n");
        imprime_matriz(sudoku);
        return 1;
    }

    while(!resolvida(sudoku)) {
        for(i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (sudoku[i][j] == 0) {
                    cont = num_possibilidades(i, j, sudoku, solucoes);

                    if (cont == 0) {
                        p = pop(p, sudoku);
                    }

                    if (cont >= 1) {
                        if (minimo(i, j, sudoku)) {

                            for (x = 0; x < cont; x++) {
                                int **nova = copia_mat(sudoku);
                                nova[i][j] = solucoes[x];
                                p = push2(p, nova);
                            }
                            p = pop(p, sudoku);
                            procura_faceis(sudoku);
                            if (resolvida(sudoku)) {
                                printf("Resolvida.\n");
                                imprime_matriz(sudoku);
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
