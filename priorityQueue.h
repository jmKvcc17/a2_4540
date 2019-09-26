#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include <stdbool.h>
#include "a2.h"

extern int peek(ui queue[], ui * queueCount);
extern bool isEmpty();
extern bool isFull();
extern int size();
extern void insert(process arr[], ui queue[], int index, ui * queueCount);
// extern process * removeData();
extern int removeData(ui queue[], ui * queueCount);
extern void printQueue(process a[], ui queue[], ui * queueCount);

#endif