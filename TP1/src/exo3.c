#include <stdio.h>
#include <xmmintrin.h>
#include <omp.h>

int OMP_NUM_THREADS = 4;

int main(int argc, char** argv) {
	omp_set_num_threads(OMP_NUM_THREADS);
    int i;

    #pragma omp parallel for
    
    for(i = 1; i <= 50; i++) {
        int nb_thread = omp_get_thread_num();
        printf("Valeur du for : %d (core %d)\n",i , nb_thread);
    }
    

    return 0;
}
