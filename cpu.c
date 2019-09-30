#include <stdio.h>
#include "priorityQueue.h"
#include "io.h"
#include "a2.h"
#include "cpu.h"

/*
Checks the current process in the CPU by first incrementing its CPU time then 
checking if it has reached its time to move to IO. If not, will check if it 
has gone over the time quantum, and if so it is moved to the wait queue again.
*/
void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct, ui io[], ui * ioCount)
{
    a[*cpu].curCpu += 1; // Increment the process' CPU time

    if (a[*cpu].curCpu == a[*cpu].cpu) // If the process has reached CPU time, move to IO
    {
        a[*cpu].cpuTotal += a[*cpu].curCpu; // Add curCpu to cpuTotal, reset
        a[*cpu].curCpu = 0; // Reset current cpu time

        int cpuIndex = *cpu;

        cpuToIo(a, queueCount, io, ioCount, cpuIndex); // Move process to IO
        *cpu = removeData(a, queue, queueCount); // Load in the next process
    }
    else { // Check time quantum
        if (a[*cpu].curCpu == osStruct.quantum) // If the process has reached the quantum time
        {       
            insert(a, queue, *cpu, queueCount); // Insert back into ready queue

            *cpu = removeData(a, queue, queueCount); // Load in the next process
        }
    }
}
