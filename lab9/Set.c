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

int isPresent(Node* head, int data); // Function prototype

Node* findUnion(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* tail = NULL;
    Node* curr1 = head1;
    Node* curr2 = head2;

    while (curr1 != NULL) {
        if (!isPresent(result, curr1->data)) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = curr1->data;
            if (result == NULL) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        if (!isPresent(result, curr2->data)) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = curr2->data;
            if (result == NULL) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        curr2 = curr2->next;
    }

    return result;
}

Node* findIntersection(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* tail = NULL;
    Node* curr1 = head1;
    Node* curr2 = head2;

    while (curr1 != NULL) {
        if (isPresent(curr2, curr1->data) && !isPresent(result, curr1->data)) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = curr1->data;
            if (result == NULL) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        curr1 = curr1->next;
    }

    return result;
}

int isPresent(Node* head, int data) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == data) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2;

    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head1, data);
    }

    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head2, data);
    }

    printf("Original list 1: ");
    printList(head1);

    printf("Original list 2: ");
    printList(head2);

    Node* unionList = findUnion(head1, head2);
    Node* intersectionList = findIntersection(head1, head2);

    printf("Union list: ");
    printList(unionList);

    printf("Intersection list: ");
    printList(intersectionList);

    return 0;
}