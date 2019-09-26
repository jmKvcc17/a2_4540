/*
Author: Jesse Meachum
Priority Queue implementation: https://www.tutorialspoint.com/data_structures_algorithms/priority_queue.htm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"

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
      //printf("Address: %d\n", &queue[i]);
      //printf("Test: %u\n", a[queue[i]].waitCount);
   }
}