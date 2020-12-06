#include<stdio.h>
#include<stdbool.h>
#include"que.h"
#include<stdlib.h>

Queue newQ(){
Queue q;
q.first = NULL;
q.last = NULL;
q.size = 0;
return q;
}

bool isEmptyQ(Queue q){
    if(q.size==0){
        return true;
    }
    else
    {
        return false;
    }
    
}

Queue delQ(Queue q){
    if(isEmptyQ(q)){
        return q;
    }
    else{
        if(q.size==1){
            q.first = NULL;
            q.last = NULL;
            q.size = 0;
            return q;
        }

       else{ 
        //Node* temp; 
        q.first = q.first->next;
        //free(temp);
        q.size--;
        return q;
       }
    }
}

Element front(Queue q){
    return *(q.first);
}

Queue addQ(Queue q, Element e){

    Element* eNew = malloc(sizeof(Element));
    eNew->data = e.data;
    eNew->next = e.next;
    
    if(isEmptyQ(q)){
        q.size = 1;
        q.first = eNew;
        q.last = eNew;
    }
    else{
        q.last->next = eNew;
        q.last= eNew;
        q.size++;
    }
    return q;
}  

int lengthQ(Queue q){
    return q.size;
}


Element newNode(int data){
	Element n;
	n.data = data;
	n.next = NULL;
	return n;
}