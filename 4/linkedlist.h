#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int element;
	struct node * next;
};

struct linkedList {
	int count;
	struct node * first;
};

void* myalloc(int x);
void myfree(void* x);

struct linkedList* createList(int N);
void insertFirst (struct linkedList * head, int ele);
struct linkedList * createCycle(struct linkedList* Ls);
