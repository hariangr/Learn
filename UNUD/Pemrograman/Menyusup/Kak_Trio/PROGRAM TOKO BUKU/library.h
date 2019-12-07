#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <string.h>
#include <time.h>
#include "struct.h"

void read(char val[], char str[]){
	printf(str);
	fflush(stdin);
	gets(val);
}

void read_int(int *val, char str[]){
	printf(str);
	scanf("%d",val);
}

void trim(char str[], char new_str[]){
	int i, j = 0;

	for (i = 0; i < strlen(str); i++) {
		if(str[i] == '\n' || str[i] == '\t') 
			continue;
		new_str[j] = str[i];
		j++;	
	}
}

Date getDateNow(void){
	time_t t;
	Date date_now;
	struct tm *time_info;
	
	time(&t);

	time_info = localtime(&t);

	date_now.day = time_info->tm_mday;
	date_now.month = time_info->tm_mon + 1;
	date_now.year = time_info->tm_year + 1900;

	return date_now;
}

int cmp(char str1[], char str2[]){
	if(strcmp(str1,str2) == 0)
		return 1;
	return 0;
}

void autoInc(char str[], int i){
	if(i!=0){ 	
		str[i]++;
		if(str[i] == ':') {
			str[i] = '0';
			autoInc(str, i-1);
		}
	}
}

void autoId(char str[], char str_new[]){
	strcpy(str_new, str);
	autoInc(str_new, strlen(str)-1);
}

#endif