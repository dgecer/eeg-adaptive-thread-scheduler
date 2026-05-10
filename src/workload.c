#include <stdio.h>

#include "workload.h"

void heavy_task(int id)
{
    volatile long long sum = 0;

    for (long long i = 0; i < 500000000; i++)
    {
        sum += i;
    }

    printf("Task %d completed.\n", id);
}
