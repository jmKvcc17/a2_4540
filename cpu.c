#include <stdio.h>
#include "priorityQueue.h"
#include "a2.h"

// Dequeue a process to get ID
// Don't change curCpu
void readyToCPU(process a[], ui queue[], ui * queueCount, ui * cpu) 
{
    // Remove the highest priority process
    int procIndex = removeData(queue, &queueCount);
    *cpu = procIndex;
}

void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct)
{
    if (a[*cpu].curCpu < osStruct.quantum && a[*cpu].curCpu < a[*cpu].cpu)
        a[*cpu].curCpu += 1;
    else 
    {
        // Move to IO if needed (TO DO)
        // Move to ready
        toReady(a, queue, &queueCount, &cpu, os_struct);
    }
        

}

void toReady(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct)
{
    // Set time waiting to 0
    a[*cpu].wait = 0;

    // Set curPriority to original priority
    a[*cpu].curPrior = a[*cpu].priority;

    // Enqueue
    insert(a, queue, *cpu, &queueCount);
    *cpu = -1;
}

void checkReady()
{
    
}