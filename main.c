/*

Group Members:
- Xin Zhang
- Genevieve Saab
- Paul Orton

Description:
1. Get vertices and edges and then create graphs G & G2
2. Add all edges to G based on input file
3. Loop through G and add edges to G2 based on:
    - The edge not already existing on G2
    - The vertex u does not equal vertex w
    - An edge connecting u -> v, v -> w
4. Print G2

Remarks:
This algorithm will not run in linear time time
due to the loops that need to be performed
which prevents it from being run proportionally
to the input.

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex; //vertex number
    struct node* next; //pointer to next node in linked list
} Node;
struct node* createNode(int); //creates node in linked list

struct Graph
{
    int numVertices;
    struct node** adjLists;
};

// Function Prototypes
struct Graph* createGraph(int vertices); //passes size of graph as parameter and creates null graph
void addEdge(struct Graph* graph, int src, int dest); //adds edge for directed graph
void printGraph(struct Graph* graph);
int getVertices(void); //Gets number of vertices of graph to be made
int getEdges(void); //Gets number of edges of graph to be made


int main(int argc, char *argv[])
{
    int vertices = getVertices() + 1;
    int edges = getEdges();
    struct Graph* graph = createGraph(vertices);
    struct Graph* graph2 = createGraph(vertices);

    FILE *file;
    file = fopen("input.txt", "r");

    int source[edges];
    int destination[edges];
    for (int i = 0; i < edges; i++)
    {
        fscanf(file, "%d %d", &source[i], &destination[i]);
        addEdge(graph, source[i], destination[i]);
    }

    struct node *ptr = NULL;
    struct node *ptr2 = NULL;
    struct node *ptr3 = NULL;
    int u, v, w;
    int exists = 0;

    for (u = 1; u < vertices; u++) {
        if(graph -> adjLists[u] != NULL) {
            ptr = graph -> adjLists[u];
            while (ptr) {
                v = ptr -> vertex;

                ptr2 = graph -> adjLists[v];

                while (ptr2) {
                    w = ptr2 -> vertex;

                    ptr3 = graph2 -> adjLists[u];
                    
                    while(ptr3) {
                         if (ptr3 -> vertex == w) { 
                            exists = 1; // Saying w already exists on this list
                         }

                         ptr3 = ptr3 -> next;
                    }

                    if (u != w && exists == 0) {
                        addEdge(graph2, u, w);
                    }
                    exists = 0;

                    ptr2 = ptr2 -> next;
                }
                ptr = ptr -> next;
            }
        } else {
            continue;
        }
    }

    printGraph(graph2);

    fclose(file);

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
    printf("\n\t[OUTPUT]\n\n");
    for (v = 1; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("%d: ", v);
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

int getVertices(void) {
    FILE *file;
    file = fopen("input.txt", "r");

    int size = 0;
    int tempSize = 0;

    while(!feof(file)) {
        fscanf(file, "%d", &tempSize);
        if (tempSize > size) {
            size = tempSize;
        }
    }

    fclose(file);

    return size;
}

int getEdges(void) {
    FILE *file;
    file = fopen("input.txt", "r");

    int edges = 0;

    while(!feof(file)) {
        if(getc(file) == '\n') {
            edges++;
        }
    }

    fclose(file);

    return edges;
}