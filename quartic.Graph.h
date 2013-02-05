#ifndef GRAPH_H
#define GRAPH_H

#include "quartic.Edge.h"
#include "quartic.Vertex.h"

typedef struct Graph {
	Edge *edges;		// Hash<Edge> *edges;
	Vertex *vertices;	// Hash<Vertex> *vertices;
	int order;
	int size;
} Graph;

// Functions a Graph needs to have
//		DFS
//		BFS
//		Add a Vertex/Edge to a Graph
//		Join a Vertex to a Graph
//		Remove a Vertex/Edge from a Graph
//		Graph Union/Intersect ?



#endif /* GRAPH_H */