int** aloca_matriz (int colunas, int linhas);
void imprime_matriz (int mat[9][9]);
int** submatriz (int li, int col, int sudoku[9][9]);
void numeros_possiveis (int li, int col, int **submat, int sudoku[9][9], int numeros[]);
void procura_faceis (int sudoku[9][9]);
int resolve (int sudoku[9][9]);
int minimo (int li, int col, int sudoku[9][9]);
int num_possibilidades (int li, int col, int sudoku[9][9], int solucoes[]);
int resolvida (int sudoku[9][9]);
int** copia_mat (int sudoku[9][9]);
void n_imprime (int **mat, int n);

