# Sudoku Solver

A small (old) algorithim in C to solve sudokus.

This solver was made implementing stacks with linked lists concept. To implement it,
it was needed to create "states" of the game, that are multidimentional arrays, to be
stacked. 
 
Initial unsolved sudokus are written on the main(). It's possible to use the two
initial arrays I put in the main() and by default it's using the complex one.
 
##A little description of the functions used to solve the sudoku: 
 
###int** aloca_matriz (int colunas, int linhas); 

This function allocates an array. 
 
###void imprime_matriz (int mat[9][9]); 
 
Prints an array sized 9x9.
 
###void n_imprime (int **mat, int n); 
 
Prints an array of n positions.
 
###int resolvida (int sudoku[9][9]); 

Walks through the array and verifies if it was totally filled, which means it was
solved.
 
###int** copia_mat (int sudoku[9][9]); 
 
Copies the array received into a new one and returns it.
 
###int** submatriz (int li, int col, int sudoku[9][9]); 

Uses the indexes of the main array* to identify which subarray of 3x3 a given position _li_
x _col_ belongs to. 
 
###void numeros_possiveis (int li, int col, int **submat, int sudoku[9][9], int numeros[]); 
 
Fills the array _numeros[]_ with _true_ or _false_ (1 or 0) in case that the number
is already filled in the main array* in any of the spaces to be considered (line,
column and subarray of 3x3). This means this number is already in use and cannot be
used in the blank position the program is trying to fill.
 
###void procura_faceis (int sudoku[9][9]); 
 
Searchs for all the spaces with '0' that have only one possibility of filling and
fills it.
 
###int num_possibilidades (int li, int col, int sudoku[9][9], int solucoes[]); 
 
Verifies how many possibilities a given position has of filling itself, and returns
it. Also fills the array of solutions with the possible values.
 
###int minimo (int li, int col, int sudoku[9][9]); 
 
Walks through the array and verifies if a given position with '0' received is the
one which possess less possibilities of filling.
 
###int resolve (int sudoku[9][9]); 
 
Inits the resolution of the array, creating a stack, stacking the main array*.
Calls the function that solves all the trivial positions, verifies if it is
completely solved.
If not, it creates a routine: while the sudoku is not solved, it walks through
it and finds the number of possibilities of all the '0' that it finds in the way.
If there is no possibility, it pops an array.
If there are possibilities, it stacks all of them and after that, pops a new one,
searchs again for the trivial blanks, and verifies again if it is solved.


####*main array = the current state of the sudoku
