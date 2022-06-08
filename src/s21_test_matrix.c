// Copyright 2022 <Zaharov Andru>
#include <check.h>

#include "s21_matrix.h"

START_TEST(s21_create_matrix_test) {
    matrix_t matrix;
    ck_assert_int_eq(s21_create_matrix(0, 0, &matrix), 1);
    ck_assert_int_eq(s21_create_matrix(2, 2, &matrix), 0);
    ck_assert_int_eq(s21_create_matrix(2, -2, &matrix), 1);
    ck_assert_int_eq(s21_create_matrix(-2, 2, &matrix), 1);
    s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test) {
    matrix_t matrix;
    s21_create_matrix(2, 2, &matrix);
    ck_assert_int_eq(empty_one_matrix(&matrix), 1);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(empty_one_matrix(&matrix), 0);
}
END_TEST

START_TEST(s21_eq_matrix_test) {
    matrix_t matrix;
    matrix_t matrix_test;
    s21_create_matrix(2, 2, &matrix);
    matrix.matrix[0][0] = 1.4567890;
    matrix.matrix[0][1] = 1.4567890;
    matrix.matrix[1][0] = 1.4567890;
    matrix.matrix[1][1] = 1.4567890;
    matrix_copy(&matrix, &matrix_test);
    ck_assert_int_eq(s21_eq_matrix(&matrix, &matrix_test), 1);
    matrix.matrix[0][0] = 1.4567840;
    ck_assert_int_eq(s21_eq_matrix(&matrix, &matrix_test), 0);
    matrix.matrix[0][0] = -1.4567890;
    matrix_test.matrix[0][0] = -1.4567890;
    ck_assert_int_eq(s21_eq_matrix(&matrix, &matrix_test), 1);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(s21_eq_matrix(&matrix, &matrix_test), 0);
    s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(s21_sum_matrix_test) {
    matrix_t matrix;
    matrix_t matrix_test;
    matrix_t result;
    s21_create_matrix(2, 2, &matrix);
    matrix.matrix[0][0] = 1.4567890;
    matrix.matrix[0][1] = 1.4567890;
    matrix.matrix[1][0] = 1.4567890;
    matrix.matrix[1][1] = 1.4567890;
    matrix_copy(&matrix, &matrix_test);
    ck_assert_int_eq(s21_sum_matrix(&matrix, &matrix_test, &result), 0);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(s21_sum_matrix(&matrix, &matrix_test, &result), 1);
    // s21_remove_matrix(&matrix);
    s21_remove_matrix(&matrix_test);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test) {
    matrix_t matrix;
    matrix_t matrix_test;
    matrix_t result;
    s21_create_matrix(2, 2, &matrix);
    matrix.matrix[0][0] = 1.4567890;
    matrix.matrix[0][1] = 1.4567890;
    matrix.matrix[1][0] = 1.4567890;
    matrix.matrix[1][1] = 1.4567890;
    matrix_copy(&matrix, &matrix_test);
    ck_assert_int_eq(s21_sub_matrix(&matrix, &matrix_test, &result), 0);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(s21_sub_matrix(&matrix, &matrix_test, &result), 1);
    s21_remove_matrix(&matrix_test);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test) {
    matrix_t matrix;
    matrix_t result;
    s21_create_matrix(2, 2, &matrix);
    matrix.matrix[0][0] = 1.4567890;
    matrix.matrix[0][1] = 1.4567890;
    matrix.matrix[1][0] = 1.4567890;
    matrix.matrix[1][1] = 1.4567890;

    ck_assert_int_eq(s21_mult_number(&matrix, 2, &result), 0);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(s21_mult_number(&matrix, 2, &result), 1);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test) {
    matrix_t matrix;
    matrix_t matrix_test;
    matrix_t result;
    s21_create_matrix(2, 2, &matrix);
    matrix.matrix[0][0] = 1.4567890;
    matrix.matrix[0][1] = 1.4567890;
    matrix.matrix[1][0] = 1.4567890;
    matrix.matrix[1][1] = 1.4567890;
    matrix_copy(&matrix, &matrix_test);
    ck_assert_int_eq(s21_mult_matrix(&matrix, &matrix_test, &result), 0);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(s21_mult_matrix(&matrix, &matrix_test, &result), 1);
    s21_create_matrix(2, 2, &matrix);
    s21_create_matrix(3, 3, &matrix);
    ck_assert_int_eq(s21_mult_matrix(&matrix, &matrix_test, &result), 1);
    s21_remove_matrix(&matrix);
    s21_remove_matrix(&matrix_test);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test) {
    matrix_t matrix;
    matrix_t result;
    s21_create_matrix(2, 2, &matrix);
    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = 7;
    matrix.matrix[1][0] = 4;
    matrix.matrix[1][1] = 3;
    ck_assert_int_eq(s21_transpose(&matrix, &result), 0);
    s21_remove_matrix(&matrix);
    ck_assert_int_eq(s21_transpose(&matrix, &result), 1);
    s21_create_matrix(4, 2, &matrix);
    ck_assert_int_eq(s21_transpose(&matrix, &result), 0);
    s21_remove_matrix(&matrix);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test) {
    matrix_t check;
    matrix_t result;
    s21_create_matrix(3, 3, &check);
    check.matrix[0][0] = 1;
    check.matrix[0][1] = 2;
    check.matrix[0][2] = 3;
    check.matrix[1][0] = 0;
    check.matrix[1][1] = 4;
    check.matrix[1][2] = 2;
    check.matrix[2][0] = 5;
    check.matrix[2][1] = 2;
    check.matrix[2][2] = 1;
    ck_assert_int_eq(s21_calc_complements(&check, &result), 0);
    s21_remove_matrix(&check);
    ck_assert_int_eq(s21_calc_complements(&check, &result), 1);
    s21_create_matrix(5, 3, &check);
    ck_assert_int_eq(s21_calc_complements(&check, &result), 1);
    s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_determinant_test) {
    matrix_t check;
    double res;
    s21_create_matrix(4, 4, &check);
    add_numbers_matrix(&check);
    ck_assert_int_eq(s21_determinant(&check, &res), 0);
    s21_create_matrix(5, 4, &check);
    ck_assert_int_eq(s21_determinant(&check, &res), 1);
    s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
    matrix_t A;
    matrix_t result;
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), 0);
    s21_remove_matrix(&A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), 1);
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
