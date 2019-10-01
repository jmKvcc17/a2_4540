/*
Author: Jesse Meachum
Class: CS4540
Assignment: A2
*/
#include <stdio.h>
#include "a2.h"
#include "priorityQueue.h"
#include "io.h"

/*
Moves the index held in the CPU to the IO queue
*/
void cpuToIo(process a[], ui io[], ui * ioCount, int index)
{
    a[index].curIo = 0; // Reset the current IO time
    io[*ioCount] = index; // Add the process to the IO array
    (*ioCount)++; // Increment the io count
}

/*
Checks each process held in the IO array and increments their times, 
will then compare it to their IO time and if need be, remove the process
from the IO array to the wait queue. Will then fill in the whole left by 
the removal by shifting elements.
*/
void checkIo(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount) {

    for (int i = 0; i < *ioCount; i++) {
        if (a[io[i]].curIo == a[io[i]].io) { // if the process has reached IO time
            a[io[i]].curIo = 0; // reset curIo

            insert(a, queue, io[i], queueCount); // Insert back into wait queue

            for (int j = i; j < *ioCount; j++) { // Loop through each processes and shift them
                io[j] = io[j + 1];
            }
            (*ioCount)--; // Decrease amount of processes in IO
            i--;
        }
        else { // Increase IO time
            a[io[i]].curIo++;
            a[io[i]].ioTotal++;
        }
    }
}