#include"element.h"
int recursive_space;
int iterative_space;
int find_min(int a,int b);
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void msortIter(Element arr[],int n);
void msortRecursive(Element arr[],int l, int r);
int space_iter;
int space_rec;