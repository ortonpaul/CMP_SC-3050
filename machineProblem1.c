#include<stdio.h>
#include<stdlib.h>

//Function prototypes
int getSize(char *); //Scans input file to find largest vertex to obtain size of adjacency list

int main(int argc, char *argv[])
{
    FILE *input;

    if(argc > 3 || argc < 3) //Check for 3 arguments
    {
        puts("Incorrect number of arguments.");
        return 0;
    }

    if((input = fopen(argv[1], "r")) == NULL) //Check input file
    {
        puts("Unable to open the input file.");
        return 0;
    }

    int size = getSize(argv[1]); //Retrieve size of array

    return 0;
}

int getSize(char *filename)
{
    FILE *input = fopen(filename, "r"); //File pointer

    if(input == NULL) //Check input file
    {
        puts("Unable to open the input file");
        return 0;
    }

    int numVertex = 0; //Total number of vertices
    int temp1; //Temp variable for first vertex on a line
    int temp2; //Temp variable for second vertex on a line

    int c = getc(input); //Takes char from file

    while(c != EOF) //Loops until end of file
    {
       fscanf(input,"%d %d\n", &temp1, &temp2); //Scan in first and second vertices on a line

       //Checks for a vertex value greater than numVertex
       if(numVertex < temp1)
       {
           numVertex = temp1;
       }
       if(numVertex < temp2)
       {
           numVertex = temp2;
       }

       c = getc(input); //Takes char from file
    }

    int size = numVertex + 1; //Size is incremented once so vertices are equal to their index

    rewind(input); //Set file pointer back to the beginning
    fclose(input); //Close file

    return size;
}

