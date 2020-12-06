#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
#include"employee.h"
#include"stack.h"
#include"quicksort.h"
#include"insertionsort.h"
#include"sort_both.h"

void testRun(Employee list_arr[], int size, double time_taken[]){
    Employee copy_emp[size];
    double elapsedTime;
	struct timeval t1, t2;


	for(int i=0;i<size;i++){
		copy_emp[i]=list_arr[i];
    }

    gettimeofday(&t1, NULL);
	quickSort(list_arr,size,0);
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	time_taken[0]=elapsedTime; //time taken for quicksort

	gettimeofday(&t1, NULL);
	insertionSort(copy_emp,size);
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	time_taken[1]=elapsedTime; //time taken for insertion sort

}

int estimateCutoff(Employee list_arr[],int n)
{
	Employee copy_emp[n];
    double time_taken[2];	
	int min=0;
	int max=n;
	int mid=(min+max)/2;

	while(max > min)
	{
		mid=(min+max)/2;
		testRun(list_arr,mid,time_taken);
		
        if(time_taken[1]-time_taken[0]>0.0)
		{
			min = mid+1;
		}
		else if (time_taken[1]-time_taken[0]<0.0)
		{
			max = mid+1;
		}
		else
		{
			return mid;
		}
	}


}

int main(int argc, char* argv[]){
	FILE* input_file = fopen(argv[1],"r");
	int n=10; //initial size before upscaling
	Employee* list_arr = malloc(sizeof(Employee)*n);
	int c=0;
	while(!feof(input_file)){
		fscanf(input_file,"%[^ ] %d\n",list_arr[c].name, &list_arr[c].empID);
		c++;
		if(c==n-1){
			n=n*2;
			list_arr = realloc(list_arr, sizeof(Employee)*n);
		}
	}
	int cutoff_val = estimateCutoff(list_arr,c);
	printf("%d\n",cutoff_val);
	fclose(input_file);

	FILE* output_file = fopen(argv[2],"w");

	struct timeval t1, t2;
	double elapsedTime;	

	gettimeofday(&t1, NULL);
	both_sort(list_arr,c,cutoff_val);
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	fprintf(output_file, "Time for sorting %d elements is %lf ms, having cutoff value %d \n",c,elapsedTime,cutoff_val);

    //printing the sorted array to the file
	for(int i=0;i<c;i++){
		fprintf(output_file, "%s %d\n",list_arr[i].name,list_arr[i].empID);
	}

}
