#include <stdio.h>
#include <stdlib.h>
#include "a2.h"
#include "readfile.h"

//void readFile(FILE * file, process a[])
void readFile(FILE * file, process a[])
{
    unsigned int priority, cpu, io, runtime;
    int lines = 0;

    // Read in the lines from the file
    while (fscanf(file, "%u %u %u %u", &priority, &cpu, &io, &runtime) != EOF) 
    {
        //printf("%u %u %u %u\n", priority, cpu, io, runtime);
        a[lines].priority = priority;
        a[lines].curPrior = priority; // ***
        a[lines].curCpu = 0;
        a[lines].cpu = cpu;
        a[lines].io = io;
        lines++;
    }

}