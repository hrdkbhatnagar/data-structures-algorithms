#include"que.h"
#include<stdbool.h>
#define maxPriority 10
typedef struct{
    int size;
    Queue* q_arr;

}MultiQ;

typedef int Priority;
typedef int TaskID;

typedef struct{
    TaskID tid;
    Priority p;
}Task;


MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);
