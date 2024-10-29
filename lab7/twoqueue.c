#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int data[MAX];
    int front1, rear1;  
    int front2, rear2; 
    int size;        
} TwoCircularQueues;

void initQueues(TwoCircularQueues* queues, int size) {
    queues->front1 = 0;
    queues->rear1 = -1;
    queues->front2 = size / 2;
    queues->rear2 = size / 2 - 1;
    queues->size = size;
}

void insertQueue1(TwoCircularQueues* queues, int value) {
    if ((queues->rear1 + 1) % (queues->size / 2) == queues->front1) {
        printf("Queue 1 is full.\n");
        return;
    }
    queues->rear1 = (queues->rear1 + 1) % (queues->size / 2);
    queues->data[queues->rear1] = value;
}

void insertQueue2(TwoCircularQueues* queues, int value) {
    if ((queues->rear2 + 1) % (queues->size / 2) == queues->front2) {
        printf("Queue 2 is full.\n");
        return;
    }
    queues->rear2 = (queues->rear2 + 1) % (queues->size / 2) + (queues->size / 2);
    queues->data[queues->rear2] = value;
}

void deleteQueue1(TwoCircularQueues* queues) {
    if (queues->front1 == (queues->rear1 + 1) % (queues->size / 2)) {
        printf("Queue 1 is empty.\n");
        return;
    }
    queues->front1 = (queues->front1 + 1) % (queues->size / 2);
}

void deleteQueue2(TwoCircularQueues* queues) {
    if (queues->front2 == (queues->rear2 + 1) % (queues->size / 2) + (queues->size / 2)) {
        printf("Queue 2 is empty.\n");
        return;
    }
    queues->front2 = (queues->front2 + 1) % (queues->size / 2) + (queues->size / 2);
}

void displayQueue1(const TwoCircularQueues* queues) {
    int i = queues->front1;
    while (i != (queues->rear1 + 1) % (queues->size / 2)) {
        printf("%d ", queues->data[i]);
        i = (i + 1) % (queues->size / 2);
    }
    printf("\n");
}

void displayQueue2(const TwoCircularQueues* queues) {
    int i = queues->front2;
    while (i != (queues->rear2 + 1) % (queues->size / 2) + (queues->size / 2)) {
        printf("%d ", queues->data[i]);
        i = (i + 1) % (queues->size / 2) + (queues->size / 2);
    }
    printf("\n");
}

int main() {
    TwoCircularQueues queues;
    int size = MAX;  

    initQueues(&queues, size);

    insertQueue1(&queues, 1);
    insertQueue1(&queues, 2);
    insertQueue1(&queues, 3);
    
    insertQueue2(&queues, 10);
    insertQueue2(&queues, 20);
    insertQueue2(&queues, 30);

    printf("Queue 1 contents:\n");
    displayQueue1(&queues);

    printf("Queue 2 contents:\n");
    displayQueue2(&queues);

    deleteQueue1(&queues);
    deleteQueue2(&queues);

    printf("Queue 1 contents after deletion:\n");
    displayQueue1(&queues);

    printf("Queue 2 contents after deletion:\n");
    displayQueue2(&queues);

    return 0;
}
