#include<stdio.h>
#include<stdlib.h>

typedef struct adjList{
    int G;
    int G2;
    int color; //white=1 and black=0
    struct adjList *next;
}ADJ;

//Function prototypes
int getSize(char *); //Scans input file to find largest vertex to obtain size of adjacency list
ADJ* createG(ADJ[], int, char *);
void insertG(ADJ**, int);

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

    //Declare arrays
    ADJ gArr[size];
    ADJ g2Arr[size]; //I just realized maybe we only need one array since we already have pointers to G and G2

    //Initialize arrays
    for(int i = 0; i < size; i++)
    {
        //All colors set to white
        gArr[i].color = 1;
        g2Arr[i].color=1;

        //All values set to zero
        gArr[i].G=0;
        g2Arr[i].G2=0;
    }

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

ADJ* createG(ADJ gArr[], int size, char *filename)
{
    FILE *input = fopen(filename, "r"); //File pointer
    int vertex1 = 0;
    int vertex2 = 0;

    for(int i = 1; i < size; i++)
    {
        fscanf(input, "%d %d\n", &vertex1, &vertex2);
        fscanf(input, "%d %d\n", &vertex1, &vertex2);
        gArr[vertex1].color = 0;
        if(gArr[vertex2].color == 1)
        {
            //insert()
        }
    }
    return gArr;
}

void insertG(ADJ** head, int data)
{
    ADJ* node = (ADJ*)(sizeof(ADJ)); //Allocate node
    node->G = data; //Insert data
    node->next=(*head); //Make new node the head
    (*head) = node; //Head points to new node
}
