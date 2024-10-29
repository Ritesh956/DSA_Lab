#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} CharStack;

void push(CharStack* s, char value);
char pop(CharStack* s);
char peek(CharStack* s);
int isEmpty(CharStack* s);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
void reverseString(char* str);
void infixToPrefix(char* infix, char* prefix);

int main() {
    char infix[MAX];
    char prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}

void push(CharStack* s, char value) {
    if (s->top < (MAX - 1)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack is full\n");
        exit(1);
    }
}

char pop(CharStack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

char peek(CharStack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int isEmpty(CharStack* s) {
    return s->top == -1;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    CharStack stack;
    stack.top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); 
        } else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0'; 

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char reversedInfix[MAX];
    char postfix[MAX];

    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    for (int i = 0; reversedInfix[i] != '\0'; i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    infixToPostfix(reversedInfix, postfix);

    reverseString(postfix);
    strcpy(prefix, postfix);
}
