#include <stdlib.h>

#include <stdio.h>

LinkedList *LinkedList_append(LinkedList *list, void *add) {
	LinkedList *node = malloc(sizeof(LinkedList));
	node->element = add;
	node->next = NULL;

	list->next = node;
	return node;
}
LinkedList *LinkedList_insert(LinkedList *list, void *add) {

}
LinkedList *LinkedList_remove(LinkedList *list, void *remove) {

}
LinkedList *LinkedList_search(LinkedList *list, void *element) {

}