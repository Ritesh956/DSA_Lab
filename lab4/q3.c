#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	int day;
	int month;
	int year;
}date;

typedef struct{
	int houseno;
	int zipcode;
	char state[50];
}address;

typedef struct{
	char name[50];
	date d;
	address addr;
}employee;

void read(employee*e,int n){
	for(int i=0;i<n;i++){
		printf("Enter firstname: ");
		scanf("%s",&(e+i)->name);
		printf("\nEnter day of DOB: ");
		scanf("%d",&((e+i)->d.day));
		printf("\nEnter month of DOB: ");
		scanf("%d",&((e+i)->d.month));
		printf("\nEnter year of DOB: ");
		scanf("%d",&((e+i)->d.year));
		printf("\nEnter House Number: ");
		scanf("%d",&((e+i)->addr.houseno));
		printf("\nEnter Zip Code: ");
		scanf("%d",&((e+i)->addr.zipcode));
		printf("\nEnter the state: ");
		scanf("%s",&((e+i)->addr.state));
	}
}

void display(employee *e,int n){
	for(int i=0;i<n;i++){
		printf("Details of employee number %d",(i+1));
		printf("\nName of the employee:%s\nDOB:%d:%d:%d\nAddress: House Number %d,Zip Code: %d,state: %s",(e+i)->d.day,(e+i)->d.month,(e+i)->d.year,(e+i)->addr.houseno,(e+i)->addr.zipcode,(e+i)->addr.state);
	}
}

int main(){
	int n;
	printf("Enter number of employees: ");
	scanf("%d",&n);
	employee *emps;
	emps=(employee*)malloc(n*sizeof(employee*));

	read(emps,n);
	display(emps,n);
	return 0;
}
