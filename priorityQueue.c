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


int peek(ui queue[], ui * queueCount) {
   return queue[(*queueCount) - 1];
}

void swap(ui *xp, ui *yp)  
{  
    ui temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}   

// An agnostic implementation that just needs the process index
// Should be able to accept from both IO and CPU
void bubbleSort(process a[], ui queue[], ui * cpu, ui * queueCount) {
    int i, j;  
    ui temp;
    for (i = 0; i < *queueCount-1; i++)      
        // Last i elements are already in place  
        for (j = 0; j < *queueCount-i-1; j++)  
            if (a[queue[j]].curPrior > a[queue[j+1]].curPrior) {
                temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }  
                //swap(&queue[j], &queue[j+1]); 
}

void checkReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct){
    // Go through each process and increase their curPriority to a max of 15
    // Only do so when the wait time is divisible by 30

    // if the CPU is empty readyToCPU
    // if (*cpu == NULL) {
    //     readyToCPU(a, queue, queueCount, cpu);
    // }
    // else {
        int numQueue = *queueCount - 1;
        //int currIndex;

        for (int i = 0; i < numQueue; i++) {

            //currIndex = removeData(queue, queueCount);
            a[queue[i]].wait += 1;

            if (a[queue[i]].wait % osStruct.wait == 0)
            {
                // Increment the current priority
                if (a[queue[i]].curPrior < 15) {
                    a[queue[i]].curPrior += 1;

                    int j;
                    ui temp;
                    //bubbleSort(a, queue, cpu, queueCount); // Resort the queue
                    for (j = 0; j < *queueCount-i-1; j++)  
                        if (a[queue[j]].curPrior > a[queue[j+1]].curPrior) {
                            // Swap
                            temp = queue[j];
                            queue[j] = queue[j+1];
                            queue[j+1] = temp;
                        }
                }
                
            }
            
        }
    //}
}

void insert(process a[], ui queue[], int index, ui * queueCount) {
    //int i = 0;

    if(*queueCount < 48)
    {
        // // if queue is empty, insert the data 
        // if((*queueCount) == 0)
        // {
        //     queue[(*queueCount)++] = index;       
        // }
        // else
        // {
        //     // start from the right end of the queue 			
        //     for(i = (*queueCount) - 1; i >= 0; i--)
        //     {
        //         // if data is larger, shift existing item to right end 
        //         if(a[index].curPrior < a[queue[i]].curPrior)
        //         {
        //            queue[i+1] = queue[i];
        //         }
        //         else
        //         {
        //            break; // ************DANGER***********
        //         }            
        //     }  
			
        //     // insert the data 
        //     queue[i+1] = index;
        //     (*queueCount)++;
        // }

        // int i, j;
        // int key;
        // for (i = 1; i < *queueCount; i++) { 
        //     key = queue[i]; 
        //     j = i - 1; 
    
        //     /* Move elements of arr[0..i-1], that are 
        //     greater than key, to one position ahead 
        //     of their current position */
        //     while (j >= 0 && a[queue[j]].curPrior > a[key].curPrior) { 
        //         queue[j + 1] = queue[j]; 
        //         j = j - 1; 
        //     } 
        //     queue[j + 1] = key;      
        // } 
        // (*queueCount)++;

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
    else {
        printf("Error. Trying to insert too many processes into wait queue.\n");
    }
}

// Removes from wait queue
int removeData(process a[], ui queue[], ui * queueCount){
    int queueSize = *queueCount - 1;
    // Check if min wait time needs to be updated
    // printf("Size of queue: %d\n", queueSize);
    if (a[queue[queueSize]].wait < a[queue[queueSize]].waitMin)
        a[queue[queueSize]].waitMin = a[queue[queueSize]].wait;

    // Check if max wait time needs to be updated
    if (a[queue[queueSize]].wait > a[queue[queueSize]].waitMax)
        a[queue[queueSize]].waitMax = a[queue[queueSize]].wait;

    a[queue[queueSize]].waitSum += a[queue[queueSize]].wait; // Update total wait time
    a[queue[queueSize]].wait = 0; // Reset wait time

    return queue[--(*queueCount)];
}