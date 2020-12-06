#include <stdio.h>
#include "element.h"
#include "merge.h"

int main(){
//testing  values for the array
	Element arr[10];
	arr[0].cgpa =  9.5;
	arr[1].cgpa =  4.5;
	arr[2].cgpa =  8.2;
	arr[3].cgpa =  2.5;
	arr[4].cgpa =  9.1;
	arr[5].cgpa =  5.5;
	arr[6].cgpa =  6.7;
	arr[7].cgpa =  8.9;
	arr[8].cgpa =  9.2;
	arr[9].cgpa =  9.9;

//uncomment the required sorting algorithm
    //msortIter(arr, 10);
    msortRecursive(arr,0,9);

	for(int i=0;i<10;i++){
		printf("%lf ",arr[i].cgpa);
	}

}