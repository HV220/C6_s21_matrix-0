#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <limits.h>
#define SUCCESS 0
#define FAILURE 1
#define INCORRECT 2

#define EPS 0.0000001

typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// add functions

int compare_matrix(matrix_t *A, matrix_t *B);
int empty_two_matrix(matrix_t *A, matrix_t *B);
int empty_one_matrix(matrix_t *A);
int compare_square_matrix(matrix_t *A);
void print_matrix(matrix_t *matrix);
int equalise_matrix(matrix_t *A, int i, int j, matrix_t *matrix);
void add_numbers_matrix(matrix_t *matrix);
#endif  //  SRC_S21_MATRIX_H_
