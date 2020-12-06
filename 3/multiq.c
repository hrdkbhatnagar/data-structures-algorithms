#include"multiq.h"
#include<stdbool.h>
#include<stdlib.h>

MultiQ createMQ(int num){
    MultiQ mq;
    mq.size = num;
    mq.q_arr = malloc(sizeof(Queue)*num);
    return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
     printf("\n inside addmq");
   /* Element newE;
    newE.data = t.tid;
    newE.next = NULL; */
   
   Element newE = newNode(t.tid);
    mq.q_arr[t.p-1] = addQ(mq.q_arr[t.p-1],newE);
    return mq;
}

bool isEmptyMQ(MultiQ mq){
  for(int i=0 ; i<=mq.size-1 ; i++){
      if(isEmptyQ(mq.q_arr[i])){

      }
      else{
          return false;
      }
  }
  return true;
}

Task nextMQ(MultiQ mq) {
   if(isEmptyMQ(mq)){
       Task nullTask;
       nullTask.tid = -1;
       nullTask.p  = -1;
       return nullTask;
   }   
   else
   {
       Task newTask;
       int i = mq.size - 1;
       while (isEmptyQ(mq.q_arr[i]))
       {
           i--;
       }
       newTask.tid  = front(mq.q_arr[i]).data;
       newTask.p = i+1;

        return newTask;
   }
    
}

MultiQ delNextMQ(MultiQ mq){
    if(isEmptyMQ(mq)){
      return mq;
   }  
   else
   {
       //Task newTask;
       int i = maxPriority - 1;
        while (isEmptyQ(mq.q_arr[i]))
       {
           i--;
       }
       mq.q_arr[i] = delQ(mq.q_arr[i]);
       return mq;


   }
   
}

int sizeMQ(MultiQ mq){
    int items = 0 ;
    for(int i = mq.size ; i>= 0; i--){
        items = items + lengthQ(mq.q_arr[i]);
    }
}

int sizeMQbyPriority(MultiQ mq, Priority p){
    int items = lengthQ(mq.q_arr[p-1]);
    return items;
}

Queue getQueueFromMQ(MultiQ mq,Priority p){
 return mq.q_arr[p-1];
}