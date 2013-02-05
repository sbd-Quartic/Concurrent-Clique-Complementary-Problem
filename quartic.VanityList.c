#include <stdlib.h>
#include <pthread.h>
#include "quartic.LinkedList.h"
#include "quartic.HashTable.h"

VanityList *vanityList_create(void *element) {
	VanityList *list = malloc(sizeof(VanityList));
	LinkedList *node = malloc(sizeof(LinkedList));
	node->element = element;
	node->next = NULL;
	list->next = node;
	list->end = node;
	return list;
}	// I call create on the vertex that thread spawns on

VanityList *vanityList_append(VanityList *list, void *append) {
	LinkedList *node = malloc(sizeof(LinkedList));
	node->element = append;
	node->next = NULL;

	list->end->next = node;
	list->end = node;
	return list;
}

// Input: Set of VanityLists
// Outout: List(Array) of these VanityLists concatenated and organized into distinct sets
//		such that no VanityList in the set is connected to any other VanityList in the set.
VanityList **vanityList_disjoint(VanityList **lists) {
	VanityList **disjoint = malloc(sizeof(**lists));
	HashTable *dTable = hashTable_create(57);
	int sets = 1;

	int search;
	for (int i=0;;i++) {
		for (int j=0;;j++) {
			search = hashTable_search(dTable, lists[i]->partners[j]);
			if (search >= 0) break;
		}
		if (search >= 0) {
			dTable = hashTable_insert(dTable, lists[i]);
		} else {
			
		}
	}


	return disjoint;
}

/*
Make a short-term hashmap to store which VanityLists are members of disjoint.
Keep an int that tracks how many disjoint sets we have. Each cell should know which set it is a part of.
	keep this in the hash value structure, this hash set will not need to be resized so it will never be needed.
	Start the set count at 1 though or shit won't work.
	
For each list
	For each element
		If it is not a member of disjoint, 
			First check all of its partners. If a partner is a member of disjoint, then they belong to the same set.
				Add it to the hashmap, assign the set to the value of its partner.
			Else, assign it a new set value to establish a new set list.
		Else, if it is already a member of disjoint, then ignore it.

Create List(Array) of VanityLists. This is Disjoint.
For each cell of the hashmap
	if hash = 0, skip
	else 
		for the first element of each set, preserve the VanityList head and assign it as Disjoint[set-1]
		for every other element of the set, append the associated LL to the primary VL.
			// Make a thread for each set. Each thread onlydeals with the elements of its own set.
			// Cut this time into a fraction at trivial code and overhead

	This should result in a single VanityList head with a long, combined LL in each Disjoint array location.

Disjoint [i][j]
var = list[i][j];
	if (Disjoint[i])


*/