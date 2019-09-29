#include <stdio.h>
#include "priorityQueue.h"
#include "io.h"
#include "a2.h"
#include "cpu.h"

void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct, ui io[], ui * ioCount)
{
    // printf("Test in Check CPU: %u, %u\n", a[*cpu].curCpu, osStruct.quantum);
    // If the process is less than the quantum
    if (a[*cpu].curCpu < osStruct.quantum)
    {
        // if the process still has time left in the cpu
        if (a[*cpu].curCpu < a[*cpu].cpu)
        {
            a[*cpu].curCpu += 1;
        }
        else // Process has finished CPU time, move to IO
        {
            // Add curCpu to cpuTotal, reset
            a[*cpu].cpuTotal = a[*cpu].cpuTotal + a[*cpu].curCpu;
            a[*cpu].curCpu = 0;

            int cpuIndex = *cpu;

            // Move to IO
            cpuToIo(a, queueCount, io, ioCount, cpuIndex);
            *cpu = removeData(a, queue, queueCount); // Load in the next process
        }
    }
    else // Process has passed the time quantum, move back to ready queue
    {
        a[*cpu].waitCount += 1; // Increment number of times in wait queue
        a[*cpu].curPrior = a[*cpu].priority; // Set curPriority to original priority

        insert(a, queue, *cpu, queueCount);

        *cpu = removeData(a, queue, queueCount); // Load in the next process
    }
}
