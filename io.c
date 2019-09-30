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
            //a[io[i]].ioTotal += a[io[i]].curIo; // Add curIo to ioTotal
            a[io[i]].curIo = 0; // reset curIo

            //a[io[i]].wait = 0; // Reset wait time
            //a[io[i]].curPrior = a[io[i]].priority; // Reset priority

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

        // if (procs[io[i]].curIo == procs[io[i]].io) { // process ready to leave IO
        //     procs[io[i]].curIo = 0; // reset curIo
        //     add_proc_to_queue(procs, queue, queue_count, io[i]);
        //     // shift the IO queue
        //     int j;
        //     for (j=i; j<*io_count; j++) {
        //         io[j] = io[j+1];
        //     }
        //     (*io_count)--;
        //     i--;
        // }
        // else { // increment IO 
        //     procs[io[i]].curIo++;
        //     procs[io[i]].ioTotal++;
        // }
    }
}