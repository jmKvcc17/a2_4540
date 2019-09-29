#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "io.h"
#include "cpu.h"
#include "a2.h"
#include "printStats.h"
#include "priorityQueue.h"

int getArgsInfoOpenFile(FILE ** infile);
void tempPrint(process a[], ui queue[]);
void iterationLoop(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct);

int main(int argc, char * argv[])
{
    // Process related vars
    process a[48];

	// process id is array index
	// variables below hold index to process in this array (process id)
    ui queue[48];
    ui queueCount = 0;
    ui io[48];
    ui ioCount = 0;
    ui cpu;
    os osStruct;
    osStruct.quantum = 70; // Time quantum
    osStruct.wait = 30; // PQ wait time

    // File pointer
    FILE * file;

    if(getArgsInfoOpenFile(&file))
    {
        perror("Could not open file.\n");
    }
    else
    {
        readFile(file, a);

        // Initial insert into queue
        for (int i = 0; i < 48; i++) {
            insert(a, queue, i, &queueCount);
            io[i] = 0;
        }
        cpu = removeData(a, queue, &queueCount);
        // printf("\nRemoving single item\n");

        iterationLoop(a, queue, &queueCount, io, &ioCount, &cpu, osStruct);
        // printStats(a, osStruct);
    }

    tempPrint(a, queue);

    return 0;
}

int getArgsInfoOpenFile(FILE ** infile)
{
    int ret = 0;

    *infile = fopen("a2in.txt", "r");

    if (*infile == NULL)
    {
        perror("Could not open file.\n");
        ret = -1;
    }

    return ret;
}

void iterationLoop(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct) {
    int interations = 1000;

    printf("Cpu value: %u\n", *cpu);

    for (int i = 0; i < interations; i++) {
        // For each iteration, need to check each process in each "queue"/array
        // for io, cpu, and wait queue
        // Will then need to do calculations/move processes around
        checkCPU(a, queue, queueCount, cpu, osStruct, io, ioCount);
        checkIo(a, queue, queueCount, io, ioCount, cpu, osStruct);
        checkReady(a, queue, queueCount, io, ioCount, cpu, osStruct);
    }
}

void tempPrint(process a[], ui queue[]) {
    printf("\nProcess end info\n");
    for (int i = 0; i < 48; i++) {
        printf("\n");
        printf("Global priority: %u\n", a[queue[i]].priority);
        printf("Global CPU: %u\n", a[queue[i]].cpu);
        printf("Global IO: %u\n", a[queue[i]].io);
        printf("Current CPU: %u\n", a[queue[i]].curCpu);
        printf("Current Priority: %u\n", a[queue[i]].curPrior);
        printf("Current IO: %u\n", a[queue[i]].curIo);
        printf("Wait Count: %u\n", a[queue[i]].waitCount);
        printf("CPU Total: %u\n", a[queue[i]].cpuTotal);
    }
}
