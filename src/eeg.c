#include <stdio.h>
#include "eeg.h"

double read_attention_level(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Failed to open EEG file.\n");
        return -1;
    }

    double value;
    double sum = 0;
    int count = 0;

    while (fscanf(file, "%lf", &value) == 1)
    {
        sum += value;
        count++;
    }

    fclose(file);

    if (count == 0)
    {
        return 0;
    }

    return sum / count;
}
