#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char name[50];
	int rno;
	double cgpa;
}student;

void read(student *stds,int n);
        int i;
        for(i=0;i<n;i++){
	        printf("Enter student firstname: ");
	        scanf("%s",(stds+i)->name);
	        printf("Enter roll no: ");
	        scanf("%d",&((stds+i)->rno));
	        printf("Enter Cgpa: ");
	        scanf("%lf",&((stds+i)->cgpa));
        }
}

void display(student  *stds,int n){
	int i;
	for(i=0;i<n;i++){
		printf("\nName of sudent:%s\nRoll Number: %d\nCGPA: %lf\n",(stds+i)->name,(stds+i)->rno,(stds+i)->cgpa);
	}
}

void sort(student *st,int n){
	student temp;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n;j++){
			if(st[i].rno > st[j].rno){
				temp=st[i];
				st[i]=st[j];
				st[j]=temp;
			}
		}
	}
}

int main(){
	int n,i;
	printf("Enter the number of stdudents: ");
	scanf("%d",&n);

	student *st;
	st=(student*)malloc(n*sizeof(student*));

	read(st,n);

	printf("\nThe details of the first student are: ");
	printf("\nName of student: %s\nRoll Noumber: %d\nCGPA:%lf\n"st[0].name,st[0].rno,st[0].cgpa);

	sort(st,n);
        printf("Details of student sorted in ascending order :\n");

	display(st,n);

	return 0;
}
