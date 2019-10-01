/*
Author: Jesse Meachum
Class: CS4540
Assignment: A2
*/
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "cpu.h"
#include "a2.h"
#include "printStats.h"
#include "priorityQueue.h"

int openFile(FILE ** infile);
void readFile(FILE * file, process a[]);
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

    FILE * file; // File pointer

    if(openFile(&file)) // if the file could not be opened
    {
        perror("Could not open file.\n");
    }
    else
    {
        readFile(file, a); // read the processes into the main array

        // Initial insert into queue
        for (int i = 0; i < 48; i++) {
            insert(a, queue, i, &queueCount);
        }
        cpu = dequeue(a, queue, &queueCount); // Load in the first process

        iterationLoop(a, queue, &queueCount, io, &ioCount, &cpu, osStruct); // Go to the main loop for simulation
    }

    printStats(a, osStruct); // print the final output

    return 0;
}

/*
Attempts to open the specified file.
*/
int openFile(FILE ** infile)
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

/*
Main simulated loop for the CPU scheduler. Will run 10000 times, each loop
checking the CPU, IO list, and wait queue.
*/
void iterationLoop(process a[], ui queue[], ui * queueCount, ui io[], ui * ioCount, ui * cpu, os osStruct) {
    int interations = 10000;

    // For each iteration, need to check each process in each "queue"/array
    // for io, cpu, and wait queue
    // Will then need to do calculations/move processes around
    for (int i = 0; i < interations; i++) {
        checkCPU(a, queue, queueCount, cpu, osStruct, io, ioCount);
        checkReady(a, queue, queueCount, osStruct);
        checkIo(a, queue, queueCount, io, ioCount);
    }
}

/*
Reads all of the process into the a array and initializes their values
*/
void readFile(FILE * file, process a[])
{
    unsigned int priority, cpu, io, runtime;
    int lines = 0;

    // Read in the lines from the file
    while (fscanf(file, "%u %u %u %u", &priority, &cpu, &io, &runtime) != EOF) 
    {
        // Set initial values
        a[lines].priority = priority;
        a[lines].cpu = cpu;
        a[lines].io = io;
        // Set temp values
        a[lines].curPrior = priority; 
        a[lines].curCpu = 0;
        a[lines].curIo = 0;
        a[lines].cpuTotal = 0;
        a[lines].ioTotal = 0;
        a[lines].waitCount = 0;
        a[lines].wait = 0;
        a[lines].waitMin = 0;
        a[lines].waitMax = 0;
        a[lines].waitSum = 0;
        lines++;
    }
}
