#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int empty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = x;
    q->size++;
}

int dequeue(Queue* q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return -1; 
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return item;
}

void reverseQueue(Queue* q) {

    if (empty(q)) {
        return;
    }
    
    int item = dequeue(q);

    reverseQueue(q);

    enqueue(q, item);
}

void printQueue(Queue* q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    int count = q->size;
    while (count--) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    
    printf("Original queue: ");
    printQueue(&q);

    reverseQueue(&q);
    
    printf("Reversed queue: ");
    printQueue(&q);
    
    return 0;
}
