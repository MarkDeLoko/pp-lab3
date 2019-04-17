#include <omp.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#define MAX 1000000

int max;
int main()
{
    int a[MAX];
    srand(time(NULL));
    for (int j = 0; j < MAX; ++j)
	a[j] = rand();

    clock_t time;
    time = clock();
    #pragma omp parallel num_threads(2)
    {
        #pragma omp for
        for (int i = 0; i < MAX; ++i)
        {   if (a[i] > max){
            #pragma omp critical
            {
                if (a[i] > max)
                    max = a[i];
            }
	    }

        }

    }
      
    printf("Max is %d ", max);
    time = clock() - time;
    printf("Time is %f\n", (double)time/CLOCKS_PER_SEC);
    return 0;
}
