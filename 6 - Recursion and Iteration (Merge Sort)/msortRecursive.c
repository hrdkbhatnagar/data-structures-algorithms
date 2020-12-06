#include"merge.h"

void msortRecursive(Element arr[], int l, int r){

    if( l<r){
       int q = (l+r)/2;
       msortRecursive(arr,l,q);
       msortRecursive(arr,q+1,r);
       
       Element temp_arr[r-l+1];

	    recursive_space += sizeof(int)+(r-l+1)*sizeof(Element);
    
		merge(arr+l, q-l+1, arr+q+1, r-q, temp_arr);
		for(int i=0;i<r-l+1;i++){
			arr[l+i]=temp_arr[i];
            //arr[l]=temp_arr[i];
            //l++;
		}
    }
}