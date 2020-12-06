#include"linkedlist.h"

void insertFirst(struct linkedList * head, int ele){

	struct node *link = (struct node*) myalloc (sizeof(struct node)); 
	link->element = ele;
	link->next = head->first;
	head -> first = link;
	head -> count ++;
}


struct linkedList* createList(int N){

    struct linkedList* Ls = (struct linkedList*) myalloc(sizeof(struct linkedList));
    Ls->count  = 0;
    Ls ->first = NULL;

    int rand_no;

    for(int i = 0 ; i<N ; i++){
        rand_no = rand();
        insertFirst(Ls,rand_no);
    }
    return Ls;
}

struct linkedList * createCycle(struct linkedList * Ls){

	int rand_no = rand();

	if(rand_no < RAND_MAX/2)
    {
		//printf("it is not cyclic\n");
		return Ls;
	}

	else{
		//printf("the linked list is cyclic \n");
        
		int arr[Ls->count];
		

		struct node* traversal = Ls->first;
        int i=0;
        
		while(traversal->next != NULL){

			arr[i]= traversal->element;
			i++;
			traversal=traversal->next;
		}

		rand_no = rand();

		double ratio = ((double)Ls->count)/RAND_MAX;
		rand_no*=ratio;

		int cycle_temp = arr[rand_no];

		struct node* cycle_temp_node = NULL;
		traversal = Ls->first;

		while(traversal->next != NULL){

			if(traversal->element == cycle_temp){
				cycle_temp_node = traversal;
			}
			traversal=traversal->next;
		}

		traversal->next = cycle_temp_node;
		return Ls;
	}
}