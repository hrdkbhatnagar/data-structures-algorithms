#include"sort_both.h"

void both_sort(Employee arr[], int n, int s){
    quickSort(arr,n,s);
    insertionSort(arr,n);
}