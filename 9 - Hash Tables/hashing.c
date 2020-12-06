#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<stdlib.h>
#include<locale.h>

int hash(wchar_t* string,int baseNumber, int tableSize){
    int hashnumber =  0;
    //int ASCII_sum =  0;
    for(int i = 0 ; i < wcslen(string); i++){
        hashnumber += string[i];
    }
    hashnumber = (hashnumber)%baseNumber;
    hashnumber = (hashnumber)%tableSize;
    return hashnumber;

}

int collisionCount(wchar_t* str_arr[],int baseNumber, int tableSize){
    int collisions = 0 ;
    int hashnumber;
    int hash_before[tableSize];

    for(int i  = 0 ; i < strlen(str_arr); i++){
        hashnumber = hash(str_arr[i],baseNumber,tableSize);  
        if(hash_before[hashnumber]==1){ //check flag
            collisions++;

        }   
        else
        {
            hash_before[hashnumber]=1 ; //set flag
        }
         
    }
    return collisions;
}

wchar_t** validStrings(char* filename, int* length){
    FILE* inputfile = fopen(filename,"r");
    int init_size = 10;
    wchar_t** str_arr = NULL;
    str_arr=(wchar_t**)malloc(sizeof(wchar_t**)*init_size);

    wchar_t curr_string[10000] = {0}; //initializing

    int valid_string_count = 0;
    
    while(fwscanf(inputfile,L"%ls ",curr_string)!=EOF){
        str_arr[valid_string_count] = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(curr_string)+1));
        wcscpy(str_arr[valid_string_count],curr_string);
        valid_string_count++;

        if(valid_string_count>= init_size){ //dynamic expansion 
            init_size*=2;
            str_arr=(wchar_t**)realloc(str_arr,sizeof(wchar_t*)*init_size);

        }
       
        *length=valid_string_count;
        fclose(inputfile);
        return str_arr;
    }



}
int profiler(char* filename){
    //hardcoded values
    int baseNumber[3][6] = {{5001,5003,5009,5000011,5000087,5000111},
                            {50101,50111,50119,50000207,50000221,50000231},
                            {500153,500167,500173,500000101,500000117,500000183}};
    int tableSize[] = {5000,50000,500000};
    int collisions[18];

     wchar_t** str_arr;
     int length;
     int collision;

     str_arr = validStrings(filename,&length);
     
     for(int i =0 ; i<3;i++){
         for(int j=0;j<6;j++){
             collision = collisionCount(str_arr,baseNumber[i][j],tableSize[i]);
             printf("Table %d Base %d Collision-Count %d \n",tableSize[i],baseNumber[i][j],collision);
            collisions[j+i*6]=collision;
         }
     }

    int min_indices=0;
	int min = collisions[0];

	for(int i=0;i<18;i++){
		if(collisions[i]<min){
			min = collisions[i];
			min_indices=i;
		}
	}
	return min_indices;


}

int main(int argc, char* argv){
    setlocale(LC_ALL, "en_US.UTF-8");


    int length = 0 ; //init
    wchar_t** str_arr = validStrings(argv[1],&length);
    
    	for(int i=0;i<length;i++){
		if(i==11409){//full
			printf("%d    %ls %lu  \n",i,str_arr[i],wcslen(str_arr[i]));
		}
		if(strlen(str_arr[i])==0){
			printf("invalid");
		}

	profiler(argv[1]);
	printf("%d %d\n",length ,collisionCount(str_arr,5003, 5000));
    return 0;
}
}
