#include<stdio.h>
void reverse(int *arr,int n){
	int *start = arr;
	int *end = arr+n-1;
	int temp;

	while(start<end){
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main(){
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);

        int arr[50];

	printf("Enter the elements in the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	reverse(arr,n);

	printf("Reversed Array :");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	return 0;
}




