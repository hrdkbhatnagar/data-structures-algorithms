#include<stdio.h>
#include<sys/time.h>
#include<math.h>
#include<stdlib.h>

#ifndef CREDCARD
#define CREDCARD
typedef struct 
{
    unsigned long long card_number;
    char bank_code[6];
    char exp_date[8];
    char fname[20];
    char lname[20];

}CRED_CARD;
#endif
