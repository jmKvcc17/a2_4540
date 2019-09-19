#include <stdio.h>

#include "readfile.h"

void readFile(FILE * file)
{
    unsigned int priority, cpu, io, runtime;

    // Read in the lines from the file
    while (fscanf(file, "%u %u %u %u", &priority, &cpu, &io, &runtime) != EOF) 
    {
        printf("%u %u %u %u\n", priority, cpu, io, runtime);
        
    }
}