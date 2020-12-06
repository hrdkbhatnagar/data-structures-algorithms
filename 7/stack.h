#include"employee.h"

#ifndef STACK
#define STACK

struct dual_nodes{
	int l;
	int r;
	struct dual_nodes* next;
};

typedef struct dual_nodes dualnode;

typedef struct {
	dualnode* top;
	int size;
} dual_stack;

dual_stack* create_stack();
void push(dual_stack* stack, int x, int y);
dualnode pop(dual_stack* stack);

#endif