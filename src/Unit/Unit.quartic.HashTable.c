#include "../quartic.Graph.h"
#include "../quartic.HashTable.h"
#include "../MurmurHash64.h"
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
	gtest.vertices = calloc(sizeof(Vertex), testCount);

	for (int i = 0; i < testCount; i++) {
		table = hashTable_insert(table, &gtest.vertices[i], 0);
	}
	table = hashTable_refresh(table);
 	for (int i = 0; i < testCount; i++) {
 		printf("%d\n", hashTable_search(table, &gtest.vertices[i]));
 		// if (i%10==9)
 		// 	printf("\n");
 	}
 	for (int i = 0; i < testCount; i++) {
		table = hashTable_remove(table, &gtest.vertices[i]);
	}

 	free(gtest.vertices);
 	free(table->cells);
 	free(table);
}
