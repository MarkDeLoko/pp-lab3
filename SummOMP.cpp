#include <omp.h>
#include <stdio.h>
#include <time.h>
#define MAX 100000

int a[MAX];

int main()
{
    clock_t time;
    time = clock();
    int i;
    int j;
    for(i = 0; i < MAX; i++)
        a[i]=i;

    long Summa = 0;
    #pragma omp parallel num_threads(2) reduction(+:Summa)
    {
        #pragma omp for
        for(i = 0; i < MAX; i++)
        {
            Summa += a[i];
            for(j = 0; j < MAX; j++)
                Summa = Summa;
        }


    }
    time = clock() - time;
    printf("Time is %f\n", (double)time/CLOCKS_PER_SEC);
    printf("Summ is %d\n ", Summa);
    return 0;
}
