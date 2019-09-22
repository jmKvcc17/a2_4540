#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include <stdbool.h>
#include "a2.h"

extern process * peek();
extern bool isEmpty();
extern bool isFull();
extern int size();
extern void insert(process arr[], ui queue[], int index);
extern process * removeData();
extern void printQueue(process queue[]);

#endif