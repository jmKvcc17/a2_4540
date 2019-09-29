#include <stdio.h>
#include <stdlib.h>
#include "roundRobin.h"
#include "readfile.h"
#include "io.h"
#include "cpu.h"
#include "a2.h"
#include "printStats.h"

extern int getArgsInfoOpenFile(FILE ** infile);
extern int mallocArrs(process a[]);

int main(int argc, char * argv[])
{
    // Process related vars
    process a[48];

	// process id is array index
	// variables below hold index to process in this array (process id)
    ui queue[48];
    ui queueCount = 0;
    ui io[48];
    ui ioCount = 10;
    ui cpu;
    os osStruct;
    osStruct.quantum = 70; // Time quantum
    osStruct.wait = 30; // PQ wait time

    // File pointer
    FILE * file;

    int testReturn = 0;

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
        }
        cpu = removeData(queue, &queueCount);
        // printQueue(a, queue, &queueCount);
        // printf("\nRemoving single item\n");

        iterationLoop(a, queue, &queueCount, io, &ioCount, &cpu, osStruct);
        // printStats(a, osStruct);
    }

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
    int interations = 100;
    int processID = 0;

    for (int i = 0; i < interations; i++) {
        // For each iteration, need to check each process in each "queue"/array
        // for io, cpu, and wait queue
        // Will then need to do calculations/move processes around
        checkCPU(a, queue, queueCount, cpu, osStruct, io, ioCount);
        //checkIo(a, queue, queueCount, io, ioCount, cpu, osStruct);
        //checkReady(a, queue, queueCount, cpu, osStruct);
    }
}
