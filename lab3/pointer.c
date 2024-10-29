#include<stdio.h>
#include<stdlib.h>

int *twice(int *ptr){
	*ptr = *ptr*2;
	return ptr;
}

int main(){
	int val,*ptr,**ptr2;
	printf("Enter a number: ");
	scanf("%d",&val);
	ptr = &val;
	ptr2 = &ptr;
	ptr = twice(ptr);

	printf("The edited number is: ",*ptr);
	printf("The number from a pointer to pointer is %d",**ptr2);

	return 0;
}
