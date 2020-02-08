#include <stdio.h>
#include <stdlib.h> // includes malloc(), free(), realloc()
#include <string.h> // includes memcpy()

#include "matrix.h" // do not modify this file

// put your function prototypes for additional helper functions below:

// implementation
matrix *create_matrix(int num_rows, int num_cols)
{
    matrix *m = (matrix *)malloc(sizeof(matrix));
    m->num_cols = num_cols;
    m->num_rows = num_rows;
    int **a = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++)
    {
        a[i] = (int *)malloc(num_cols * sizeof(int));
        for (int j = 0; j < num_cols; j++)
        {
            a[i][j] = 0;
        }
    }
    m->data = a;
    return m;
    
}

void add_row(matrix *mat, int *row)
{
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    a = (int **)realloc(a, (num_rows + 1) * sizeof(int *));
    a[num_rows]=(int *)malloc(num_cols * sizeof(int));
    for (int i = 0; i < num_cols; i++)
    {

        a[num_rows][i] = row[i];

    }
    mat->num_rows = num_rows + 1;
    mat->data=a;
}

void add_col(matrix *mat, int *col)
{
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    for (int i = 0; i < num_rows; i++)
    {
        a[i] = (int *)realloc(a[i], (num_cols + 1) * sizeof(int));
        a[i][num_cols] = col[i];
    }
    mat->num_cols = num_cols + 1;
    mat->data=a;
}

void increment(matrix *mat, int num)
{
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            a[i][j] += num;
        }
    }
}

void scalar_multiply(matrix *mat, int num)
{
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            a[i][j] *= num;
        }
    }
}

void scalar_divide(matrix *mat, int num)
{
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            a[i][j] /= num;
        }
    }
}
// int compute_power(int a, int b)
// {
//     int result = 1;
//     while (b != 0)
//     {
//         result *= a;
//         --b;
//     }
//     return result;
// }


void scalar_power(matrix *mat, int num)
{
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            a[i][j] = compute_power(a[i][j],num);
        }
    }
}

 void delete_matrix(matrix *mat)
{
    
    int num_rows=mat->num_rows;
    for(int i=0;i<num_rows;i++){
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

 void element_wise_op(matrix *mat, int num, void (*op_ptr)(int *, int))
 {
    int **a = mat->data;
    int num_cols = mat->num_cols;
    int num_rows = mat->num_rows;
    for (int i = 0; i < num_rows; i++)
    {
        op_ptr(a[i],num);
    }
 }


/*
    DO NOT MODIFY BELOW
*/
// print out matrix in row-major order
// elements in the same row are space-separated
// each row starts in a new line
void print_matrix(matrix *mat)
{
    int row_idx, col_idx;
    for (row_idx = 0; row_idx < mat->num_rows; ++row_idx)
    {
        for (col_idx = 0; col_idx < mat->num_cols; ++col_idx)
        {
            if (col_idx == mat->num_cols - 1)
            {
                printf("%d\n", mat->data[row_idx][col_idx]);
            }
            else
            {
                printf("%d ", mat->data[row_idx][col_idx]);
            }
        }
    }
}
