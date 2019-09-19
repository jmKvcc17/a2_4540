#include <stdio.h>
#include "readfile.h"
#include "a2.h"

int main(int argc, char * argv[])
{
//     process a[48]; 
// 	// process id is array index
// 	// variables below hold index to process in this array (process id)
//     ui queue[48]; ui queueCount = 0;
//     ui io[48];  ui ioCount = 0;
//     ui cpu;
    FILE * file;

    file = fopen("a2in.txt", "r");

    if (file == NULL)
    {
        perror("Could not open file.\n");
    }

    readFile(file);

    return 0;
}