#include <stdio.h>
#include <stdlib.h>
#include "roundRobin.h"
#include "readfile.h"
#include "priorityQueue.h"
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

int mallocArrs(process a[]) 
{
    int ret = 0;

    a = malloc(sizeof(process) * 48);

    return ret;
}
