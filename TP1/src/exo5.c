#include <stdio.h>
#include <stdlib.h>    
#include <omp.h>
#include <time.h>

int OMP_NUM_THREADS = 2;

int main (int argc, char** argv) {
    omp_set_num_threads(OMP_NUM_THREADS);

    int i;
    float K = 2.f;
    int size = 1700000000;
    float * TAB1 = (float *) malloc( size * sizeof(float) );
    float * TAB2 = (float *) malloc( size * sizeof(float) );
    float * TAB3 = (float *) malloc( size * sizeof(float) );

    //for(i = 0; i < size; i++) { TAB1[i] = rand(); TAB2[i] = rand(); TAB3[i] = rand(); }

    double t0 = omp_get_wtime();

    for(i = 0; i < size; i++) {
        TAB3[i] = TAB1[i] + TAB2[i] * K;
    }

    printf("Temps d'execution : %f\n", omp_get_wtime() - t0);

    return 0;
}