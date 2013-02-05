#include "quartic.Graph.h"
#include "quartic.Hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

uint64_t hash(void *key) {
	return MurmurHash64A(key, 8, 0x9747b28c);
}

int main(int argc, char **argv) {
	
	int testCount = atoi(argv[1]);
	HashTable *table = hashTable_create(1031);
	Graph gtest;
	gtest.edges = calloc(sizeof(Edge), testCount);


	for (int i = 0; i < testCount; i++) {
		table = hashTable_insert(table, &gtest.edges[i], 0);
	}
	table = hashTable_refresh(table);
 	for (int i = 0; i < testCount; i++) {
 		// hashTable_search(table, &gtest.edges[i]);
 		printf("%d\n", hashTable_search(table, &gtest.edges[i]));
 		// if (i%10==9)
 		// 	printf("\n");
 	}
 	for (int i = 0; i < testCount; i++) {
		table = hashTable_remove(table, &gtest.edges[i]);
	}

 	free(gtest.edges);
 	free(table->cells);
 	free(table);
	// hashTable_search(&table);


	// printf("%lu\n", hash(&table));

	// Vertex test;
	// Vertex test2;

	// test.edges = malloc(65536*sizeof(Edge));
	// test2.edges = malloc(120);


	// printf("%p\n", test.edges);
	// printf("%p\n", test2.edges);
	// printf("%ld\n", sizeof(Edge));
	// printf("%ld\n", sizeof(char));
	// printf("%lu\n", MurmurHash64A(&test.edges, 8, 5));
	// printf("%lu\n", MurmurHash64A(&test2.edges, 8, 5));

	// printf("Size of Edge:\t\t %ld\n", sizeof(Edge));
	// printf("Size of Edge(pointer):\t %ld\n", sizeof(test.edges));
	// printf("Size of Edge(total):\t %ld\n", sizeof(*test.edges));
	// printf("Size of Vertex:\t\t %ld\n", sizeof(test));
}
