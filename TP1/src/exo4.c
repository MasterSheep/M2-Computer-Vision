#include <stdio.h>
#include <xmmintrin.h>
#include <omp.h>
#include <math.h>

int OMP_NUM_THREADS = 4;

int main (int argc, char** argv) {
    omp_set_num_threads(OMP_NUM_THREADS);

    double t0 = omp_get_wtime();
    static long nb_pas = 2100000000;
    double pas;
    int i; double x, pi, som = 0.0;
    pas = 1.0 / (double) nb_pas;

    #pragma omp parallel for reduction (+:som) private (x)    
    for (i = 0 ;i < nb_pas; i++){
        x = (i + 0.5) * pas;
        som = som + 4.0 / (1.0 + x * x);
    }
    

    pi = pas * som;

    printf("PI   = %f\n", pi);
    printf("Math = %f\n", M_PI);
    printf("Temps d'execution : %f\n", omp_get_wtime() - t0);

    return 0;
}