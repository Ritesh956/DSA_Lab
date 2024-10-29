#include<stdio.h>
void delete(int arr[],int k,int n){
	int i,j,count=0;
	for(i=0;i<n-1 && count<k;i++){
		if(arr[i]<arr[i+1]){
			for(j=i;j<n-1;j++){
				arr[j]=arr[j+1];
			}
			n--;
			i++;
			count++;
		}
	}

	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}

int main(){
	int n,k;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in array:");
	for(int i=0;i<n;i++){
		scanf("%d",arr[i]);
	}
	printf("Enter the number of elements to delete:");
	scanf("%d",&k);
	printf("Elements left in array: ",(arr,n,k));
}

