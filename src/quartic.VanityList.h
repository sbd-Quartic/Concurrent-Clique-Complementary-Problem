/* VanityList is a linked list variant wherein the Head is of a different structure than the rest of the nodes,
containing no element, but instead a pointer to the final node of the list.
It is called a VanityList because it is for lists in which you don't care about the inside-- 
it's the outside that counts. 
*/

#ifndef VANITYLIST_H
#define VANITYLIST_H

#include "quartic.LinkedList.h"

typedef struct VanityList {
	LinkedList *next;
	LinkedList **partners;
} VanityList;

VanityList *vanityList_create(void *element);
VanityList *vanityList_append(VanityList *list, void *append);

#endif /* VANITYLIST_H */