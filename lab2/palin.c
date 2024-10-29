#include<stdio.h>
void IsPalin(char str[],int idx){
	int len=len(str)-(idx+1);
	if(str[idx]==str[len]){
		printf("Palindrome");
	}
	if(idx!='\0'){
		idx++;
		IsPalin();
	}
	else{
		printf("Not Palindrome");
	}

int main(){
	char str[10];
	printf("Enter the string:");
        scanf("%s",&str[]);
	printf(IsPalin(str[],0);
}
