#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void removeDuplicates(Node** head) {
    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    Node* head = NULL;
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original list: ");
    printList(head);

    removeDuplicates(&head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}