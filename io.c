#include <stdio.h>
#include "a2.h"
#include "priorityQueue.h"
#include "io.h"

void cpuToIo(process a[], ui * queueCount, ui io[], ui * ioCount, int index)
{
    a[index].curIo = 0;
    io[*ioCount] = index; // Add the process to the IO array
    (*ioCount)++; // Increment the io count
}

void ioToReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct, int index) 
{
    // Need to decrement the IO list***

    // Add curIO to total IO
    a[index].ioTotal += a[index].curIo;
    a[index].curIo = 0;
    
    // Need to send the index to the RQ
}

void checkIo(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct) {
    for (int i = 0; i < *ioCount; i++) {
        if (a[io[i]].curIo == a[io[i]].io) { // if the process has reached IO time
            a[io[i]].ioTotal += a[io[i]].curIo; // Add curIo to ioTotal
            a[io[i]].curIo = 0; // reset curIo

            a[io[i]].wait = 0; // Reset wait time
            a[io[i]].curPrior = a[io[i]].priority; // Reset priority

            // Insert back into wait queue
            insert(a, queue, io[i], queueCount);

            for (int j = 0; j < (*ioCount - i - 1); j++) {
                io[j] = io[j + 1];
            }
            (*ioCount)--;
        }
        else { // Increase IO time
            a[io[i]].curIo++;
        }
    }
}