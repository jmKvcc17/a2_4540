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

void checkReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct){
    // Go through each process and increase their curPriority to a max of 15
    // Only do so when the wait time is divisible by 30
    // Utilizes a bubble sort to move processes

    int numQueue = *queueCount - 1;

    for (int i = 0; i < numQueue; i++) {

        a[queue[i]].wait += 1;

        if (a[queue[i]].wait % osStruct.wait == 0)
        {
            // Increment the current priority
            if (a[queue[i]].curPrior < 15) {
                a[queue[i]].curPrior += 1;

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
Utilizes insertion sort
*/
void insert(process a[], ui queue[], int index, ui * queueCount) {

    int i;
    a[index].curPrior = a[index].priority;
    for (i = *queueCount-1; i >= 0 && a[queue[i]].curPrior > a[index].curPrior; i--) {
        queue[i+1] = queue[i];
    }
    queue[i+1] = index;
    (*queueCount)++;
    a[index].waitCount++;
    a[index].wait = 0;
}

// Removes from wait queue
int removeData(process a[], ui queue[], ui * queueCount){
    int queueSize = *queueCount - 1;
    
    if (a[queue[queueSize]].wait < a[queue[queueSize]].waitMin) // Check if min wait time needs to be updated
        a[queue[queueSize]].waitMin = a[queue[queueSize]].wait;

    if (a[queue[queueSize]].wait > a[queue[queueSize]].waitMax) // Check if max wait time needs to be updated
        a[queue[queueSize]].waitMax = a[queue[queueSize]].wait;

    a[queue[queueSize]].waitSum += a[queue[queueSize]].wait; // Update total wait time
    a[queue[queueSize]].wait = 0; // Reset wait time

    return queue[--(*queueCount)];
}