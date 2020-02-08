#include <stdio.h>
#include <stdlib.h> // includes malloc(), free(), realloc()

#include "ex3.h" // do not modify this file

// put your function prototypes for additional helper functions below:

// parse input stream and perform corresponding matrix operation on input mat
// assume input stream is fully correct
#define ARR_LEN(array, length){ length =  sizeof(array) / sizeof(array[0]); }
static matrix *mat;
void print_matrix_wrap(matrix *m, int *parameters)
{
    print_matrix(mat);
}

void create_matrix_wrap(matrix *m, int *parameters)
{
    parameters = (int *)malloc(sizeof(int) * 2);
    read_numbers(parameters, 2);
    
//    printf("%p\n",mat);
    mat = create_matrix(parameters[0], parameters[1]);
//
//    printf("%s",mat);
    free(parameters);
}

void add_row_wrap(matrix *m, int *parameters)
{
    //printf("%d",mat->num_cols);
    parameters = (int *)malloc(sizeof(int) * mat->num_cols);
    read_numbers(parameters, mat->num_cols);
    add_row(mat, parameters);
    free(parameters);
}

void add_col_wrap(matrix *m, int *parameters)
{
    parameters = (int *)malloc(sizeof(int) * mat->num_rows);
    read_numbers(parameters, mat->num_rows);
    add_col(mat, parameters);
    free(parameters);
}

void increment_wrap(matrix *m, int *parameters)
{
    parameters = (int *)malloc(sizeof(int));
    read_numbers(parameters, 1);
    increment(mat, parameters[0]);
    //void (*op_ptr)(int *, int) = increment_single;
 
    //element_wise_op(mat, parameters[0],op_ptr);
    free(parameters);
}



void scalar_multiply_wrap(matrix *m, int *parameters)
{
    parameters = (int *)malloc(sizeof(int));
    read_numbers(parameters, 1);
    scalar_multiply(mat, parameters[0]);
    //     void (*op_ptr)(int *, int) = scalar_multiply_single;
    // element_wise_op(mat, parameters[0],op_ptr);
    free(parameters);
}

void scalar_multiply_single(int *x, int y) {
for (int i = 0; i < sizeof(x)/sizeof(int); i++)
{
    x[i]*=y;
}
}

void scalar_divide_wrap(matrix *m, int *parameters)
{
    parameters = (int *)malloc(sizeof(int));
    read_numbers(parameters, 1);
     scalar_divide(mat, parameters[0]);
    //    void (*op_ptr)(int *, int) = scalar_divide_single;
    //element_wise_op(mat, parameters[0],op_ptr);
    free(parameters);
}

void scalar_divide_single(int *x, int y) {
for (int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
{
    x[i]/=y;
}
}

void scalar_power_wrap(matrix *m, int *parameters)
{
    parameters = (int *)malloc(sizeof(int));
    read_numbers(parameters, 1);
    scalar_power(mat, parameters[0]);
     //   void (*op_ptr)(int *, int) = scalar_power_single;
    //element_wise_op(mat, parameters[0],op_ptr);
    free(parameters);
}

void scalar_power_single(int *x, int y) {
for (int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
{
    x[i]=compute_power(x[i],y);
}
}

int compute_power(int a, int b)
{
    int result = 1;
    while (b != 0)
    {
        result *= a;
        --b;
    }
    return result;
}

void delete_matrix_wrap(matrix *m, int *parameters)
{
    delete_matrix(mat);
}

void my_run()
{
    void (*fun_ptr_arr[])(matrix *, int *) = {print_matrix_wrap, create_matrix_wrap, add_row_wrap, add_col_wrap, increment_wrap,
                                              scalar_multiply_wrap, scalar_divide_wrap, scalar_power_wrap, delete_matrix_wrap};

 
    while (1)
    {
        
        int instruction;
        int *parameters;

        if (scanf("%d", &instruction) <= 0)
            break;
        
        (*fun_ptr_arr[instruction])(mat, parameters);
        
    }
}

// read n numbers into arr
void read_numbers(int *arr, int n)
{
    int idx;
    for (idx = 0; idx < n; ++idx)
    {
        if (scanf("%d", arr + idx) <= 0)
        {
            fprintf(stderr, "Failed to read numbers\n");
            break;
        }
    }
}
