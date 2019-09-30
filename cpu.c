#include <stdio.h>
#include "priorityQueue.h"
#include "io.h"
#include "a2.h"
#include "cpu.h"

void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct, ui io[], ui * ioCount)
{
    a[*cpu].curCpu += 1;
    // if (a[*cpu].curCpu < osStruct.quantum) // If the process is less than the quantum
    // {
        //if (a[*cpu].curCpu < a[*cpu].cpu) // If the process still has time left in the cpu
    if (a[*cpu].curCpu == a[*cpu].cpu) // If the process has reached CPU time, move to IO
    {
        //a[*cpu].curCpu += 1;
        a[*cpu].cpuTotal += a[*cpu].curCpu; // Add curCpu to cpuTotal, reset
        a[*cpu].curCpu = 0;

        int cpuIndex = *cpu;

        // Move to IO
        cpuToIo(a, queueCount, io, ioCount, cpuIndex);
        *cpu = removeData(a, queue, queueCount); // Load in the next process
    }
    else { // Check time quantum
        if (a[*cpu].curCpu == osStruct.quantum) // If the process is less than the quantum
        {       
            a[*cpu].curPrior = a[*cpu].priority; // Set curPriority to original priority

            insert(a, queue, *cpu, queueCount); // Insert back into ready queue

            *cpu = removeData(a, queue, queueCount); // Load in the next process
        }
    }
        // else // Process has finished CPU time, move to IO
        // {
        //     // Add curCpu to cpuTotal, reset
        //     a[*cpu].cpuTotal = a[*cpu].cpuTotal + a[*cpu].curCpu;
        //     a[*cpu].curCpu = 0;

        //     int cpuIndex = *cpu;

        //     // Move to IO
        //     cpuToIo(a, queueCount, io, ioCount, cpuIndex);
        //     *cpu = removeData(a, queue, queueCount); // Load in the next process
        // }
    //}
    // else // Process has passed the time quantum, move back to ready queue
    // {
    //     a[*cpu].curPrior = a[*cpu].priority; // Set curPriority to original priority

    //     insert(a, queue, *cpu, queueCount); // Insert back into ready queue

    //     *cpu = removeData(a, queue, queueCount); // Load in the next process
    // }
}
