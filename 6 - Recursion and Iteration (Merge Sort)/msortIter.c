#include"merge.h"

int find_min(int x, int y){
	 return (x<y)? x :y; 
	 } 

void msortIter(Element arr[], int n ){
    int mid,right;
    for(int current_size = 1; current_size < n; current_size *= 2){
		for(int start = 0; start < n; start = start + 2*current_size){
			
            mid = find_min(start+current_size-1,n-1);
			
            right = find_min(start+2*current_size-1,n-1);

			Element newarr[right-start+1];
			iterative_space += 2*sizeof(int)+(right-start+1)*sizeof(Element);

			merge(arr+start,mid-start+1,arr+mid+1,right-mid,newarr);
			for(int i=0;i<right-start+1;i++){
				arr[start+i]=newarr[i];
			}
		}
	}
}