#include <stdlib.h>
#include <assert.h>
#include "trimatrix.h"

void QRA(trimatrix * T)
{
	// function declarations
	matrix QRdecomp(matrix * A);
	int FindZero(trimatrix * T);
	double GetShift(trimatrix * T);
	// get size
	const int N = T->rows; assert(N == T->cols);
	if (N == 1)
	{ return; }
	else
	{
	int k = FindZero(T); // see if we can deflate