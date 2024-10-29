#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
typedef struct Node {
    int coef; // Coefficient
    int exp;  // Exponent
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in a circular linked list
void insert(Node** head, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Complete the circle
    }
}

// Function to display the polynomial
void display(Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        if (temp->coef != 0) {
            printf("%dx^%d ", temp->coef, temp->exp);
            if (temp->next != head) {
                printf("+ ");
            }
        }
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to subtract two polynomials
Node* subtract(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    do {
        int coef1 = 0, exp1 = 0;
        if (temp1->coef != 0) {
            coef1 = temp1->coef;
            exp1 = temp1->exp;
        }
        
        int coef2 = 0, exp2 = 0;
        if (temp2->coef != 0) {
            coef2 = temp2->coef;
            exp2 = temp2->exp;
        }

        if (exp1 == exp2) {
            insert(&result, coef1 - coef2, exp1);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (exp1 > exp2) {
            insert(&result, coef1, exp1);
            temp1 = temp1->next;
        } else {
            insert(&result, -coef2, exp2);
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 || temp2 != poly2);

    return result;
}

// Function to multiply two polynomials
Node* multiply(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;

    do {
        Node* temp2 = poly2;
        do {
            int newCoef = temp1->coef * temp2->coef;
            int newExp = temp1->exp + temp2->exp;
            insert(&result, newCoef, newExp);
            temp2 = temp2->next;
        } while (temp2 != poly2);
        temp1 = temp1->next;
    } while (temp1 != poly1);

    return result;
}

// Main function to drive the program
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int choice, coef, exp;

    do {
        printf("\nPolynomial Operations using Circular Linked List");
        printf("\n1. Input Polynomial 1");
        printf("\n2. Input Polynomial 2");
        printf("\n3. Subtract Polynomials");
        printf("\n4. Multiply Polynomials");
        printf("\n5. Display Polynomial 1");
        printf("\n6. Display Polynomial 2");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input terms for Polynomial 1 (coef exp) [end with -1 -1]:\n");
                while (1) {
                    scanf("%d %d", &coef, &exp);
                    if (coef == -1 && exp == -1) break;
                    insert(&poly1, coef, exp);
                }
                break;

            case 2:
                printf("Input terms for Polynomial 2 (coef exp) [end with -1 -1]:\n");
                while (1) {
                    scanf("%d %d", &coef, &exp);
                    if (coef == -1 && exp == -1) break;
                    insert(&poly2, coef, exp);
                }
                break;

            case 3: {
                Node* result = subtract(poly1, poly2);
                printf("Result of Polynomial 1 - Polynomial 2: ");
                display(result);
                break;
            }

            case 4: {
                Node* result = multiply(poly1, poly2);
                printf("Result of Polynomial 1 * Polynomial 2: ");
                display(result);
                break;
            }

            case 5:
                printf("Polynomial 1: ");
                display(poly1);
                break;

            case 6:
                printf("Polynomial 2: ");
                display(poly2);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
