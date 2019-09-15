#include <stdio.h>
#include <stdlib.h>

//Function prototypes
//int getSize(char *); //Scans input file to find largest vertex to obtain size of adjacency list
struct node
{
    int vertex; //vertex number
    struct node* next; //pointer to next node in linked list
};
struct node* createNode(int); //creates node in linked list

struct Graph
{
    int numVertices;
    int color; //white, gray or black
    struct node** adjLists;
};


struct Graph* createGraph(int vertices); //passes size of graph as parameter and creates null graph
void addEdge(struct Graph* graph, int src, int dest); //adds edge for directed graph
void printGraph(struct Graph* graph);


int main(int argc, char *argv[])
{
    int size = 6;
    struct Graph* graph = createGraph(size);

    FILE *file;
    file = fopen("input.txt", "r");

    int source[size];
    int destination[size];
    for(int i = 0; i < size; i++)
    {
        fscanf(file, "%d %d", &source[i], &destination[i]);
        addEdge(graph, source[i], destination[i]);
    }

    printGraph(graph);

    return 0;
}

struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph)); //allocate space for graph
    graph->numVertices = vertices; //sets size

    graph->adjLists = malloc(vertices * sizeof(struct node*)); //allocates space for each adjacency list in matrix

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL; //initialize adjacency list in graph as null

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from source to destination
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
