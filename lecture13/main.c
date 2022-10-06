#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "time.h"

int main()
{
    // Matrices
    matrix A = new_matrix(5,5);
    matrix B = new_matrix(5,5);
    srand( time(NULL) );
    

    for(int i=1; i<=5; i++ )
        for (int j=1; j<=5; j++ )
        {
            //set random values % 30 (1-30)
            mget(A,i,j) = (rand()%30);
            mget(B,i,j) = (rand()%30);
        }

    // Print matrices
    print_matrix(&A);
    print_matrix(&B);

    // Add/Subtract/Multiply matrices
    matrix Csum = matrix_add(&A,&B); print_matrix(&Csum);
    matrix Cdiff = matrix_sub(&A,&B); print_matrix(&Cdiff);
    matrix Cprod = matrix_mult(&A,&B); print_matrix(&Cprod);
    matrix Cdot = matrix_dot_mult(&A,&B); print_matrix(&Cdot);
    matrix Csquare = matrix_dot_mult(&A,&A); print_matrix(&Csquare);

    // Vectors
    vector x = new_vector(5);
    vector y = new_vector(5);

    //set random values % 30 (1-30)
    vget(x,1) = (rand()%30); vget(y,1) = (rand()%30);
    vget(x,2) = (rand()%30); vget(y,2) = (rand()%30);
    vget(x,3) = (rand()%30); vget(y,3) = (rand()%30);
    vget(x,4) = (rand()%30); vget(y,4) = (rand()%30);
    vget(x,5) = (rand()%30); vget(y,5) = (rand()%30);

    // Print vectors
    print_vector(&x);
    print_vector(&y);

    // Add/Subtract/Multiply vectors
    vector zsum = vector_add(&x,&y); print_vector(&zsum);
    vector zdiff = vector_sub(&x,&y); print_vector(&zdiff);
    double zdot = vector_dot_mult(&x,&y); print_scalar(&zdot);

    // Matrix vector multiply
    vector Ax = matrix_vector_mult(&A,&x);
    print_vector(&Ax);

    // Linear solve via Gaussian elimination
    vector soln = solve(&A,&x);
    print_vector(&soln);

    vector soln2 = solve(&B, &y);
    print_vector(&soln2);

    vector soln3 = solve(&Csum, &zsum);
    print_vector(&soln3);
}