#include<stdio.h>
int sparse(int a[][100],int m,int n)
{
	int count=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if (a[i][j]==0)
				count++;
		}
	if(count>(m*n/2))
		printf("sparse matrix");
	else 
		printf("not a sparse atrix");
}


int main()
{
	int m,n,arr[m][n];
	printf("Enter the order of matrix:");
	scanf("%d%d",&m,&n);
	printf("Enter the elements of the matrix:");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}



sparse(arr,m,n);
return 0;
}

