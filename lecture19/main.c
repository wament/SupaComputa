#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include <math.h>
#ifdef _OPENMP
# include <omp.h>
#endif

int main(int argc, char* argv[])
{
    void usage(const char* prog_name);
    if (argc != 3) { usage(argv[0]); }
    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);
    if (thread_count <= 0)
    {
        usage(argv[0]);
    }

    srand(time(NULL));
    vector v = new_vector(N);
    double norm = 0.0;
    for (int i = 1; i <= N; i++) {
        vget(v, i) = (double) rand() % 50;
    }

    const double time1 = omp_get_wtime();

    //fine grain parallelization
#   pragma omp parallel num_threads(thread_count)
    {
        //compute |x_i|^2 for x_i in v
#       pragma omp for reduction(+:norm)
        for (int i = 1; i <= N; i++) {
            norm += pow(abs(vget(v, i), 2);
        }
        //make sure all threads are done
#       pragma omp barrier

        //take the sqrt (only once)
#       pragma omp single
        norm = sqrt(norm);

        //divide x_i by norm to normalize v
#       pragma omp for
        for (int i = 1; i <= N; i++) {
            vget(v, i) = vget(v, i) / norm;
        }
    }

    const double time2 = omp_get_wtime();
    const double clock_time = time2 - time1;

    //check duration of computation
    printf(" With %i threads, computing %i numbers, clock_time = %11.5e (sec)\n", thread_count, N, clock_time);


    delete_vector(&v);
    return 0;
}

void usage(const char* prog_name)
{
    fprintf(stderr, "usage: %s <thread_count> <vector size>\n", prog_name);
    fprintf(stderr, " thread_count should be positive\n");
    fprintf(stderr, " N should be positive\n");
    exit(1);
}