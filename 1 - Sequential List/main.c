#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int i;
 seqarr seq;
 joblist arr;
 initialize_elements (arr);
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (arr,seq);
 copy_sorted_ele (seq , arr); 
 printjoblist(arr);
}
 
