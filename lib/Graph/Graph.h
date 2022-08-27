#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct DirectedEdge DirectedEdge;
typedef struct Vertex Vertex;
typedef struct Graph Graph;

struct Vertex
{
    char *id;
    DirectedEdge **edges;
    int noOfEdges;
};

struct DirectedEdge
{
    Vertex *v1;
    Vertex *v2;
    double weight;
};

struct Graph
{
    Vertex **vertices;
    DirectedEdge **edges;
    int noOfVertices;
    int noOfEdges;
};

Graph *MakeGraph();

void AddVertex(Graph *G, char *id);
void AddEdge(Graph *G, Vertex *v1Ptr, Vertex *v2Ptr, double weight);

void PrintAdjMatrix(Graph *G);
double GetEdgeWeight(Vertex *v1, Vertex *v2);

void FreeGraph(Graph *G);

#endif