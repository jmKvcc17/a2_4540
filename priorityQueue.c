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

int itemCount = 0;

int peek(ui queue[], ui * queueCount) {
   return queue[(*queueCount) - 1];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == 48;
}

int size(){
   return itemCount;
}  

void checkReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct){
    // Go through each process and increase their curPriority to a max of 15
    // Only do so when the

    // if the CPU is empty readyToCPU
    if (*cpu == NULL) {
        readyToCPU(a, queue, &queueCount, &cpu);
    }
    else {
        int numQueue = *queueCount;
        int currIndex;

        for (int i = 0; i < numQueue; i++) {

            currIndex = removeData(queue, &queueCount);
            a[currIndex].wait += 1;

            if (a[currIndex].wait % osStruct.wait == 0)
            {
                // Increment the current priority
                if (a[currIndex].curPrior < 15) {
                    a[currIndex].curPrior += 1;
                }
                
            }
            
        }
    }

}

void insertCurr(process arr[], ui queue[], int index, ui * queueCount) {
    int i = 0;

    if(!isFull())
    {
        // if queue is empty, insert the data 
        if((*queueCount) == 0)
        {
            queue[(*queueCount)++] = index;       
        }
        else
        {
            // start from the right end of the queue 			
            for(i = (*queueCount) - 1; i >= 0; i--)
            {
                // if data is larger, shift existing item to right end 
                if(arr[index].curPrior < arr[queue[i]].curPrior)
                {
                   queue[i+1] = queue[i];
                }
                else
                {
                   break; // ************DANGER***********
                }            
            }  
			
            // insert the data 
            queue[i+1] = index;
            (*queueCount)++;
        }
    }
}

void insert(process arr[], ui queue[], int index, ui * queueCount) {
    int i = 0;

    if(!isFull())
    {
        // if queue is empty, insert the data 
        if((*queueCount) == 0)
        {
            queue[(*queueCount)++] = index;       
        }
        else
        {
            // start from the right end of the queue 			
            for(i = (*queueCount) - 1; i >= 0; i--)
            {
                // if data is larger, shift existing item to right end 
                if(arr[index].priority < arr[queue[i]].priority)
                {
                   queue[i+1] = queue[i];
                }
                else
                {
                   break; // ************DANGER***********
                }            
            }  
			
            // insert the data 
            queue[i+1] = index;
            (*queueCount)++;
        }
    }
}

int removeData(ui queue[], ui * queueCount){
   // return processArray[--itemCount]; 
   return queue[--(*queueCount)];
}

void printQueue(process a[], ui queue[], ui * queueCount) {

   for (int i = 0; i < (*queueCount); i++) {
      printf("Process info: %u %u %u\n", a[queue[i]].priority, a[queue[i]].cpu, a[queue[i]].io);
   }
}