#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct LinkedList {
	void *element;
	struct LinkedList *next;
} LinkedList;

LinkedList *LinkedList_append(LinkedList *list, void *add);
LinkedList *LinkedList_insert(LinkedList *list, void *add);
LinkedList *LinkedList_remove(LinkedList *list, void *remove);
LinkedList *LinkedList_search(LinkedList *list, void *element);

#include "quartic.LinkedList.c"

#endif /* LINKEDLIST_H */