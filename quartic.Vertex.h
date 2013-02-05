#ifndef VERTEX_H
#define VERTEX_H

#include "quartic.Edge.h"
#include <stdlib.h>

typedef struct Vertex {
	struct Edge *edges;
	int capacity;
	int degree;
} Vertex;

#endif /* VERTEX_H */