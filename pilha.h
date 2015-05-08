#include <stdio.h>
#include <stdlib.h>

typedef struct estado{
    int** sudoku;
} Estado;

typedef struct Pilha {
    Estado topo;
    struct Pilha *next;
} Pilha;

Pilha* create_stack ();
Pilha* push (Pilha *p, int sudoku[9][9]);
Pilha* pop (Pilha *p, int mat[9][9]);
int empty (Pilha *p);
void free_stack (Pilha *p);
