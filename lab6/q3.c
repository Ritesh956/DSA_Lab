#include<stdio.h>

#define MAX_SIZE

void push1(int x){
	if(top1<top2-1){
		arr[++top1]=x;
	}
	else{
		printf("Stack1 is Full");
	}
}

void push2(int x){
	if(top1<top2-1){
		arr[--top2]=x;
	}
	else{
		printf("Stack2 is Full");
	}
}

int pop1(int x){
	if(top1>=0){
		return arr[top1--];
	}
	else{
		printf("Stack1 is empty");
		return -1;
	}
}

int pop2(int x){
	if(top2<MAX_SIZE){
		return arr[top2++];
	}
	else{
		printf("Stack2 is empty");
		return -1;
	}
}

int main(){
	int choice.x;
	printf("1. Push to Stack1");
	printf("2. Push to Stack2");
	printf("3. Pop to Stack1");
	printf("4. Pop to Stack2");
	printf("5.Exit\n");

	while(1){
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){

			case 1:
			printf("Enter the number to push to Stack1:");
			scanf("%d",&x);
			push1(x);
			break;

                        case2:
			printf("Enter the number to push to Stack2:);
			scanf("%d",&x);
			push2(x);
			break;

                        case3:
			printf("Popped from Stack1: %d",pop1());
			break;

                        case4:
			printf("Popped from Stack2: %d",pop2());
			break;

                        case5:
			return 0;

			default:
			printf("Invalid Choice");
		}
	}
	return 0;
}


