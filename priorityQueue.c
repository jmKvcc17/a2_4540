/*
Author: Jesse Meachum
Priority Queue implementation: https://www.tutorialspoint.com/data_structures_algorithms/priority_queue.htm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"
#include "cpu.h"
#include "io.h"
#include "priorityQueue.h"

/*
Go through each process and increase their curPriority to a max of 15.
Only do so when the wait time is divisible by 30.
Utilizes a bubble sort to sort processes, is stable to preserve process
order so other processes don't keep getting sent to the front of the queue.
*/
void checkReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct){
    int numQueue = *queueCount - 1;

    for (int i = 0; i < numQueue; i++) {

        a[queue[i]].wait += 1;

        if (a[queue[i]].wait % osStruct.wait == 0) // If the wait time is divisible by 30 (wait time)
        {
            if (a[queue[i]].curPrior < 15) { // If the process is less than 15
                a[queue[i]].curPrior += 1; // Increment the current priority

                ui temp;
                for (int j = 0; j < *queueCount-i-1; j++)  
                    if (a[queue[j]].curPrior >= a[queue[j+1]].curPrior) {
                        // Swap
                        temp = queue[j];
                        queue[j] = queue[j+1];
                        queue[j+1] = temp;
                    }
            }   
        }   
    }
}

/*
Utilizes insertion sort to insert the process back into the wait queue
*/
void insert(process a[], ui queue[], int index, ui * queueCount) {

    int i;
    a[index].curPrior = a[index].priority; // reset current priority
    for (i = *queueCount-1; i >= 0 && a[queue[i]].curPrior > a[index].curPrior; i--) {
        queue[i+1] = queue[i];
    }
    queue[i+1] = index;
    (*queueCount)++;
    a[index].waitCount++;
    a[index].wait = 0;
}

/*
Removes the highest priority index from the wait queue.
Before it is removed, the wait min and max are updated.
*/
int removeData(process a[], ui queue[], ui * queueCount){
    int queueSize = *queueCount - 1; // Get the top priority processes index
    
    if (a[queue[queueSize]].wait < a[queue[queueSize]].waitMin) // Check if min wait time needs to be updated
        a[queue[queueSize]].waitMin = a[queue[queueSize]].wait;

    if (a[queue[queueSize]].wait > a[queue[queueSize]].waitMax) // Check if max wait time needs to be updated
        a[queue[queueSize]].waitMax = a[queue[queueSize]].wait;

    a[queue[queueSize]].waitSum += a[queue[queueSize]].wait; // Update total wait time
    a[queue[queueSize]].wait = 0; // Reset wait time

    return queue[--(*queueCount)];
}