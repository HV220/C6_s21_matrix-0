#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    result->columns = columns;
    result->rows = rows;
    int error = SUCCESS;
    if (rows > 0 && columns > 0) {
        if ((result->matrix = (double **)calloc(rows, sizeof(double *))) ==
            NULL) {error = FAILURE; } else {
        for (int i = 0; i < rows; i++) {
            if (((result->matrix[i] =
                      (double *)calloc(columns, sizeof(double))) == NULL)) {
                for (int j = 0; j < i; j++) {
                    free(result->matrix[j]);
                }
                free(result->matrix);
                error = FAILURE;
            }
        } }
    } else { error = FAILURE; }
    return error;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix) {
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
    }
    A->columns = 0;
    A->rows = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    if (compare_matrix(A, B) && empty_two_matrix(A, B)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if ((fabs(A->matrix[i][j] - B->matrix[i][j])) < EPS) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error = SUCCESS;
    if (compare_matrix(A, B) && empty_two_matrix(A, B)) 
    {
        if (s21_create_matrix(A->rows, A->columns, result)) { error = FAILURE;} else {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = (A->matrix[i][j] + B->matrix[i][j]);
                }
            }
        }
    } 
    else 
    {
        error = INCORRECT;
    }
    return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
   int error = SUCCESS;
    if (compare_matrix(A, B) && empty_two_matrix(A, B)) 
    {
        if (s21_create_matrix(A->rows, A->columns, result)) { error = FAILURE;} else {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = (A->matrix[i][j] - B->matrix[i][j]);
                }
            }
        }
    } 
    else 
    {
        error = INCORRECT;
    }
    return error;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int error = SUCCESS;
    if (empty_one_matrix(A)) {
        if (s21_create_matrix(A->rows, A->columns, result)) {error = FAILURE;} else {        
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = number * A->matrix[i][j];
                }
            }
        }
    } else {
        error = INCORRECT;
    }
    return error;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error = SUCCESS;
    if (empty_two_matrix(A, B)) {
        if (A->columns == B->rows) {
            if (s21_create_matrix(A->rows, B->columns, result)) {error = FAILURE;} else {
                int tmp = 0;
                int tmp_columns = 0;
                for (int i = 0; i < result->rows; i++, tmp++) {
                    for (int j = 0; j < result->columns; j++) {
                        for (int k = 0; k < A->columns; k++) {
                            result->matrix[i][j] += (A->matrix[tmp][k]) *
                                                    (B->matrix[k][tmp_columns]);
                        }
                        tmp_columns++;
                    }
                    tmp_columns = 0;
                }
            }
        } else {
            error = INCORRECT;
        }
    } else {
        error = INCORRECT;
    }
    return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int error = SUCCESS;
    if (!empty_one_matrix(A)) {
        error = FAILURE;
    } else {
        if (s21_create_matrix(A->columns, A->rows, result)) {error = FAILURE;} else {
            int tmp = 0;
            for (int i = 0; i < result->rows; i++) {
                for (int j = 0; j < result->columns; j++) {
                    result->matrix[i][j] = A->matrix[j][tmp];
                }
                tmp++;
            }
        }
    }
    return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int error = SUCCESS;
    if (!empty_one_matrix(A) && compare_square_matrix(A)) {
        error = FAILURE;
    } else {
        if (s21_create_matrix(A->columns, A->rows, result)) {error = FAILURE;} else {
            matrix_t tmp;
            double d_tmp;
            for (int i = 0; i < result->rows; i++) {
                for (int j = 0; j < result->columns; j++) {
                    if(equalise_matrix(A, j, i, &tmp)) {error = FAILURE; break;}
                    s21_determinant(&tmp,&d_tmp);
                    result->matrix[i][j] = pow(-1, i + j) * d_tmp;
                }
            }
        }
    }
    return error;
}

int s21_determinant(matrix_t *A, double *result) {
int error = SUCCESS;
double test = 0.0;
    if (!(compare_square_matrix(A)) && !(empty_one_matrix(A)))
    {
        error = FAILURE;
    } else {
        if (A->rows == 1)
        {
            test = A->matrix[0][0];
        }
        if (A->rows == 2)
        {
            test = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
        }
        if (A->rows > 2)
        {   matrix_t matrix;   

            
            for (int i = 0; i < A->rows; i++)
            {
            if (equalise_matrix(A, 0, i, &matrix))
            {
                error = FAILURE;
                break;
            }
                s21_determinant(&matrix, result);
                test += A->matrix[i][0] * pow(-1, i) * *result;   
                s21_remove_matrix(&matrix);
            }
            }
        }
        *result = test;
    return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int error = SUCCESS;
    if (!empty_one_matrix(A) && !compare_square_matrix(A))
    {
        error = FAILURE;
    } else {
        double deter;
        if (!s21_determinant(A, &deter))
        {
            if (fabs(deter) > EPS)
            {
                matrix_t tmp;
                minor_complements(A, result);
                s21_transpose(result, &tmp);
                for (int i = 0; i < result->rows; i++)
                {
                    for (int j = 0; j < result->columns; j++)
                    {
                        result->matrix[i][j] = tmp.matrix[i][j];
                    }
                }
                s21_remove_matrix(&tmp);
            } else {
                error = INCORRECT;
            }
            
        } else {
            error = INCORRECT;
        }
        
    }
    return error;
}

int compare_matrix(matrix_t *A, matrix_t *B) {
    int error = 0;
    if (A->columns == B->columns && A->rows == B->rows) {error = 1;}
    return error;
}

int empty_two_matrix(matrix_t *A, matrix_t *B) {
    int error = 0;
    if ((A->columns > 0) && (B->columns > 0) && (A != NULL) && (B != NULL) &&
        (A->matrix != NULL) && (B->matrix != NULL)) {
        error = 1;
    }
    return error;
}

int empty_one_matrix(matrix_t *A) {
    int error = 0;
    if ((A->columns > 0) && (A->columns > 0) && (A != NULL) && (A->matrix != NULL)) {
        error = 1;
    }
    return error;
}

int compare_square_matrix(matrix_t *A) {
    int error = 0;
    if (A->columns == A->rows)
    {
        error = 1;
    }
    return error;
}

int equalise_matrix(matrix_t *A, int row, int column, matrix_t *matrix) {
    int error = 0;
    if (s21_create_matrix(A->rows - 1, A->columns - 1, matrix))
    {
        error = 1;
    } else {
        for (int i = 0, y = 0; i < A->rows; i++)
        {
            if (i != column)
            {
                for (int j = 0, x = 0; j < A->rows; j++)
                {
                    if (j != row)
                    {
                        matrix->matrix[y][x] = A->matrix[i][j];
                        x++;
                    }      
                }
                y++;
            }
        }
    }
    return error;
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            printf("%f ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_numbers_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
           matrix->matrix[i][j] = (rand() % (40-10+1)+5);
        }
    }
}

int minor_complements(matrix_t *A, matrix_t *result) {
    int error = SUCCESS;
    if (!empty_one_matrix(A) && compare_square_matrix(A)) {
        error = FAILURE;
    } else {
        if (s21_create_matrix(A->columns, A->rows, result)) {error = FAILURE;} else {
            matrix_t tmp;
            double d_tmp;
            for (int i = 0; i < result->rows; i++) {
                for (int j = 0; j < result->columns; j++) {
                    if(equalise_matrix(A, j, i, &tmp)) {error = FAILURE; break;}
                    s21_determinant(&tmp,&d_tmp);
                    result->matrix[i][j] = d_tmp;
                }
            }
        }
    }
    return error;
}