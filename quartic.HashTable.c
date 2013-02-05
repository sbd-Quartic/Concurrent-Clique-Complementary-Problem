#include "MurmurHash64.h"
#include "quartic.Prime.h"

HashTable *hashTable_create(int capacity) {
	HashTable *table = malloc(sizeof(HashTable));
	table->capacity = capacity;
	table->cells = calloc(capacity, sizeof(Cell));
	table->elements = 0;
	table->ratio = 0.6;
	table->tombstones = 0;
	return table;
}

HashTable *hashTable_expand(HashTable *original) {
	HashTable *expanded = malloc(sizeof(HashTable));
	expanded->capacity=nextPrime(original->capacity << 1);
	expanded->cells = calloc(expanded->capacity, sizeof(Cell));
	expanded->elements = 0;
	expanded->ratio = original->ratio;
	expanded->tombstones = 0;

	for(int i=0; i < original->capacity; i++) {
		if(original->cells[i].hash) {
			hashTable_insert(expanded, original->cells[i].key, original->cells[i].hash);
		}
	}
	free(original->cells);
	free(original);
	return expanded;
}

HashTable *hashTable_refresh(HashTable *original) {
	HashTable *refreshed = malloc(sizeof(HashTable));
	refreshed->capacity=original->capacity;
	refreshed->cells = calloc(refreshed->capacity, sizeof(Cell));
	refreshed->elements = 0;
	refreshed->ratio = original->ratio;
	refreshed->tombstones = 0;

	for(int i=0; i < original->capacity; i++) {
		if(original->cells[i].hash) {
			hashTable_insert(refreshed, original->cells[i].key, original->cells[i].hash);
		}
	}
	free(original->cells);
	free(original);
	return refreshed;
}

HashTable *hashTable_insert(HashTable *table, void *add, uint64_t hashpass) {
	uint64_t hashValue;
	if (hashpass) hashValue = hashpass;
	else hashValue = hash(&add);

	int index = (int)(hashValue%table->capacity);
	int results = hashTable_search(table, add);
	if (results == -2) {
		table->cells[index].key = add;
		table->cells[index].hash = hashValue;
		table->elements++;
		if (table->cells[index].dead) {
			table->cells[index].dead = 0;
			table->tombstones--;
		}
		if (((float)table->elements / (float)table->capacity) > table->ratio)
			table = hashTable_expand(table);
	} else if (results == -1) {
		for (int i=1;; i++) {
			int j=i*i;
			int newIndex = (index+j)%table->capacity;
			if (!table->cells[newIndex].hash) {
				table->cells[newIndex].key = add;
				table->cells[newIndex].hash = hashValue;
				table->elements++;
				if (table->cells[newIndex].dead) {
					table->cells[newIndex].dead = 0;
					table->tombstones--;
				}
				break;
			}
		}
	}
	return table;
}

HashTable *hashTable_remove(HashTable *table, void *remove) {
	int index = hashTable_search(table,remove);
	if (index >= 0) {
		table->cells[index].key = 0;
		table->cells[index].hash = 0;
		table->cells[index].dead = 1;
		table->elements--;
		table->tombstones++;
		if (((float)(table->elements+table->tombstones) / (float)table->capacity) > table->ratio)
			table = hashTable_refresh(table);
	}
	return table;
}

int hashTable_search(HashTable *table, void *find) {
	uint64_t hashValue = hash(&find);
	int index = hashValue%table->capacity;

	if (table->cells[index].hash || table->cells[index].dead) {
		if (table->cells[index].key == find) {
			return index;
		} else {
			for (int i=1;; i++) {
				int j=i*i;
				int newIndex = (index+j)%(table->capacity);
				if(table->cells[newIndex].key == find)
					return newIndex;
				else if (!table->cells[newIndex].hash)
					if (!table->cells[newIndex].dead)
						return -1;
			}
		}
	}
	return -2;
}