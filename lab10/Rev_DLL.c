#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    Node* head;
} List;

void initList(List* list) {
    list->head = NULL;
}

void insertNode(List* list, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);

    if (list->head == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}

void printList(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(List* list) {
    Node* temp = list->head;
    Node* prev = NULL;
    Node* next = NULL;

    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }

    list->head = prev;
}

int main() {
    List* list = (List*)malloc(sizeof(List));
    initList(list);

    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char data[100];
        printf("Enter word %d: ", i + 1);
        scanf("%s", data);
        insertNode(list, data);
    }

    printf("Original list: ");
    printList(list);

    reverseList(list);

    printf("Reversed list: ");
    printList(list);

    return 0;
}