#ifndef CPU
#define CPU
#include "a2.h"

extern void readyToCPU(process a[], ui queue[], ui * queueCount, ui * cpu);
extern void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct, ui io[], ui * ioCount);
extern void cpuToReady(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct);
extern void checkReady();

#endif