#ifndef CPU
#define CPU
#include "a2.h"

extern void readyToCPU(void readyToCPU(process a[], ui queue[], ui * queueCount, ui * cpu));
extern void checkCPU(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct);
extern void toReady(process a[], ui queue[], ui * queueCount, ui * cpu, os osStruct);
extern void checkReady();

#endif