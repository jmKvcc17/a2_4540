#include <stdio.h>
#include "a2.h"

extern void cpuToIo(process a[], ui * queueCount, ui io[], ui * ioCount, int index);
extern void ioToReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct, int index);