#include<stdio.h> 
int Lsearch(int arr[],int size , int key) 
{ 
        for(int i=0;i<size;i++) 
                if(arr[i]==key) 
                        return i; 
 
 
return -1; 
}

int  main()
{
	int n;
	printf("the total number of values:");
	scanf("%d",n);
	int arr[n];
	printf("\n ENter the values");
	for(int i=0;i<n;i++)
		scanf("%d",arr[i]);
	printf("enter the key");
	int key;
	scanf("%d",key);

int pos=Lsearch(arr,n,key);
printf("\nthe value %d is at the index %d",key,pos);
return 0;
}

~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
~                                                                                                                                                                               
-- VISUAL --                                                                                                                                        10        10,2          All

