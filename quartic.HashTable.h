#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>

typedef struct Cell {
	void *key;
	uint64_t hash;
	char dead;
} Cell;

typedef struct HashTable {
	Cell *cells;
	int capacity;
	int elements;
	int tombstones;
	float ratio;	
} HashTable;

uint64_t hash(void *key);
HashTable *hashTable_create(int capacity);
HashTable *hashTable_insert(HashTable *table, void *add, uint64_t hashpass);
HashTable *hashTable_expand(HashTable *original);
HashTable *hashTable_remove(HashTable *table, void *remove);
HashTable *hashTable_refresh(HashTable *original);
int hashTable_search(HashTable *table, void *find);

#include "quartic.HashTable.c"

#endif /* HASHTABLE_H */
