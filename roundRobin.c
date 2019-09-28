#include <stdio.h>
#include "cpu.h"
#include "io.h"
#include "priorityQueue.h"
#include "a2.h"

void iterationLoop(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct) {
    int interations = 100;
    int processID = 0;

    for (int i = 0; i < interations; i++) {
        // For each iteration, need to check each process in each "queue"/array
        // for io, cpu, and wait queue
        // Will then need to do calculations/move processes around
        checkCPU(a, queue, queueCount, cpu, osStruct, io, ioCount);
        //checkIo(a, queue, queueCount, io, ioCount, cpu, osStruct);
    }
}