/*
Author: Jesse Meachum
Class: CS4540
Assignment: A2
*/
#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include <stdbool.h>
#include "a2.h"

extern void insert(process a[], ui queue[], int index, ui * queueCount);
extern int dequeue(process a[], ui queue[], ui * queueCount);
extern void checkReady(process a[], ui queue[], ui * queueCount, os osStruct);

#endif