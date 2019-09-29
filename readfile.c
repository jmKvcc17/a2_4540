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
        // Set initial values
        a[lines].priority = priority;
        a[lines].cpu = cpu;
        a[lines].io = io;
        // Set temp values
        a[lines].curPrior = priority; 
        a[lines].curCpu = 0;
        a[lines].curIo = 0;
        a[lines].cpuTotal = 0;
        a[lines].ioTotal = 0;
        a[lines].waitCount = 0;
        a[lines].wait = 0;
        a[lines].waitMin = 0;
        a[lines].waitMax = 0;
        a[lines].waitSum = 0;
        lines++;
    }

}