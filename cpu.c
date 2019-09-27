#include <stdio.h>
#include "priorityQueue.h"
#include "io.h"
#include "a2.h"

// Dequeue a process to get ID
// Don't change curCpu
void readyToCPU(process a[], ui queue[], ui * queueCount, ui * cpu) 
{
    // Remove the highest priority process
    int procIndex = removeData(queue, &queueCount);
    a[procIndex].curCpu = 0;
    *cpu = procIndex;
}

void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct, ui io[], ui * ioCount)
{
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
            //a[*cpu].curIo = 0;

            // Move to IO
            cpuToIo(a, &queueCount, io, &ioCount, cpuIndex);
            *cpu = 48; // ? Reset to outside array range?
        }
    }
    else // Process has passed the time quantum, move back to ready queue
    {
        // Move to ready
        toReady(a, queue, &queueCount, &cpu, osStruct);

        // Set cpu to empty
        *cpu = 48;
    }
}

// Send the process to the 
void toReady(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct)
{
    // Set time waiting to 0 (MAY NOT HAVE TO DO)
    a[*cpu].wait = 0;

    // Set curPriority to original priority
    a[*cpu].curPrior = a[*cpu].priority;

    // Enqueue
    insert(a, queue, *cpu, &queueCount);
    *cpu = -1;
}