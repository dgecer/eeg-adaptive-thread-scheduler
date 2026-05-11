#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "scheduler.h"
#include "workload.h"

void run_scheduler(double attention_level)
{
    int quantum;

    clock_t start, end;
    double cpu_time_used;

    double total_time = 0;
    int completed_tasks = 0;

    Task tasks[5] =
    {
        {1, 3},
        {2, 1},
        {3, 2},
        {4, 1},
        {5, 3}
    };

    if (attention_level > 100.0)
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
        printf("\n[TASK %d]\n", tasks[i].task_id);

        printf("Priority: %d\n", tasks[i].priority);

        printf("Quantum: %d\n", quantum);

        start = clock();

        if (attention_level <= 100.0 && tasks[i].priority == 3)
        {
            printf("Task skipped due to low attention.\n");
            continue;
        }

        heavy_task(tasks[i].task_id);

        end = clock();

        cpu_time_used =
            ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Execution Time: %.2f seconds\n",
               cpu_time_used);

        total_time += cpu_time_used;

        completed_tasks++;

        sleep(quantum);
    }

    printf("\n===== Scheduler Statistics =====\n");

    printf("Completed Tasks: %d\n",
           completed_tasks);

    printf("Total Execution Time: %.2f seconds\n",
           total_time);

    printf("Average Task Time: %.2f seconds\n",
           total_time / completed_tasks);

    printf("Throughput: %.2f tasks/sec\n",
           completed_tasks / total_time);
}