#include<stdio.h>
#include"multiq.h"
//#include"que.h"
#include <sys/time.h> 

MultiQ loadData(FILE* f){
    printf("\nstart of load data");
    MultiQ mq = createMQ(10);
    printf("\n after createmq");
    int a,b;
	Task t;

    while(!feof(f)){
        fscanf(f,"%d,%d",&a,&b);
		fgetc(f);
		t.tid = a;
		t.p = b;
        printf("\n before addmq");
        mq = addMQ(mq,t);
        printf("\nafer addmq");
    };
    return mq;
}

MultiQ testDel(MultiQ mq, int num){
    for (int i = 0; i < num; i++)
    {
        delNextMQ(mq);
    }
    return mq;
    
}

int main(){
    struct timeval t1, t2;
    double elapsedTime;
    printf("test1");
    // start timer
    gettimeofday(&t1, NULL);
    FILE* f = fopen("input10.txt","r");
    printf("test2");
    MultiQ mq  = loadData(f);
    printf("test3");
    fclose(f);
    //stop timer
    gettimeofday(&t2, NULL);
    //compute and print time in ms
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
     printf("Total time is %f ms", &elapsedTime);
    printf("test");
    return 0;
}