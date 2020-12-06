#include"employee.h"

void insertInOrder(Employee arr[], int n, Employee newEmp){
	Employee emp = newEmp;
	Employee temp_emp;

	for(int i=0;i<n;i++){
		if(emp.empID < arr[i].empID || i==n-1){
            //swapping
			temp_emp = emp;
			emp = arr[i];
			arr[i]=temp_emp;
		}
	}
}

void insertionSort(Employee arr[],int n){
	for(int i=0;i<n;i++){
		insertInOrder(arr, i+1, arr[i]);
	}
}