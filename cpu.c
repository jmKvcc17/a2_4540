#include <stdio.h>
#include "priorityQueue.h"
#include "io.h"
#include "a2.h"
#include "cpu.h"

// Dequeue a process to get ID
// Don't change curCpu
void readyToCPU(process a[], ui queue[], ui * queueCount, ui * cpu) 
{
    // Remove the highest priority process
    int procIndex = removeData(a, queue, queueCount);
    a[procIndex].curCpu = 0;
    *cpu = procIndex;
}

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
            //a[*cpu].curIo = 0;

            // Move to IO
            cpuToIo(a, queueCount, io, ioCount, cpuIndex);
            *cpu = removeData(a, queue, queueCount); // Load in the next process
        }
    }
    else // Process has passed the time quantum, move back to ready queue
    {
        // Move to ready
        //cpuToReady(a, queue, queueCount, cpu, osStruct);

        // ****
        a[*cpu].waitCount += 1; // Increment number of times in wait queue
        a[*cpu].curPrior = a[*cpu].priority; // Set curPriority to original priority
        //insert(a, queue, *cpu, queueCount);
        toReady(a, queue, *cpu, queueCount);
        // ***

        *cpu = removeData(a, queue, queueCount); // Load in the next process
    }
}

// // Send the process to the 
// void cpuToReady(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct)
// {
//     // Set time waiting to 0 (MAY NOT HAVE TO DO)
//     a[*cpu].wait = 0;

//     // Set curPriority to original priority
//     a[*cpu].curPrior = a[*cpu].priority;

//     // Enqueue
//     insert(a, queue, *cpu, queueCount);
//     *cpu = -1;
// }