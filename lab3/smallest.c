#include<stdio.h>
#include<stdlib.h>

int Smallest (int *arr,int n){
	int smallest = *arr;
	for(int i=0;i<n;i++){
		if(*(arr+i)<smallest){
			smallest = *(arr+i);
		}
	}
	return smallest;
}

int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);

	int *arr = (int*)malloc(n*sizeof(int));

	printf("Enter the elements in the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	int smallest = Smallest(arr,n);

	printf("The smallest elemnt in the array is: %d",smallest);

	free(arr);
	return 0;
}

