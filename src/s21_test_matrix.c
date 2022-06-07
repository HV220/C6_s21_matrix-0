#include <check.h>

#include "s21_matrix.h"

START_TEST(s21_create_matrix_test) {

}
END_TEST

START_TEST(s21_remove_matrix_test) {

}
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
    matrix_t check;
    matrix_t result;
    printf("\n21_calc_complements_test\n");
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
    s21_calc_complements(&check, &result);
    print_matrix(&check);
    print_matrix(&result);
}
END_TEST

START_TEST(s21_determinant_test) {
    matrix_t check;
    double res;
    s21_create_matrix(4, 4, &check);
    add_numbers_matrix(&check);
    s21_determinant(&check, &res);
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
    matrix_t A;
    matrix_t result;
    printf("\ns21_inverse\n");
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
    s21_inverse_matrix(&A, &result);
    print_matrix(&A);
    print_matrix(&result);
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
