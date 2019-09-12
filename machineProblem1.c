#include<stdio.h>
#include<stdlib.h>

//Function prototypes
int getSize(FILE *) //Scans input file to find largest vertex to obtain size of adjacency list

int main(int argc, char *argv[])
{
    FILE *input;

    if(argc > 3 || argc < 3)
    {
        puts("Incorrect number of arguments.");
        return 0;
    }

    if((input = fopen(argv[1], "r")) == NULL)
    {
        puts("Unable to open the input file.");
        return 0;
    }
    return 0;
}

int getSize(FILE *input)
{
    int numVertex = 0;

    char c = getc(input);
    while(c != EOF)
    {
        if (c > numVertex)
        {
            numVertex = c;
        }
    }

    size = numVertex + 1;

    rewind(input)
    fclose(input);
    return size;
}

