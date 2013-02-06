#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct LinkedList {
	void *element;
	struct LinkedList *next;
} LinkedList;

LinkedList *linkedList_create(void *element);
LinkedList *linkedList_search(LinkedList *list, void *element);
	  void *linkedList_append(LinkedList *list, void *add);
	  void *linkedList_remove(LinkedList *list, LinkedList* remove);
		int linkedList_length(LinkedList *list);

#include "quartic.LinkedList.c"

#endif /* LINKEDLIST_H */