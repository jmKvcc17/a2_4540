/*
Author: Jesse Meachum
Priority Queue implementation: https://www.tutorialspoint.com/data_structures_algorithms/priority_queue.htm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"

process * processArray[48];
int itemCount = 0;

process * peek() {
   return processArray[itemCount - 1];
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

void insert(process arr[], ui queue[], int index) {
   int i = 0;

   if(!isFull()){
      // if queue is empty, insert the data 
      if(itemCount == 0){
         //processArray[itemCount++] = data;
         queue[itemCount++] = index;  
         printf("Location of element in new queue: %d\n", queue[itemCount]);      
      }else{
         // start from the right end of the queue 
			
         for(i = itemCount - 1; i >= 0; i-- ){
            // if data is larger, shift existing item to right end 
            // if(data->priority > processArray[i]->priority){
            if(arr[index].priority > arr[queue[i]].priority){
               //processArray[i+1] = processArray[i];
               queue[i+1] = queue[i];
            }else{
               break;
            }            
         }  
			
         // insert the data 
         // processArray[i+1] = data;
         queue[i+1] = index;
         itemCount++;
      }
   }
}

process * removeData(){
   return processArray[--itemCount]; 
}

void printQueue(process a[], ui queue[]) {
   for (int i = 0; i < 48; i++) {
      printf("Process info: %u %u %u\n", a[queue[i]].priority, a[queue[i]].cpu, a[queue[i]].io);
      //printf("Address: %d\n", &queue[i]);
      printf("Test: %u\n", a[queue[i]].waitCount);
   }
}