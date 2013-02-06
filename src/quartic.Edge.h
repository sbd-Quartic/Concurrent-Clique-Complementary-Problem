#ifndef EDGE_H
#define EDGE_H

#include "quartic.Vertex.h"

typedef struct Edge {
	struct Vertex vertices[2];
	char directed;
} Edge;

#endif /* EDGE_H */