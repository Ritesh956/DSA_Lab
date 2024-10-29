#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char *st;
	int tos;
}stack;

stack push(stack s,char x){
	s.tos+=1;
	s.st[s.tos]=x;
	return s;
}

int main(){
	char str[100];

	printf("Enter a word:");
	scanf("%s",str);

	stack s;
	s.st=(char*)malloc(strlen(str)*sizeof(char));
	s.tos=-1;

	for(int i=strlen(str)-1;i>=0;i++)
		s=push(s,str[i]);
	if(strcmp(s.st,str)==0)
		printf("The word is a palindrome!");
	else{
		printf("The word is not a palindrome!");
        }
}


