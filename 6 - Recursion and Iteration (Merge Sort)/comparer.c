#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include "element.h"
#include "merge.h"

//#define RAND_MAX  9;

int main(){
	int N;
	printf("Enter the no. of elements to be sorted (based on CGPA)\n");
	scanf("%d",&N);

	printf("Creating array of random elements...\n");
	Element iter_arr[N];
	Element recursive_arr[N];
	float rand1,rand2;

	srand(time(0)); //seeding

	for(int i=0;i<N;i++){
		rand1 =rand()%9;
      //  srand(time(NULL));
		rand2 = (rand()%99)/100.00;
       // printf("rand2 : %f  ",rand2);
		recursive_arr[i].cgpa= rand1+rand2;
		iter_arr[i].cgpa= rand1+rand2;
       // printf("%f  \n",recursive_arr[i].cgpa);
	}


	struct timeval t1, t2;
	double elapsedTime;
	
    iterative_space=0;
	recursive_space=0;

	gettimeofday(&t1, NULL);
	msortRecursive(recursive_arr, 0,N-1);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Recursive Merge sorted %d elements in %lf ms\n",N,elapsedTime);
	printf("Recursive Merge Sort Used Space -  %d\n",recursive_space);

	gettimeofday(&t1, NULL);
    msortIter(iter_arr,N);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	printf("Iterative Merge sorted %d elements in %lf ms \n",N,elapsedTime);
	printf("Iterative Merge sort Used space  - %d\n",iterative_space);
}