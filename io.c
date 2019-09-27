#include <stdio.h>
#include "a2.h"

void cpuToIo(process a[], ui * queueCount, ui io[], ui * ioCount, int index)
{
    a[index].curIo = 0;
}

void ioToReady(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct, int index) 
{
    // Need to decrement the IO list***

    // Add curIO to total IO
    a[index].ioTotal += a[index].curIo;
    a[index].curIo = 0;
    
    // Need to send the index to the RQ
}