#include <stdio.h>
#include"quicksort.h"

void swap(Employee* e1, Employee* e2){
	Employee temp = *e2;
	*e1=*e2;
	*e2=temp;
}

int partition(Employee arr[], int l, int r){
	int x = arr[r].empID;
	int i = l-1;
	for(int j=l;j<r;j++){

		if(arr[j].empID<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[++i],&arr[r]);
	return i;
}

void quickSort(Employee arr[], int n, int S){
	dual_stack* custom_stack = create_stack();
	dualnode temp;
	int l,r,next;
    /* recursive method is below
    q = partitiion (A,p,r);
    qs(A,p,q-1);
    qs(A,q+1,r);
    */
    push(custom_stack,0,n-1); //initialization of stack

	while(custom_stack->size > 0){
		temp = pop(custom_stack);//similar to recursion given above
		l = temp.l;
		r = temp.r;
		if(r-l>S){
			next = partition(arr,l,r);//similar to  q = partition(A,p,r)
			push(custom_stack,l,next-1);//simiar to qs(A,p,q-1)
			push(custom_stack,next+1,r);//similar to qs(A,q+1,r)
		}
	}
}