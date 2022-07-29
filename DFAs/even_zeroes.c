#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int z;
int stateOne(char* string, int i, int len);
int stateTwo(char* string, int i, int len);
int stateThree(char* string, int i, int len);

int main(){
	char string[100];
	printf("Enter a string (less than 100 chars long) :: ");
	scanf("%s",string);
	int len = (int)strlen(string);
	int i;
	for(i = 0; i < len; ++i){
		if(string[i]!='0' && string[i]!='1'){
			printf("Invalid input, %s contains Non-binary character!",string);
			return 0;
		}
	}
	int x = stateOne(string,0,len);
	
	if(x==10){
		printf("\n%s is a valid string.\n",string);
	}
	else{
		printf("\n%s is an Invalid string.\n",string);
	}
	return 0;
}

int stateOne(char* string, int i, int len){
	if(i <= len - 1){
		if(string[i] == '1'){
			z = stateOne(string, i+1, len);
		}
		if(string[i] == '0'){
			z = stateTwo(string, i+1,len);
		}
	}	
	if(i == len){
		z = 9;
	}
	return z;
}

int stateTwo(char* string, int i, int len){
	if(i < len){
		if(string[i] == '1'){
			z = stateTwo(string, i+1, len);
		}
		if(string[i] == '0'){
			z = stateThree(string, i+1,len);
		}
	}	
	if(i == len){
		z = 9;
	}
	return z;
}

int stateThree(char* string, int i, int len){
	if(i < len){
		if(string[i] == '1'){
			z = stateThree(string, i+1, len);
		}
		if(string[i] == '0'){
			z = stateTwo(string, i+1,len);
		}
	}	
	if(i == len){
		z = 10;
	}
	return z;
}
