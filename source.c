#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "a2.h"

extern int getArgsInfoOpenFile(FILE ** infile);
extern int mallocArrs(process a[]);

int main(int argc, char * argv[])
{
    // Process related vars
    process a[48];

    //a[0].cpu = 1000;
    //printf("Test: %u\n", a[0].cpu);
	// process id is array index
	// variables below hold index to process in this array (process id)
    ui queue[48];
    ui queueCount = 0;
    ui io[48];
    ui ioCount = 0;
    ui cpu;

    // File pointer
    FILE * file;

    if(getArgsInfoOpenFile(&file))
    {
        perror("Could not open file.\n");
    }
    else
    {
        readFile(file, a);
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
