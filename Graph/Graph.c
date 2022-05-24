#include "Graph.h"
#include "../Helpers/Helpers.h"
#include <stdio.h>
#include <stdlib.h>

Graph *MakeGraph()
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->edges = NULL;
    G->vertices = NULL;
    G->noOfVertices = 0;
    G->noOfEdges = 0;

    return G;
}

void FreeGraph(Graph *G)
{
    int i;
    // free Edges
    for (i = G->noOfEdges - 1; i >= 0; i--)
        free(G->edges[i]);
    free(G->edges);

    // free Vertices
    for (i = G->noOfVertices - 1; i >= 0; i--)
        free(G->vertices[i]);
    free(G->vertices);

    // free Graph
    free(G);
}

void AddVertex(Graph *G, char *vertexId)
{
    Vertex *v = (Vertex *)malloc(sizeof(Vertex));
    v->id = vertexId;
    v->edges = NULL;
    v->noOfEdges = 0;

    G->noOfVertices++;
    if (G->vertices == NULL)
    {
        G->vertices = (Vertex **)malloc(sizeof(Vertex *));
        G->vertices[0] = v;
    }
    else
    {
        G->vertices = (Vertex **)realloc(G->vertices, sizeof(Vertex *) * G->noOfVertices);
        G->vertices[G->noOfVertices - 1] = v;
    }
}

void AddEdge(Graph *G, Vertex *v1Ptr, Vertex *v2Ptr, double weight)
{
    DirectedEdge *e = (DirectedEdge *)malloc(sizeof(DirectedEdge));
    e->v1 = v1Ptr;
    e->v2 = v2Ptr;
    e->weight = weight;

    // add Edge to the Graph
    G->noOfEdges++;
    if (G->edges == NULL)
    {
        G->edges = (DirectedEdge **)malloc(sizeof(DirectedEdge *));
        G->edges[0] = e;
    }
    else
    {
        G->edges = (DirectedEdge **)realloc(G->edges, sizeof(DirectedEdge *) * G->noOfEdges);
        G->edges[G->noOfEdges - 1] = e;
    }
    // add Edge to Vertex v1
    v1Ptr->noOfEdges++;
    if (v1Ptr->edges == NULL)
    {
        v1Ptr->edges = (DirectedEdge **)malloc(sizeof(DirectedEdge *));
        v1Ptr->edges[0] = e;
    }
    else
    {
        v1Ptr->edges = (DirectedEdge **)realloc(v1Ptr->edges, sizeof(DirectedEdge *) * v1Ptr->noOfEdges);
        v1Ptr->edges[v1Ptr->noOfEdges - 1] = e;
    }
}

void PrintAdjMatrix(Graph *G)
{
    int i, j;
    printf("\n\t");
    for (i = 0; i < G->noOfVertices; i++)
    {
        printf("%s\t", G->vertices[i]);
    }
    printf("\n");

    for (i = 0; i < G->noOfVertices; i++)
    {
        Vertex *v = G->vertices[i];
        printf("%s\t", v->id);
        for (j = 0; j < G->noOfVertices; j++)
        {
            double weight = GetEdgeWeight(v, G->vertices[j]);
            if (weight == NULL)
                printf("--\t");
            else
                printf("%d\t", weight);
        }
        printf("\n");
    }
}

double GetEdgeWeight(Vertex *v1, Vertex *v2)
{
    int i;

    for (i = 0; i < v1->noOfEdges; i++)
    {
        if (isStrsEqual(v1->edges[i]->v2->id, v2->id))
            return v1->edges[i]->weight;
    }

    return NULL;
}