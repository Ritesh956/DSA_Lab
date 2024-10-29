#include<stdio.h>
void ssort(int a[100],int n, int idx)
{
	if(idx>=n-1)
		return;
	int min = idx;
	for(int i=idx+1;i<n;i++)
	{
		if(a[i]<a[min])
		{
			int temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			ssort(a,n,idx);
		}
	}
	ssort(a,n,idx+1);
}
int main()
{
	printf("\nenter array size");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("\nenter the values");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	ssort(a,n,0);
	printf("\n sorted aaray is");
	for(int i=0;i<n;i++)
		printf("\n %d",a[i]);
	return 0;



}
