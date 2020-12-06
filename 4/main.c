#include "cycle.h"
#include <sys/time.h>
//#include"linkedlist.h"

long long space_heap = 0;

void* myalloc(int tmp){
	space_heap = space_heap + tmp;
	int* temp_2 = (int*)malloc(tmp+4);
	*temp_2 = tmp;
	return (((void*)temp_2)+4);
}

void myfree(void* var){

	int* arg = (int*)(var-4);
	int size = *arg;
	space_heap= space_heap - size;
	free(arg);
}


int main(){
 
   int N = 1000000;
    FILE* fp = fopen("heap.txt","w");

    fprintf(fp," Initial value of heap is %lld.\n",space_heap);
	fclose(fp);
    
    struct linkedList* list = createList(N);

   list = createCycle(list);

    struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);

    int isCyclic = testCyclic(list);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	printf("Time taken for cyclic detection is %f ms.\n", elapsedTime);

	if(isCyclic){
		printf("Linked list is cyclic \n");
	}
	else{
		printf("Linked list is linear \n");
	}

    fp = fopen("heap.txt","a");
	fprintf(fp,"Heap space after detection of cycles is  %lld.\n",space_heap);
	fclose(fp);


}