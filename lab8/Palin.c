#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

int isFull(Deque* dq) {
    return dq->size == MAX_SIZE;
}

void insertRear(Deque* dq, char ch) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->rear = (dq->rear + 1) % MAX_SIZE;
    dq->data[dq->rear] = ch;
    dq->size++;
}

char deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return '\0'; 
    }
    char ch = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX_SIZE;
    dq->size--;
    return ch;
}

char deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return '\0'; 
    }
    char ch = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    dq->size--;
    return ch;
}

int isPalindrome(const char* str) {
    Deque dq;
    initDeque(&dq);

    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (isalnum(ch)) {
            insertRear(&dq, ch);
        }
    }

    while (!isEmpty(&dq)) {
        char frontChar = deleteFront(&dq);
        char rearChar = deleteRear(&dq);
        if (frontChar != rearChar) {
            return 0; // Not a palindrome
        }
    }

    return 1;
}

int main() {
    const char* testStr = "A man, a plan, a canal, Panama";

    if (isPalindrome(testStr)) {
        printf("\"%s\" is a palindrome\n", testStr);
    } else {
        printf("\"%s\" is not a palindrome\n", testStr);
    }

    return 0;
}
