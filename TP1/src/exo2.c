#include <stdio.h>
#include <xmmintrin.h>
#include <omp.h>

int OMP_NUM_THREADS = 4;

int main(int argc, char** argv){
	omp_set_num_threads(OMP_NUM_THREADS);

    int VALEUR1 = 1000;
    int VALEUR2 = 2000;
	
	//#pragma omp parallel private (VALEUR2)
    #pragma omp parallel firstprivate (VALEUR2)
    {
        //VALEUR2 = 0;
        int nb_thread = omp_get_thread_num();
        printf("VALEUR1 : %d (core %d)\n", VALEUR1, nb_thread);
        VALEUR2 += 1;
        printf("VALEUR2 : %d (core %d)\n", VALEUR2, nb_thread);
    }

    return 0;
}
