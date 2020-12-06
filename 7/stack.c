#include<stdlib.h>
#include"stack.h"

dual_stack* create_stack(){
	dual_stack* stack = (dual_stack*)malloc(sizeof(dual_stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void push(dual_stack* stack, int x, int y){
	dualnode* new_ptr = (dualnode*)malloc(sizeof(dualnode));
	new_ptr->l = x;
	new_ptr->r = y;
	new_ptr->next = stack->top;
	stack->top = new_ptr;
	(stack->size)++;
}

dualnode pop(dual_stack* stack){
	dualnode temp_node;
	if(stack->size==0){
        //if stack is empty
		temp_node.l = -1;
		temp_node.r = -1;
		temp_node.next = NULL;
		return temp_node;
	}

	temp_node=*(stack->top);//add to top of the stack
	stack->top = (stack->top)->next;
	(stack->size)--;
	return temp_node;
}