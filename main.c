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
    struct Graph* graph = createGraph(6);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);
    addEdge(graph, 6, 5);
    addEdge(graph, 5, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 5);
    addEdge(graph, 1, 5);
    addEdge(graph, 5, 6);

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
