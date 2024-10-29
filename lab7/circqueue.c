#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100   
#define STR_SIZE 100 

typedef struct {
    char queue[MAX][STR_SIZE]; 
    int front;                
    int rear;                 
    int size;                  
} CircularQueue;

void initQueue(CircularQueue* cq) {
    cq->front = 0;
    cq->rear = -1;
    cq->size = 0;
}

void insertcq(CircularQueue* cq, const char* str) {
    if (cq->size == MAX) {
        printf("Queue is full.\n");
        return;
    }
    cq->rear = (cq->rear + 1) % MAX; 
    strncpy(cq->queue[cq->rear], str, STR_SIZE);
    cq->queue[cq->rear][STR_SIZE - 1] = '\0'; 
    cq->size++;
}

void deletecq(CircularQueue* cq) {
    if (cq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    cq->front = (cq->front + 1) % MAX;
    cq->size--;
}

void displaycq(const CircularQueue* cq) {
    if (cq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    int i = cq->front;
    int count = 0;
    while (count < cq->size) {
        printf("%s\n", cq->queue[i]);
        i = (i + 1) % MAX;
        count++;
    }
}

int main() {
    CircularQueue cq;
    initQueue(&cq);

    insertcq(&cq, "Hello");
    insertcq(&cq, "World");
    insertcq(&cq, "Circular");
    insertcq(&cq, "Queue");

    printf("Queue contents:\n");
    displaycq(&cq);

    printf("\nDeleting one element...\n");
    deletecq(&cq);

    printf("Queue contents after deletion:\n");
    displaycq(&cq);

    return 0;
}
