#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    Node* head;
} List;

void initList(List* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->head->next = list->head;
    list->head->prev = list->head;
}

void insertNode(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = list->head->next;
    newNode->prev = list->head;

    list->head->next->prev = newNode;
    list->head->next = newNode;
}

void printList(List* list) {
    Node* temp = list->head->next;
    while (temp != list->head) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

List* addLists(List* list1, List* list2) {
    List* result = (List*)malloc(sizeof(List));
    initList(result);

    Node* temp1 = list1->head->next;
    Node* temp2 = list2->head->next;
    int carry = 0;

    while (temp1 != list1->head && temp2 != list2->head) {
        int sum = temp1->data + temp2->data + carry;
        carry = sum / 10;
        insertNode(result, sum % 10);

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != list1->head) {
        int sum = temp1->data + carry;
        carry = sum / 10;
        insertNode(result, sum % 10);

        temp1 = temp1->next;
    }

    while (temp2 != list2->head) {
        int sum = temp2->data + carry;
        carry = sum / 10;
        insertNode(result, sum % 10);

        temp2 = temp2->next;
    }

    if (carry > 0) {
        insertNode(result, carry);
    }

    return result;
}

int main() {
    List* list1 = (List*)malloc(sizeof(List));
    initList(list1);

    List* list2 = (List*)malloc(sizeof(List));
    initList(list2);

    int n1, n2;
    printf("Enter the number of digits in the first number: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        int data;
        printf("Enter digit %d: ", i + 1);
        scanf("%d", &data);
        insertNode(list1, data);
    }

    printf("Enter the number of digits in the second number: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        int data;
        printf("Enter digit %d: ", i + 1);
        scanf("%d", &data);
        insertNode(list2, data);
    }

    printf("First number: ");
    printList(list1);

    printf("Second number: ");
    printList(list2);

    List* result = addLists(list1, list2);

    printf("Sum: ");
    printList(result);

    return 0;
}