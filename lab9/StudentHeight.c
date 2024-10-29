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

void display(Node* head) {
    printf("Displaying the list: ");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* mergeLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node** current = &result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            *current = head1;
            head1 = head1->next;
        } else {
            *current = head2;
            head2 = head2->next;
        }
        current = &((*current)->next);
    }

    if (head1 != NULL) {
        *current = head1;
    } else {
        *current = head2;
    }

    return result;
}

int main() {
    int N1, N2;
    printf("Enter the number of students in Class A: ");
    scanf("%d", &N1);
    printf("Enter the heights of students in Class A (in ascending order): ");
    Node* headA = NULL;
    for (int i = 0; i < N1; i++) {
        int data;
        scanf("%d", &data);
        insert(&headA, data);
    }

    printf("Enter the number of students in Class B: ");
    scanf("%d", &N2);
    printf("Enter the heights of students in Class B (in ascending order): ");
    Node* headB = NULL;
    for (int i = 0; i < N2; i++) {
        int data;
        scanf("%d", &data);
        insert(&headB, data);
    }

    printf("Display Line of Class A: ");
    display(headA);

    printf("Display line of class B: ");
    display(headB);

    Node* jointHead = mergeLists(headA, headB);
    printf("Display the joint class file: ");
    display(jointHead);

    return 0;
}