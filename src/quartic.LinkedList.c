#include <stdlib.h>

LinkedList *linkedList_create(void *element){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->element = element;
	list->next = NULL;
	return list;
}
LinkedList *linkedList_search(LinkedList *list, void *element) {
	LinkedList *travis = list;
	while ((travis->element != element) && (travis->next != NULL))
		travis = travis->next;
	return travis;
}
void *linkedList_append(LinkedList *list, void *add) {
	LinkedList *node = malloc(sizeof(LinkedList));
	node->element = add;
	node->next = NULL;

	LinkedList *travis = list;
	while (travis->next != NULL)
		travis = travis->next;

	travis->next = node;
}
void *linkedList_remove(LinkedList *list, LinkedList* rm) {
	LinkedList *travis = list;
	while (travis->next != NULL) {
		if (travis->next == rm) {
			travis->next = rm->next;
			free(rm);			
		}
		travis = travis->next;		
	}
}
int linkedList_length(LinkedList *list) {
	int length = 1;
	LinkedList *travis = list;
	while (travis->next != NULL) {
		travis = travis->next;
		length++;
	}
	return length;
}