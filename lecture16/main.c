#include "stdio.h"
#include "time.h"
#include "assert.h"
#include "stdlib.h"
#include "trimatrix.h"
#include "matrix.h"


int main()
{
	// Get dimensions
	int N;
	printf("Matrix multiplication row-wise vs col-wise access\n");
	printf(" Input N: ");
	scanf("%i",&N);
	assert(N>0);
	// Create matrix
	matrix create_random_matrix(const int, const int);
	matrix A = create_random_matrix(N,N);

	// Clock times
	clock_t time0,time1,time2;

	// Matrix multiply
	time0 = clock();
	matrix_mult(&A,&A);
	time1 = clock();
	matrix_mult_v2(&A,&A);
	time2 = clock();

	printf("%11.5e\n", (double)time0);
	printf("%11.5e\n", (double)time1);
	printf("%11.5e\n", (double)time2);
	
	double cpu_time1 = ((double)(time1-time0))/((double)(CLOCKS_PER_SEC));
	double cpu_time2 = ((double)(time2-time1))/((double)(CLOCKS_PER_SEC));
	printf(" row-wise multiplication cpu time = %11.5e\n",cpu_time1);
	printf(" col-wise multiplication cpu time = %11.5e\n",cpu_time2);


	/*
	//QRA

	void QRA(trimatrix* T);
	void Hessenberg(const matrix* A, trimatrix* T);
	trimatrix T = new_trimatrix(N);


	A = create_random_matrix(N,N);


	print_matrix(&A);

	// DO QRA transformation

	Hessenberg(&A,&T);
	time1 = clock();
	print_trimatrix(&T);

	QRA(&T);
	
	time2 = clock();

	printf("\n Eigenvalues of A:\n");
	for (int i=1; i<=N; i++)
	{ printf(" lambda(%3i) = %24.16e\n",i,tget(&T,i,i)); }
	printf("\n");

	 cpu_time1 = ((double)(time1-time0))/((double)(CLOCKS_PER_SEC));
	 cpu_time2 = ((double)(time2-time1))/((double)(CLOCKS_PER_SEC));
	printf(" time for A -> T = %11.5e\n",cpu_time1);
	printf(" time for QTQ -> eigenvalues of A = %11.5e\n",cpu_time2);
*/

	//Transpose
	// Get dimensions
	N=0; int stride=0;
	printf(" Input N: \n"); scanf("%i",&N);
	printf(" Input stride: \n"); scanf("%i",&stride);
	assert(N>0); assert(stride >0); assert(stride <=N);

	A = create_random_matrix(N,N);
	matrix B = new_matrix(N,N);

	while(stride <=N && N%stride!=0)
	{ stride = stride+1; }

	printf(" N = %i\n",N);
	printf(" stride = %i\n",stride);

	// Stride 1 access
	time0 = clock();
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
		{
			mget(B,j,i) = mget(A,i,j);
		}
	time1 = clock();

	// Stride "stride" access (version 1) col-wise
	for (int ii=1; ii<N; ii+=stride)
		for (int i=ii; i<ii+stride; i++)
			for (int jj=1; jj<N; jj+=stride)
				for (int j=jj; j<jj+stride; j++)
				{
					mget(B,j,i) = mget(A,i,j);
				}
	time2 = clock();

	// Stride "stride" access (version 2) block-wise
	for (int ii=1; ii<N; ii+=stride)
		for (int jj=1; jj<N; jj+=stride)
			for (int i=ii; i<ii+stride; i++)
				for (int j=jj; j<jj+stride; j++)
				{
					mget(B,j,i) = mget(A,i,j);
				}
	clock_t time3 = clock();

	// Report times
	 cpu_time1 = ((double)(time1-time0))/((double)(CLOCKS_PER_SEC));
	 cpu_time2 = ((double)(time2-time1))/((double)(CLOCKS_PER_SEC));
	double cpu_time3 = ((double)(time3-time2))/((double)(CLOCKS_PER_SEC));
	printf(" brute force transpose = %11.5e\n",cpu_time1);
	printf(" col-wise stride transpose = %11.5e\n",cpu_time2);
	printf(" block-wise stride transpose = %11.5e\n",cpu_time3);
	delete_matrix(&A);
	//delete_trimatrix(&T);
}


matrix create_random_matrix(const int NumRows, const int NumCols)
{
	srand((unsigned)time(NULL));
	matrix A = new_matrix(NumRows,NumCols);
	for (int i = 1; i <= NumRows; i++)
		for (int j = 1; j <= i; j++)
		{
			double tmp = ((double)rand()) / ((double)RAND_MAX);
			tmp = (double)((int)(10000.0 * tmp)) / 10000.0;
			mget(A, i, j) = tmp;
		}
	for (int i = 1; i <= (NumRows - 1); i++)
		for (int j = (i + 1); j <= NumRows; j++)
		{ mget(A, i, j) = mget(A, j, i); }
	return A;
}

