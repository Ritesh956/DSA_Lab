#include<stdio.h>
void towerofHanoi(int n,char srce,char temp,char dest){
	if(n==1){
		printf("Move disk1 from rod%c to rod %c",srce,dest);
		return;
	}

	towerofHanoi(n-1,srce,dest,temp);
	printf("\nMove disk%d from rod%c to rod%c",srce,temp);
	towerofHanoi(n-1,dest,temp,srce);
}

int main(){
	int n;
	char srce,temp,dest;
	printf("Enter the number of discs");
	scanf("%d",&n);
	towerofHanoi(n,srce,temp,dest);
	return 0;
}
