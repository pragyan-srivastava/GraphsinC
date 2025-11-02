#include "1basic.h"
#include "1basic.c" // comment this in ideal case and then compile both files and link both to single output file
// Compile two files: gcc -c 1basic.c -o 1basic 1example.c -o 1example
// Link the two files: gcc 1basic 1example -o program
// Run by : program.exe
#include <stdio.h>
#include <stdlib.h>
void main()
{
    printf("\n");
    printListGraph(constructListDemo1());
    printf("\n\n\n");
    printMatrixGraph(constructMatrixDemo1());
}