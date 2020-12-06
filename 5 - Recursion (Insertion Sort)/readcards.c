#include"readcards.h"

CRED_CARD* read_cards(CRED_CARD* card_arr, char* filename , int* finalsize){
    
    int size = 5;
    card_arr = (CRED_CARD*)malloc(sizeof(CRED_CARD)*size);
	FILE* f = fopen(filename,"r"); //buffer

	if(f==NULL){
		printf("file does not exist, exiting...");
		exit(0);
	}

	CRED_CARD newcard;

    int i=0;
	while(!feof(f)){
		fscanf(f,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(newcard.card_number),newcard.bank_code,newcard.exp_date,newcard.fname,newcard.lname);
		card_arr[i++]=newcard;

		if(i==size){
			size*=2;
			card_arr = realloc(card_arr,sizeof(CRED_CARD)*size); //load management
		}
	}

	fclose(f);
	
	*finalsize = i;
	
	return card_arr;
}