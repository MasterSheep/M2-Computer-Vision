# Text 1

```
#include <stdio.h>
#include <xmmintrin.h>
#include <omp.h>

int OMP_NUM_THREADS 4;

int main(int argc, char** argv){
	omp_set_num_threads(OMP_NUM_THREADS);
	
	#pragma omp parallel
    {
        printf("Hello from process: %d\n", omp_get_thread_num());
    }

    return 0;
}
```