#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int top;
    int arr[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[s->top];
}

void transfer(Stack *stack1, Stack *stack2) {
    while (!isEmpty(stack1)) {
        push(stack2, pop(stack1));
    }
}

void enqueue(Stack *stack1, int value) {
    push(stack1, value);
}

int dequeue(Stack *stack1, Stack *stack2) {
    if (isEmpty(stack2)) {
        if (isEmpty(stack1)) {
            printf("Queue is empty\n");
            exit(EXIT_FAILURE);
        }
        transfer(stack1, stack2);
    }
    return pop(stack2);
}

int main() {
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    enqueue(&stack1, 10);
    enqueue(&stack1, 20);
    enqueue(&stack1, 30);

    printf("Dequeued: %d\n", dequeue(&stack1, &stack2)); // Should print 10
    printf("Dequeued: %d\n", dequeue(&stack1, &stack2)); // Should print 20

    enqueue(&stack1, 40);
    enqueue(&stack1, 50);

    printf("Dequeued: %d\n", dequeue(&stack1, &stack2)); // Should print 30
    printf("Dequeued: %d\n", dequeue(&stack1, &stack2)); // Should print 40
    printf("Dequeued: %d\n", dequeue(&stack1, &stack2)); // Should print 50

    return 0;
}
