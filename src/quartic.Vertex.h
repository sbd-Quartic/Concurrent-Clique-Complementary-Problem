#ifndef VERTEX_H
#define VERTEX_H

#include <stdlib.h>

typedef struct Vertex {
	struct Vertex *incidents;
	int capacity;
	int degree;
} Vertex;

#endif /* VERTEX_H */