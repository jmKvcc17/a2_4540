#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include <stdbool.h>
#include "a2.h"

extern int peek(ui queue[], ui * queueCount);
extern bool isEmpty();
extern bool isFull();
extern int size();
extern void insert(process a[], ui queue[], int index, ui * queueCount);
//extern void insertCurr(process arr[], ui queue[], int index, ui * queueCount);
extern int removeData(ui queue[], ui * queueCount);
extern void printQueue(process a[], ui queue[], ui * queueCount);
extern void checkReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct);
extern void toReady(process a[], ui queue[], ui * cpu, ui * queueCount);

#endif