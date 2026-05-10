#include <stdio.h>

#include "eeg.h"
#include "scheduler.h"

int main()
{
    double attention;

    attention = read_attention_level("data/eeg_sample.csv");

    if (attention < 0)
    {
        return 1;
    }

    printf("Attention Level: %.2f\n", attention);

    run_scheduler(attention);

    return 0;
}
