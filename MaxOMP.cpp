#include <omp.h>
#include <stdio.h>
#include <time.h>
#define MAX 16

int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int max =0;

int main()
{
    clock_t time;
    time = clock();
    #pragma omp parallel num_threads(2)
    {
        #pragma omp for
        for (int i = 0; i < MAX; ++i)
        {
            #pragma omp critical
            {
                if (a[i] > max)
                    max = a[i];
            }

        }

    }
      
    printf("Max is %d ", max);
    time = clock() - time;
    printf("Time is %f\n", (double)time/CLOCKS_PER_SEC);
    return 0;
}
