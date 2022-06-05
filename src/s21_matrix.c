#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    matrix_t matrix;
    matrix.columns = columns;
    matrix.rows = rows;
    if ((matrix.matrix = (double **)malloc(rows * sizeof(double *))) == NULL)
        return 1;
    for (size_t i = 0; i < rows; i++) {
        if (((matrix.matrix[i] = (double *)malloc(columns * sizeof(double))) == NULL)) {
            for (size_t j = 0; j < i; j++) {
                free(matrix.matrix[j]);
            }
            free(matrix.matrix);
            return 1;
        }
    }
    result = &matrix;
    return 0;
}