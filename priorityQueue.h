#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include <stdbool.h>
#include "a2.h"

extern int peek(ui queue[], ui * queueCount);
extern void insert(process a[], ui queue[], int index, ui * queueCount);
extern int removeData(process a[], ui queue[], ui * queueCount);
extern void checkReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct);
extern void bubbleSort(process a[], ui queue[], ui * cpu, ui * queueCount);
extern void swap(ui *xp, ui *yp);

#endif