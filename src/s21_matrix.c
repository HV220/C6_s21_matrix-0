#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    result->columns = columns;
    result->rows = rows;
    if (rows > 0 && columns > 0) {
        if ((result->matrix = (double **)calloc(rows, sizeof(double *))) ==
            NULL)
            return 1;
        for (int i = 0; i < rows; i++) {
            if (((result->matrix[i] =
                      (double *)calloc(columns, sizeof(double))) == NULL)) {
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
    if (A->matrix) {
        for (int i = 0; i < A->columns; i++) {
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
                    return FAILURE;
                }
            }
        }
    }
    return SUCCESS;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error = FAILURE;
    if (compare_matrix(A, B) && empty_two_matrix(A, B)) {
        if (s21_create_matrix(A->rows, A->columns, result)) {
            error = SUCCESS;
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = (A->matrix[i][j] + B->matrix[i][j]);
                }
            }
        }
    } else {
        error = INCORRECT;
    }
    return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error = FAILURE;
    if (compare_matrix(A, B) && empty_two_matrix(A, B)) {
        if (s21_create_matrix(A->rows, A->columns, result)) {
            error = SUCCESS;
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = (A->matrix[i][j] - B->matrix[i][j]);
                }
            }
        }
    } else {
        error = INCORRECT;
    }
    return error;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int error = FAILURE;
    if (empty_one_matrix(A)) {
        if (!(s21_create_matrix(A->rows, A->columns, result))) {
            error = SUCCESS;
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
    int error = 1;
    if (empty_two_matrix(A, B)) {
        if (A->columns == B->rows) {
            if (!s21_create_matrix(A->rows, B->columns, result)) {
                error = 0;
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
            error = 2;
        }
    } else {
        error = 2;
    }
    return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int error = 0;
    if (!empty_one_matrix(A)) {
        error = 1;
    } else {
        if (!s21_create_matrix(A->columns, A->rows, result)) {
            int tmp = 0;
            for (int i = 0; i < result->rows; i++) {
                for (int j = 0; j < result->columns; j++) {
                    result->matrix[i][j] = A->matrix[j][tmp];
                }
                tmp++;
            }
        } else {
            error = 2;
        }
    }
    return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int error = 0;
    if (!empty_one_matrix(A)) {
        error = 1;
    } else {
        if (!s21_create_matrix(A->rows, A->columns, result)) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                }
            }

        } else {
            error = 2;
        }
    }
    return error;
}

int compare_matrix(matrix_t *A, matrix_t *B) {
    if (A->columns == B->columns && A->rows == B->rows) return SUCCESS;
    return FAILURE;
}

int empty_two_matrix(matrix_t *A, matrix_t *B) {
    if ((A->columns > 0) && (B->columns > 0) && (A != NULL) && (B != NULL) &&
        (A->matrix != NULL) && (B->matrix != NULL)) {
        return SUCCESS;
    }
    return FAILURE;
}
int empty_one_matrix(matrix_t *A) {
    if ((A->columns > 0) && (A != NULL) && (A->matrix != NULL)) {
        return SUCCESS;
    }
    return FAILURE;
}
int calc_minor(matrix_t *A) {
    for (int i = 0; i < count; i++) {
        /* code */
    }
}