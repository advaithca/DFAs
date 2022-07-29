#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stateOne(char* string, int i, int len);
int stateTwo(char* string, int i, int len);
int stateThree(char* string, int i, int len);
int stateFour(char* string, int i, int len);

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
	int result = stateOne(string,0,len);
	
	if(result==10){
		printf("\n%s is a valid string.\n",string);
	}
	else{
		printf("\n%s is an Invalid string.\n",string);
	}
	return 0;
}

int stateOne(char* string, int i, int len){
	int z;
	if(i==len){
		return 9;
	}
	else{
		if(string[i]=='1'){
			z = stateOne(string,i+1,len);
		}
		else if(string[i]=='0'){
			z = stateTwo(string,i+1,len);
		}
		printf("%d %d 0\n",z,i);
		return z;
	}
}

int stateTwo(char* string, int i, int len){
	int z;
	if(i==len){
		return 9;
	}
	else{
		if(string[i]=='1'){
			z = stateOne(string,i+1,len);
		}
		else if(string[i]=='0'){
			z = stateThree(string,i+1,len);
		}
		printf("%d %d 1\n",z,i);
		return z;
	}
}

int stateThree(char* string, int i, int len){
	int z;
	if(i==len){
		return 10;
	}
	else{
		if(string[i]=='1'){
			z = stateFour(string,i+1,len);
		}
		else if(string[i]=='0'){
			z = stateThree(string,i+1,len);
		}
		printf("%d %d 2\n",z,i);
		return z;
	}
}

int stateFour(char* string, int i, int len){
	int z;
	if(i==len){
		return 10;
	}
	else{
		if(string[i]=='1'){
			z = stateFour(string,i+1,len);
		}
		else if(string[i]=='0'){
			z = stateThree(string,i+1,len);
		}
		printf("%d %d 3\n",z,i);
		return z;
	}
}
