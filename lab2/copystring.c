#include<stdio.h>
void copy(char str1[],char str2[],int i){
	if(str1[i]=='\0'){
		str2[i]='\0';
		return ;
	}
	else{
		str[i]=str2[i];
		copy(str1,sr2,i+1);
	}
}
void main(){
	char ch[10],char ch2[10];
	printf("Enter the string:);
	scanf("%s",ch1);
	copy(cha1,ch2,0);
	printf("Copied string is %s",ch2);
}

