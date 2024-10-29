#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

void push(Stack* s, int value);
int pop(Stack* s);
int isEmpty(Stack* s);
int peek(Stack* s);
int evaluatePrefix(char* expression);

int main() {
    char expression[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", expression);

    int result = evaluatePrefix(expression);
    printf("The result of the prefix expression is: %d\n", result);

    return 0;
}

void push(Stack* s, int value) {
    if (s->top < (MAX - 1)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack is full\n");
        exit(1);
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int evaluatePrefix(char* expression) {
    Stack s;
    s.top = -1;

    int i = 0;
    while (expression[i] != '\0') {
        i++;
    }

    for (--i; i >= 0; i--) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i >= 0 && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i--;
            }
            i++; 
            push(&s, num);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int op1 = pop(&s);
            int op2 = pop(&s);
            int result;

            switch (expression[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 != 0) {
                        result = op1 / op2;
                    } else {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    break;
            }
            push(&s, result);
        }
    }

    return pop(&s);
}
