#include <check.h>

#include "s21_matrix.h"

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            printf("%f ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void create_compare_matrix(int rows, int columns, double **matrix) {
    int error = 0;
    if ((matrix = (double **)malloc(columns * sizeof(double *))) == NULL) {
        error = 1;
    }
    if (!error) {
        for (int i = 0; i < columns; i++) {
            if (((matrix[i] = (double *)malloc(rows * sizeof(double))) ==
                 NULL)) {
                for (int j = 0; j < i; j++) {
                    free(matrix[j]);
                }
                free(matrix);
            }
        }
    }
}

START_TEST(s21_create_matrix_test) {
    matrix_t matrix;
    //matrix_t matrix2;
    matrix_t res;
    s21_create_matrix(2, 4, &matrix);
    //s21_create_matrix(2, 3, &matrix2);
    matrix.matrix[0][0] = 1;
    matrix.matrix[0][1] = 2;
    matrix.matrix[0][2] = 3;
    matrix.matrix[0][3] = 4;
    matrix.matrix[1][0] = 5;
    matrix.matrix[1][1] = 6;
    matrix.matrix[1][2] = 7;
    matrix.matrix[1][3] = 8;

    // matrix2.matrix[0][0] = 1;
    // matrix2.matrix[0][1] = -1;
    // matrix2.matrix[0][2] = 1;
    // matrix2.matrix[1][0] = 2;
    // matrix2.matrix[1][1] = 3;
    // matrix2.matrix[1][2] = 4;
    s21_transpose(&matrix, &res);
    print_matrix(&matrix);
    //print_matrix(&matrix2);
    print_matrix(&res);
    //printf("res%d\n", r);
    // s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test) {}
END_TEST

START_TEST(s21_eq_matrix_test) {
    // test
}
END_TEST

START_TEST(s21_sum_matrix_test) {
    // test
}
END_TEST

START_TEST(s21_sub_matrix_test) {
    // test
}
END_TEST

START_TEST(s21_mult_number_test) {
    // test
}
END_TEST

START_TEST(s21_mult_matrix_test) {
    // test
}
END_TEST

START_TEST(s21_transpose_test) {
    // test
}
END_TEST

START_TEST(s21_calc_complements_test) {
    // test
}
END_TEST

START_TEST(s21_determinant_test) {
    // test
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
    // test
}
END_TEST

int main() {
    Suite *suite = suite_create("S21_test_matrix");
    SRunner *srunner = srunner_create(suite);

    TCase *s21_create_matrixCase = tcase_create("s21_create_matrixCase");
    suite_add_tcase(suite, s21_create_matrixCase);
    tcase_add_test(s21_create_matrixCase, s21_create_matrix_test);

    TCase *s21_remove_matrixCase = tcase_create("s21_remove_matrixCase");
    suite_add_tcase(suite, s21_remove_matrixCase);
    tcase_add_test(s21_remove_matrixCase, s21_remove_matrix_test);

    TCase *s21_eq_matrixCase = tcase_create("s21_eq_matrixCase");
    suite_add_tcase(suite, s21_eq_matrixCase);
    tcase_add_test(s21_eq_matrixCase, s21_eq_matrix_test);

    TCase *s21_sum_matrixCase = tcase_create("s21_sum_matrixCase");
    suite_add_tcase(suite, s21_sum_matrixCase);
    tcase_add_test(s21_sum_matrixCase, s21_sum_matrix_test);

    TCase *s21_sub_matrixCase = tcase_create("s21_sub_matrixCase");
    suite_add_tcase(suite, s21_sub_matrixCase);
    tcase_add_test(s21_sub_matrixCase, s21_sub_matrix_test);

    TCase *s21_mult_numberCase = tcase_create("s21_mult_numberCase");
    suite_add_tcase(suite, s21_mult_numberCase);
    tcase_add_test(s21_mult_numberCase, s21_mult_number_test);

    TCase *s21_mult_matrixCase = tcase_create("s21_mult_matrixCase");
    suite_add_tcase(suite, s21_mult_matrixCase);
    tcase_add_test(s21_mult_matrixCase, s21_mult_matrix_test);

    TCase *s21_transposeCase = tcase_create("s21_transposeCase");
    suite_add_tcase(suite, s21_transposeCase);
    tcase_add_test(s21_transposeCase, s21_transpose_test);

    TCase *s21_calc_complementsCase = tcase_create("s21_calc_complementsCase");
    suite_add_tcase(suite, s21_calc_complementsCase);
    tcase_add_test(s21_calc_complementsCase, s21_calc_complements_test);

    TCase *s21_determinantCase = tcase_create("s21_determinantCase");
    suite_add_tcase(suite, s21_determinantCase);
    tcase_add_test(s21_determinantCase, s21_determinant_test);

    TCase *s21_inverse_matrixCase = tcase_create("s21_inverse_matrixCase");
    suite_add_tcase(suite, s21_inverse_matrixCase);
    tcase_add_test(s21_inverse_matrixCase, s21_inverse_matrix_test);

    srunner_run_all(srunner, CK_VERBOSE);
    int numbers_errors = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    return (numbers_errors) ? EXIT_FAILURE : EXIT_SUCCESS;
}
