#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    result->columns = columns;
    result->rows = rows;
    if(rows > 0 && columns > 0) {
    if ((result->matrix = (double **)calloc(rows, sizeof(double *))) == NULL)
        return 1;
    for (int i = 0; i < columns; i++) {
        if (((result->matrix[i] = (double *)calloc(columns, sizeof(double))) == NULL)) {
            for (int j = 0; j < i; j++) {
                free(result->matrix[j]);
            }
            free(result->matrix);
            return 1;
        }
    }
    }
    return 0;
}

void s21_remove_matrix(matrix_t *A) {
    if (A -> matrix) {
        for (int i = 0; i < A->columns; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix); }
    A->columns = 0;
    A->rows = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    
    if (compare_matrix(A,B) && empty_matrix(A,B))
    {
        for (int i = 0; i < A->rows; i++)
        {
            for (int j = 0; j < A->columns; j++)
            {
                if ((fabs(A->matrix[i][j] - B->matrix[i][j])) < EPS)
                {
                    return FAILURE;
                }             
            }          
        }  
    }
    return SUCCESS;
}

int compare_matrix(matrix_t *A, matrix_t *B) {
    int error = FAILURE;
    if (A->columns == B->columns && A->rows == B->rows) {error = SUCCESS;}
    return error;
}

int empty_matrix(matrix_t *A, matrix_t *B) {
   int error = FAILURE; 
    if (A->columns > 0 && B->columns > 0 && A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL)
    {
        error = SUCCESS;
    }
    return error;
}
