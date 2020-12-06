#include<stdio.h>
#include"employee.h"
#include"stack.h"
#include"quicksort.h"
#include"insertionsort.h"
#include"sort_both.h"
int main(){

	Employee arr[10];
	arr[0].empID = 9;
	arr[1].empID = 8;
	arr[2].empID = 6;
	arr[3].empID = 99;
	arr[4].empID = 5;
	arr[5].empID = 4;
	arr[6].empID = 3;
	arr[7].empID = 2;
	arr[8].empID = 1;
	arr[9].empID = 33;

	for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}
	putchar('\n');
//	both_sort(arr,10,5);
//	quickSort(arr,10,0);
//	insertionSort(arr,10);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}
	putchar('\n');

}