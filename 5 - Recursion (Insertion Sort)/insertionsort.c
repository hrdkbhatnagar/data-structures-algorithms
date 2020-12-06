#include"insertionsort.h"

void insertInOrder(CRED_CARD* card_array, int n, CRED_CARD newcard){
    CRED_CARD card = newcard;
    CRED_CARD tempcard;
    for(int i = 0 ; i < n ; i ++){
        if(card.card_number < card_array[i].card_number || i == n -1 ){
            //swapping
            tempcard = card;
            card = card_array[i];
            card_array[i]=tempcard;
            
        }
    }
}

void insertionSort(CRED_CARD* card_arr,int n ){
    if(n == 0 ){
       stack_top = &n;
        return;
        //base case
    }

    insertionSort(card_arr,n-1);
	insertInOrder(card_arr,n,card_arr[n-1]);
}