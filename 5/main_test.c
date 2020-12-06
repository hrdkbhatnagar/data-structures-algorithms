#include"measure.h"
#include"insertionsort.h"
#include"readcards.h"
#include<stdio.h>
int main (int argc, char* argv[]){
	
	time_reading(argv[1],argv[2]);
	time_sorting(argv[1],argv[2]);
	memory_sorting(argv[1],argv[2]);

	return 0;
}