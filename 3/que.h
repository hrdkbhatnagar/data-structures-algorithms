#include<stdio.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node Element;

struct queue
{
    Element* first;
    Element* last;
    int size;
};

typedef struct queue Queue;

Queue newQ();
bool isEmptyQ(Queue q);
Queue delQ(Queue q) ;

Element front(Queue q);
Queue addQ(Queue q , Element e);
int lengthQ(Queue q);

Element newNode(int data);