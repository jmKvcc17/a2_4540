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

void checkIo(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct) {

    for (int i = 0; i < *ioCount; i++) {
        if (a[io[i]].curIo == a[io[i]].io) { // if the process has reached IO time
            a[io[i]].curIo = 0; // reset curIo

            // Insert back into wait queue
            insert(a, queue, io[i], queueCount);

            for (int j = i; j < *ioCount; j++) {
                io[j] = io[j + 1];
            }
            (*ioCount)--;
            i--;
        }
        else { // Increase IO time
            a[io[i]].curIo++;
            a[io[i]].ioTotal++;
        }
    }
}