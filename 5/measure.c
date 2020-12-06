#include"measure.h"
#include<math.h>
#include"readcards.h"

void time_reading(char* file_to_read,char* file_to_print){
	CRED_CARD* card_arr;
	int size;

	FILE* file_buffer = fopen(file_to_print,"a");

	struct timeval t1, t2; 
	double time_taken;
		
	gettimeofday(&t1, NULL);
	card_arr = read_cards(card_arr, file_to_read ,&size);
	gettimeofday(&t2, NULL);

	time_taken = (t2.tv_sec - t1.tv_sec) * 1000.0;
	time_taken += (t2.tv_usec - t1.tv_usec) / 1000.0;

	fprintf(file_buffer, "Read %d structs in %lf ms \n", size, time_taken);
	fclose(file_buffer);
}

void time_sorting(char* file_to_read, char* file_to_print){
	CRED_CARD* card_arr;
	int size;
	FILE* file_buffer = fopen(file_to_print,"a");

	struct timeval t1, t2;
	double time_taken;
		
	gettimeofday(&t1, NULL);
	card_arr = read_cards(card_arr,file_to_read,&size);
	insertionSort(card_arr,size);
	gettimeofday(&t2, NULL);

	time_taken = (t2.tv_sec - t1.tv_sec) * 1000.0;
	time_taken += (t2.tv_usec - t1.tv_usec) / 1000.0;

	fprintf(file_buffer, " %d structs were sorted in in %lf ms.\n",size , time_taken);
	fclose(file_buffer);
}

void memory_sorting(char* file_to_read,char* file_to_print){
	CRED_CARD* card_arr;
	int size;
	FILE* file_buffer = fopen(file_to_print,"a");

	int local_var;		
	card_arr = read_cards(card_arr,file_to_read,&size);
	insertionSort(card_arr,size);

	fprintf(file_buffer, " %d Elements sorted, Stack Top: %llu, Stack Bottom:%llu, Difference: %llu \n",size ,stack_top ,&local_var, (unsigned long long)&local_var-(unsigned long long)stack_top);
	fclose(file_buffer);
}