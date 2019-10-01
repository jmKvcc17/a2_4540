/*
Author: Jesse Meachum
Class: CS4540
Assignment: A2
*/
#ifndef IO
#define IO
#include <stdio.h>
#include "a2.h"

extern void cpuToIo(process a[], ui io[], ui * ioCount, int index);
extern void checkIo(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount);

#endif