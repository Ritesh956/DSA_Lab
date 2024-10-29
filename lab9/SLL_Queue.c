#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node** rear, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(Node** front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = (*front)->data;
    Node* temp = *front;
    *front = (*front)->next;
    free(temp);
    return data;
}

void printQueue(Node* front) {
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&rear, data);
                if (front == NULL) {
                    front = rear;
                }
                break;
            case 2:
                data = dequeue(&front);
                if (data != -1) {
                    printf("Dequeued data: %d\n", data);
                }
                if (front == NULL) {
                    rear = NULL;
                }
                break;
            case 3:
                printQueue(front);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}