#include"cycle.h"

int testCyclic(struct linkedList* list){

	struct node* traversal = list->first;

	if(traversal==NULL) return 0;

	struct node* prev_node = list->first;
	struct node* prev_of_prev = NULL;	

	while(traversal->next != NULL){

		if(prev_node != list->first)
			prev_node->next = prev_of_prev;
		prev_of_prev = prev_node;
		prev_node = traversal;
		traversal = traversal->next;

		if(traversal==list->first){
			return 1;
		}
	}
	return 0;
}