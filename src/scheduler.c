#include <stdio.h>
#include <unistd.h>

#include "scheduler.h"
#include "workload.h"

void run_scheduler(double attention_level)
{
    int quantum;

    if (attention_level > 40.0)
    {
        quantum = 1;

        printf("\n[MODE] HIGH ATTENTION\n");
        printf("Aggressive scheduling enabled.\n");
    }
    else
    {
        quantum = 3;

        printf("\n[MODE] LOW ATTENTION\n");
        printf("Conservative scheduling enabled.\n");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\nRunning task %d with quantum %d...\n", i + 1, quantum);

        heavy_task(i + 1);

        sleep(quantum);
    }
}
