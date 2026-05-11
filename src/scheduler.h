#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct
{
    int task_id;
    int priority;
} Task;

void run_scheduler(double attention_level);

#endif
