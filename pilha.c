#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "sudoku.h"

Pilha* create_stack () {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p = NULL;
    return p;
}

Pilha* push (Pilha *p, int sudoku[9][9]) {  //push da matriz original
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->topo.sudoku = sudoku;
    aux->next = p;
    return aux;
}

Pilha* push2 (Pilha *p, int **sudoku) {
    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->topo.sudoku = sudoku;
    aux->next = p;
    return aux;
}

Pilha* pop (Pilha *p, int mat[9][9]) {
    if (empty(p)) {
        printf("pilha vazia!");
        exit(1); /*aborta programa*/
    }

    int i, j;

    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            mat[i][j] = p->topo.sudoku[i][j];
        }
    }
    return p->next;
}

int empty (Pilha *p) {
    return (p == NULL);
}

void free_stack (Pilha *p) {
    Pilha *aux;
    Pilha *pi = p;
    while(pi->next != NULL) {
        aux = pi->next;
        free(pi);
        pi = aux;
    }
    free(pi);
}
